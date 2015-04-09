
#define DEBUG


#include <cstdio>
#include<SDL/SDL.h>
#include<math.h>


#include"sdl_framerate.h"
#include"d_logging.h"

//#include"ui_loadanim.h"
//#include"ui_numberbar.h"
#include"ui_graph.h"

//#include<d_dft.h>

// Global SDL things
SDL_Surface *screen = NULL;
SDL_Event event;


float pi = 3.141593;



// DRAWING ENDS HERE

// Clean up SDL
void clean_up()
{
	d_log("Stopping SDL\n");
	SDL_Quit(); // Stop SDL

}


bool init()
{
    d_log("Initalizing SDL subsytem\n");

	// Initialize SDL subsystems
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        d_log( "\nUnable to init SDL: %s\n", SDL_GetError() );
        return false;
    }

	// Set up the screen
	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);

	if( !screen )
	{
		d_log("\nUnable to set video mode: %s\n", SDL_GetError());
		return false;
	}

	// Make sure SDL cleans up before exit
    //atexit(clean_up);
	return true;
}



float testFunct(float x)
{
	//printf("Data: %f\n", x);
	return sin(x*pi);
}

//int argc, char *argv[]	Required in windows. Doesn't do anything in Lunux.

int main(int argc, char *argv[]) {


	if ( init() == false )
	{
		d_log("Error initializing SDL");
		return 1;
	}




	// INITIALIZE OBJECTS HERE


    FrameRate fps_lock(15);

    Graph g(screen, testFunct);
    d_log("Main screen width: %i\n", screen->w);



	// END INITIALIZING OBJECTS





    // program main loop
    bool done = false;
    while (!done)
    {

        // message processing loop

        fps_lock.start();
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
					switch (event.key.keysym.sym)
						{
							case SDLK_ESCAPE: done=true; break;
							case SDLK_SPACE: done=true; break;

							case SDLK_RIGHT: g.camera.position_x += 10; break;
							case SDLK_LEFT: g.camera.position_x += -10; break;

							case SDLK_UP: g.camera.position_y += 10; break;
							case SDLK_DOWN: g.camera.position_y += -10; break;

							case SDLK_q: g.camera.scale_x++; g.camera.scale_y++; break;
							case SDLK_w: g.camera.scale_x--; g.camera.scale_y--; break;

							default: break;
						}

                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0,0, 0));


        g.draw();
        //g.dummyDraw();
		//draw background


        // DRAWING ENDS HERE
        SDL_Flip(screen);
        fps_lock.stop();

    } // end main loop

    // all is well
	clean_up();
	d_log("Sort exited cleanly\n");
    return 0;
}
