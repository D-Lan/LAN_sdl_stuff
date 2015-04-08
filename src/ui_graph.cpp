
#define DEBUG


#include"ui_graph.h"
#include<SDL/SDL.h>
#include"lan_logging.h"


void put_pixel(SDL_Surface* screen,int x,int y, int r, int g, int b)
{
  Uint32* p_screen = (Uint32*)screen->pixels;
  p_screen += y*screen->w+x;
  *p_screen = SDL_MapRGB(screen->format, r, g, b);
}


CoordCamera::CoordCamera()
{
    position_x = 0;
    position_y = 0;
	scale_x = 2;
	scale_y = 2;
}


Graph::Graph(SDL_Surface* newScreen,  float (&newFunct)(float x) )
{
    screen = newScreen;
    camera.screen = newScreen;
    funct = newFunct;

    camera.position_x = 0;
	camera.position_y = 0;
}



float CoordCamera::screenToWorld_x(int x)
{
	float center = (screen->w / 2) - position_x;
	float t = (((x - center)) * scale_x) / screen->w;
	return t;
}


float CoordCamera::screenToWorld_y(int y)
{
	float center = (screen->h / 2) + position_y;
	float t = ((-y + center) * scale_y) / screen->h;
	return t;
}




int CoordCamera::worldToScreen_x(float x)
{
	float center = (screen->w / 2) - position_x;
	float t = ((x * screen->w) / scale_x) + center;
	return t;
}


int CoordCamera::worldToScreen_y(float y)
{
	float center = (screen->h / 2) + position_y;

	float t = ((-y * screen->h) / scale_y) + center;
	return t;
}


void Graph::draw()
{

	

	
    for (int x=0; x<screen->w ; x++)		// Draw function
    {

		float y = funct( camera.screenToWorld_x(x) );

		if ( x<screen->w && x>0 && camera.worldToScreen_y(y)<screen->h && camera.worldToScreen_y(y)>0)
		{
            put_pixel(screen, x, camera.worldToScreen_y(y) , 255, 255, 255);
        }
    }
	


    int x = camera.worldToScreen_x(0);

    if ( x>0 && x<screen->w)		// Draw Vertical axis line (x=0)
    {
		for (int y = 0; y < screen->h; y++)
        {
            put_pixel(screen, x, y ,0,255,0);
        }
    }


	int y = camera.worldToScreen_y(0);

	if (y>0 && y<screen->h)			// Draw Horizontal axis line (y=0)
	{
		for (int x = 0; x<screen->w; x++)
		{
			put_pixel(screen, x, y, 255, 0, 0);
		}
	}
	


}




void Graph::test_Coord_conversion()
{
	camera.position_x = 100;
	camera.position_y = 100;

	int screen_point_x = 0;
	int screen_point_y = 0;

	float world_x = camera.screenToWorld_x(screen_point_x);
	float world_y = camera.screenToWorld_y(screen_point_y);


	int screen_x = camera.worldToScreen_x(world_x);
	int screen_y = camera.worldToScreen_y(world_y);
}