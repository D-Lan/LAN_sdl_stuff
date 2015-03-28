

#include<SDL/SDL.h>

#ifndef SORT_FRAMERATE_H
#define SORT_FRAMERATE_H


class FrameRate
{
	private:
		int startTicks;
		int pausedTicks;
		
		bool paused;
		bool started;
		
		int frame;
		int frameRate;
		
	public:
	
		FrameRate();
		FrameRate(int newRate);
	
		void start();
		void stop();
		void pause();
		void unpause();
	
		int get_ticks();
	
		bool is_started();
		bool is_paused();
		
		int get_frame();
		int get_frameRate();
		void change_frameRate(int newRate);
		
};


#endif