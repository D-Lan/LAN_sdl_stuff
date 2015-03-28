



#ifndef UI_NUMBERBAR_H
#define UI_NUMBERBAR_H


#include<SDL/SDL.h>


class NumberBars
{

	private:

		// SDL stuff
		SDL_Surface* screen;			// Points screen in main.cpp


		// Colors
		Uint32 color_default;			// Color of generic bar
		Uint32 color_alternate;
		Uint32 color_primary;			// Color of primary selected bar
		Uint32 color_secondary;			// Color of primary selected bar

		// Numbers
		int *numbers;					// Point to int array
		int amount;						// Amount of numbers in array
		int max;						// Largest number
		int min;						// smallest number


		// Selection
		int select_primary;				// Primary selection
		int select_secondary;			// Secondary selection


		// Bar stuff
		SDL_Rect bar;					// Rect for drawing bars
		int max_height;					//
		int bar_width;					//
		//int zoom;						//
		//int left;						// Lowest array item shown
		//int right;					// Highest array item shown
		int scroll;						// Amount of offset to the right
		int on_screen;					// Amount of bars on screen


		// Bar methods
		void getInitBarWidth();			// Set initial bar width



		public:

			// Construction
			NumberBars(SDL_Surface* newScreen, int newTotalNumbers, int *newNumbers);

			// Bar stuff



			// SDL stuff
			void draw();
			void dummy_draw();	// Output values to console


			// Selection
			bool selectPrimary(int newSelect);
			bool selectSecondary(int newSelect);



};





#endif
