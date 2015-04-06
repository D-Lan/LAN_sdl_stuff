
#define DEBUG


#include <cstdio>
#include<SDL/SDL.h>
#include<math.h>


#include"sdl_framerate.h"
//#include"lan_logging.h"

#include"ui_loadanim.h"
#include"ui_numberbar.h"
#include"ui_graph.h"



// Global SDL things
SDL_Surface *screen = NULL;
SDL_Event event;




// DRAWING ENDS HERE

// Clean up SDL
void clean_up()
{
	//log("Stopping SDL\n");
	SDL_Quit(); // Stop SDL

}


bool init()
{

    //log("Initalizing SDL subsytem\n");

	// Initialize SDL subsystems
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        //log( "\nUnable to init SDL: %s\n", SDL_GetError() );
        return false;
    }

	// Set up the screen
	screen = SDL_SetVideoMode(320, 240, 32, SDL_HWSURFACE);

	if( !screen )
	{
		//log("\nUnable to set video mode: %s\n", SDL_GetError());
		return false;
	}

	// Make sure SDL cleans up before exit
    //atexit(clean_up);
	return true;
}



float testFunct(float x)
{
	//printf("Data: %f\n", x);
	return sin(x)*4;
}

//int argc, char *argv[]	Required in windows. Doesn't do anything in Lunux.

int main(int argc, char *argv[]) {


	if ( init() == false )
	{
		//log("Error initializing SDL");
		return 1;
	}



	
	// INITIALIZE OBJECTS HERE


    FrameRate fps_lock(15);

    Graph g(screen, testFunct);
    //log("Main screen width: %i\n", screen->w);
    g.draw();


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
							case SDLK_ESCAPE: done=true;
							case SDLK_SPACE: done=true;
							default: break;
						}

                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE


		// draw background
        //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0,20, 255));

        // DRAWING ENDS HERE
        SDL_Flip(screen);
        fps_lock.stop();

    } // end main loop

    // all is well
	clean_up();
	//log("Sort exited cleanly\n");
    return 0;
}
