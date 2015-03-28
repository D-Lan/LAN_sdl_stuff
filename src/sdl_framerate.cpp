

#include"SDL/SDL.h"
#include"sdl_framerate.h"


FrameRate::FrameRate()
{
    //Initialize the variables
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;

	frame=0;
	frameRate=1000/15; // 15 FPS default
}

FrameRate::FrameRate(int newRate)
{
    //Initialize the variables
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;

	frame=0;
	frameRate=1000/newRate;
}


void FrameRate::start()
{
    //Start the timer
    started = true;

    //Unpause the timer
    paused = false;

    //Get the current clock time
    startTicks = SDL_GetTicks();
}

void FrameRate::stop()
{
    //Stop the timer
    started = false;

    //Unpause the timer
    paused = false;

	frame++;
	if(get_ticks() < frameRate)
	{
		//Sleep the remaining frame time
		SDL_Delay( ( frameRate ) - get_ticks() );
	}


}

void FrameRate::pause()
{
    //If the timer is running and isn't already paused
    if( ( started == true ) && ( paused == false ) )
    {
        //Pause the timer
        paused = true;

        //Calculate the paused ticks
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void FrameRate::unpause()
{
    //If the timer is paused
    if( paused == true )
    {
        //Unpause the timer
        paused = false;

        //Reset the starting ticks
        startTicks = SDL_GetTicks() - pausedTicks;

        //Reset the paused ticks
        pausedTicks = 0;
    }
}

int FrameRate::get_ticks()
{
    //If the timer is running
    if( started == true )
    {
        //If the timer is paused
        if( paused == true )
        {
            //Return the number of ticks when the timer was paused
            return pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - startTicks;
        }
    }

    //If the timer isn't running
    return 0;
}

bool FrameRate::is_started()
{
    return started;
}

bool FrameRate::is_paused()
{
    return paused;
}

int FrameRate::get_frame()
{
	return frame;
}

int FrameRate::get_frameRate()
{
	return frameRate*1000;
}

void FrameRate::change_frameRate(int newRate)
{
	if ((newRate>0) && (newRate<200))
	{
		frameRate=1000/newRate;
	}
}






