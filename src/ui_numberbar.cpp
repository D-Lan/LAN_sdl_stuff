

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
	offset = 0;
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



// Selection methods

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



bool NumberBars::incrementPrimary()
{
	if (select_primary < amount-1)
	{
		select_primary++;
		return true;
	} else
	{
		return false;
	}
}



bool NumberBars::decrementPrimary()
{
	if (select_primary > 0)
	{
		select_primary--;
		return true;
	}
	else
	{
		return false;
	}
}



bool NumberBars::incrementSecondary()
{
	if (select_secondary < amount - 1)
	{
		select_secondary++;
		return true;
	}
	else
	{
		return false;
	}
}



bool NumberBars::decrementSecondary()
{
	if (select_secondary > 0)
	{
		select_secondary--;
		return true;
	}
	else
	{
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



// Bar methods

bool NumberBars::fitToScreen()
{
	if (amount <= screen->w / 4)						// Minimum of 4 pixels wide
	{
		log("Fitting bars to screen\n");

		bar_width = screen->w / amount;					// Width of bar in pixels
		on_screen = amount;								// All bars are displayed on screen
		offset = (screen->w - bar_width*amount) / 2;	// Center the bars on screen
	}
	else
	{
		log("Could not fit bars to screen\n");
		return false;
	}
}







void NumberBars::getInitBarWidth()
{

	if (!fitToScreen())					// Attempt to fit the bars to the screen
	{
		bar_width = 4;					// Otherwise make them default
		on_screen = screen->w / 4;
		offset = 0;
	}

	log("Bar width: %i\n", bar_width);
	log("On screen: %i\n", on_screen);
	log("Bar offset: %i\n", offset);

}



void NumberBars::draw()
{

	bar.w = bar_width;
	for (int i=0; i<on_screen; i++)
	{

		bar.h = (200*numbers[i])/max;
		bar.x = (bar_width*i)+offset;
		bar.y = (screen->h) - (bar.h);

		if (!(i%2))
		{
			SDL_FillRect(screen, &bar, color_default);
		} else {
			SDL_FillRect(screen, &bar, color_alternate);
		}
	}
}
