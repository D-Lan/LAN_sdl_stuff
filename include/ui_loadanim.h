

#include<SDL/SDL.h>

#ifndef UI_LOADANIM_H
#define UI_LOADANIM_H


class LoadAnim
{
	private:

		// SDL screen
		SDL_Surface* screen; 		// Points to screen in main.cpp


		// Animation values
		int frame_total;			// Total frames in anim
		int frame;					// Current frame
		bool direction;				// Go left or right


		// Timing
		unsigned int time_total;	// Total ticks per frame
		unsigned int time;			// Frame start time


		// Colors
		Uint32 color_on;			// Color of on box
		Uint32 color_off;			// Color of off boxes


		// Box
		int total_boxes;			// Number of boxes (must be 5)
		SDL_Rect box;				// The box
		int size;					// Size of the boxes (square)


	public:
		LoadAnim(SDL_Surface* newScreen);
		void draw();
};




#endif
