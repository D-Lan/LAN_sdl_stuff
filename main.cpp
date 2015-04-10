
#define DEBUG


#include <cstdio>
#include<SDL/SDL.h>
#include<math.h>


#include"sdl_framerate.h"
#include"d_logging.h"

//#include"ui_loadanim.h"
//#include"ui_numberbar.h"
#include"ui_graph.h"




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




int Loop_SDL()
{

	if (init() == false)
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
				case SDLK_ESCAPE: done = true; break;
				case SDLK_SPACE: done = true; break;

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
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));


		g.draw();
		//g.dummyDraw();
		//draw background


		// DRAWING ENDS HERE
		SDL_Flip(screen);
		fps_lock.stop();

	} // end main loop

	// all is well
	clean_up();

}


// Assumes end > start
// Assumes start & end are >0
void d_fft(float* x, float* i, int start, int end, int stride)
{
	int length = ((end - start) / stride) + 1;

	if ( length <= 1) return;

	
	// Divide and conquer
	d_fft(x, i, start, end - stride, stride * 2);	// Even
	d_fft(x, i, start + stride, end, stride * 2);	// Odd
	
	
	
	// Get odd: (k * 2 + 1)*stride + start
	// Get even: (k * 2)*stride + start



	// Combine
	printf("Sr: %i, St: %i\n", stride, start);
	for (int k = 0; k < length / 2; ++k)
	{
		


		// Poloar conversion std::polar( 1.0, -2 * PI * k/length) 

		//_Rho * exp(i * _Theta)
	}




	

}




/*


// Show values in use
for (int i = start; i < end; i += stride)
{
printf("%f, ", x[i]);
}
printf("\n");

// Show odd/even
printf("++O: %f\n", x[(k * 2 + 1)*stride + start]);	// Odd
printf("++E: %f\n", x[(k * 2)*stride + start]);		// Even


printf("Length: %i\n", length);
printf("\n");
*/




#include<d_fft.h>


int main(int argc, char *argv[])	//int argc, char *argv[]	Required in windows. Doesn't do anything in Lunux.
{
	d_log("Running FFT test...\n");
	

	const int Samples = 8;

	//float x[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0 };
	float x[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 };
	float i[8];


	//d_fft(x, i, 0, (Samples-1), 1);

	
	TESTfft();



	

	d_log("Done!\n");
    return 0;
}
