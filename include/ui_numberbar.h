



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
		int max_height;					// Height in pixels the bars can be
		int bar_width;					// The width of each bar
		int scroll;						// Amount of offset to the right in bars
		int offset;						// Amount to offsent in pixels
		int on_screen;					// Amount of bars on screen


		// Bar methods
		
		bool fitToScreen();				// Fit the bars to the screen


		public:
			void getInitBarWidth();			// Set initial bar width
			// Construction
			NumberBars(SDL_Surface* newScreen, int newTotalNumbers, int *newNumbers);

			// Bar stuff
			void scrollLeft();
			void scrollRight();
			void scrollLeft(int move);
			void scrollRight(int move);


			void zoomIn();
			void zoomOut();
			void zoomIn(int move);
			void zoomOut(int move);


			// SDL stuff
			void draw();		// Draws bars on SDL surface
			void dummy_draw();	// Output values to console


			// Selection
			bool selectPrimary(int newSelect);
			bool selectSecondary(int newSelect);

			bool incrementPrimary();
			bool decrementPrimary();

			bool incrementSecondary();
			bool decrementSecondary();

};





#endif
