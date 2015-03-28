

#include<SDL/SDL.h>

#include"ui_numberbar.h"

#include <lan_logging.h>

NumberBars::NumberBars(SDL_Surface* newScreen, int newTotalNumbers, int *newNumbers)
{

	// SDL screen
	screen = newScreen;


	// Colors
	color_default = SDL_MapRGB(screen->format, 220, 220, 220);
	color_alternate = SDL_MapRGB(screen->format, 210, 210, 210);
	color_primary = SDL_MapRGB(screen->format, 120, 120, 120);
	color_secondary = SDL_MapRGB(screen->format, 50, 50, 50);

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
	max_height = 300;
	bar_width = 2;
	scroll = 0;

	getInitBarWidth();
}


void NumberBars::dummy_draw()
{

	log("\n\n\n%i Numbers:\n", amount);

	for (int i=0; i<amount; i++)
	{
		printf("%i\n", numbers[i]);
	}
	log("\nMax: %i\nMin: %i\n", max, min);
	log("Primary: %i\n\n", select_primary);
	log("Secondary: %i\n\n\n\n", select_secondary);
}




bool NumberBars::selectPrimary(int newSelect)
{
	if (newSelect>=0 && newSelect<amount)
	{
		select_primary=newSelect;
		return true;
	} else {
		return false;
	}
}

bool NumberBars::selectSecondary(int newSelect)
{
	if (newSelect>=0 && newSelect<amount)
	{
		select_secondary=newSelect;
		return true;
	} else {
		return false;
	}
}




void NumberBars::getInitBarWidth()
{

	if (amount<=(screen->w)/4) 			// If less than 80
	{									// Fit bars to the screen
		bar_width = screen->w/amount;
		on_screen = amount;
	} else {
		bar_width = 4;
		on_screen = screen->w/4;
	}

	log("Bar width: %i\n", bar_width);
	log("On screen: %i\n", on_screen);
}



void NumberBars::draw()
{

	bar.w = bar_width;
	for (int i=0; i<on_screen; i++)
	{

		bar.h = (200*numbers[i])/max;
		bar.x = bar_width*i;
		bar.y = (screen->h) - (bar.h);

		if (!(i%2))
		{
			SDL_FillRect(screen, &bar, color_default);
		} else {
			SDL_FillRect(screen, &bar, color_alternate);
		}
	}


}
























