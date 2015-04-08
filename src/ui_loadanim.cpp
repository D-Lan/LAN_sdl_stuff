
#include"ui_loadanim.h"


LoadAnim::LoadAnim(SDL_Surface* newScreen)
{

	// SDL screen
	screen = newScreen;


	// Animation values
	frame_total = 5; 		// 0 1 2 3 4 (must be 5)
	frame = 0;
	direction = true; 		// True +    False -


	// Timing
	time_total = 300;		// milliseconds
	time = 0;

	// Colors
	color_on = SDL_MapRGB(screen->format, 200, 200, 200);
	color_off = SDL_MapRGB(screen->format, 120, 120, 120);


	// Boxes
	size = 16;
	total_boxes = 5; // (must be 5)



	box.w = size;
	box.h = size;


}


void LoadAnim::draw()
{

	if (SDL_GetTicks() >= time+time_total)	// If more than max time has passed
	{
		//printf("hit switch");
		switch (frame)				//
		{
			case 0:					// If going left and reached 0
				direction=true;		// Start going right
				frame++;			// Go right
				break;

			case 4:					// If going right and reached frame total
				direction=false;	// Start going left
				frame--;			// Go left
				break;

			default:				// If 1 2 or 3
				switch (direction)	//
				{
					case true:		// If going right
						frame++;	// Go right
						break;

					case false:		// If going left
						frame--;	// Go left
						break;
				} // End switch direction
		} // End switch frame

		time=SDL_GetTicks(); // Update frame start time

	} // End if time

	for (int i=0; i<total_boxes; i++) // Draw the boxes
	{
		if (i==frame)	// If it's the highlight box
		{
			box.x = (24*i)+102;
			box.y = 110;
			box.w = size+4;
			box.h = size+4;
			SDL_FillRect(screen, &box, color_on);

		} else {		// If it's just a box
			box.x = (24*i)+104;
			box.y = 112;
			box.w = size;
			box.h = size;
			SDL_FillRect(screen, &box, color_off);
		}
	}
}
