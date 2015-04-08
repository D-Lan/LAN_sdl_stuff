

#include<SDL/SDL.h>

#include"ui_numberbar.h"

#include <d_logging.h>



// Constructor //

NumberBars::NumberBars(SDL_Surface* newScreen, int newTotalNumbers, int *newNumbers)
{

	// SDL screen
	screen = newScreen;


	// Colors
	color_default = SDL_MapRGB(screen->format, 240, 240, 240);
	color_alternate = SDL_MapRGB(screen->format, 210, 210, 210);
	color_primary = SDL_MapRGB(screen->format, 255, 0, 0);
	color_secondary = SDL_MapRGB(screen->format, 0, 255, 0);


	// Numbers
	numbers = newNumbers;
	amount = newTotalNumbers;
	max = numbers[0];
	min = numbers[0];


	// Get max and min
	for (int i=1; i<amount; i++)
	{
		if (min > numbers[i]) { min = numbers[i]; }
		if (max < numbers[i]) { max = numbers[i]; }
	}


	// Selection
	select_primary = amount-1;
	select_secondary = 0;


	// Bar stuff
	max_height = screen->h-32;
	scroll = 0;
	offset = 0;



	updateZoomLevels();



}


void NumberBars::updateZoomLevels()
{
	amount_zoom_levels = 4;
	int testZoomLevel = 2;



	for (int i = 0; i < amount_zoom_levels; i++)
	{
		while (testZoomLevel < 100 && screen->w % testZoomLevel != 0)
		{
			testZoomLevel++;
		}
		zoom_level[i] = testZoomLevel;
		testZoomLevel++;
	}


	d_log("Zoom levels: %i, %i, %i, %i", zoom_level[0], zoom_level[1], zoom_level[2], zoom_level[3]);
}






// Drawing Methods //

/*Old draw
void NumberBars::draw()
{

	bar.w = bar_width;
	for (int i = 0; i < on_screen; i++)
	{

		bar.h = (200 * numbers[i+scroll]) / max;
		bar.x = (bar_width*i) + offset;
		bar.y = (screen->h) - (bar.h);

		if (select_primary == i+scroll)
		{
			SDL_FillRect(screen, &bar, color_primary);		// If current bar is selected as primary
		}
		else if (select_secondary == i + scroll)
		{
			SDL_FillRect(screen, &bar, color_secondary);	// If current bar is selected as secodary
		}
		else if (!((i+scroll) % 2))
		{
			SDL_FillRect(screen, &bar, color_default);		// If i is even (Makes an alternating color pattern)
		}
		else
		{
			SDL_FillRect(screen, &bar, color_alternate);	// If i is odd
		}
	}
}
*/







void NumberBars::dummy_draw()
{



	//d_log("\n\n\n%i Numbers:\n", amount);

	//for (int i=0; i<amount; i++)
	//{
	//	printf("%i\n", numbers[i]);
	//}

	d_log("\nDummy Draw...\n");
	d_log("Max: %i\nMin: %i\n", max, min);
	d_log("Primary: %i\n", select_primary);
	d_log("Secondary: %i\n\n", select_secondary);
}
