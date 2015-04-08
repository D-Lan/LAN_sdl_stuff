
#define DEBUG


#include"ui_graph.h"
#include<SDL/SDL.h>
#include"lan_logging.h"

///*
void put_pixel(SDL_Surface* screen,int x,int y, int r, int g, int b)
{
  Uint32* p_screen = (Uint32*)screen->pixels;
  p_screen += y*screen->w+x;
  *p_screen = SDL_MapRGB(screen->format, r, g, b);
}
//*/

/*
void put_pixel(SDL_Surface* screen,int x,int y, int r, int g, int b)
{
}
*/

CoordCamera::CoordCamera()
{
    position_x = 0;
    position_y = 0;

    scale = 4.0;

}


float CoordCamera::getWorldCoord_x(int x)   //Get world coord from screen coord
{
	float c = screen->w / 2.0;	 // center offset
    float t = (float)x / (float)screen->w;

    t = t * scale;

    return ((t + c) - position_x);

}

/*
float center = (screen->h / 2);
	float t = scale / y;

	t = screen->h / t;


    t = t + center + position_y;
*/





float CoordCamera::getWorldCoord_y(int y)
{
	float c = screen->h / 2.0;	 // center offset
    float t = (float)y / (float)screen->h;
    t = t * scale;

    return t + (float)c + position_y;
}


int CoordCamera::getViewCoord_y(float y)
{
    float center = (screen->h / 2);
	float t = scale / y;

	t = screen->h / t;


    t = t + center + position_y;

    //log("Data Y: %f\n", y);
    //log("Data T: %f\n", t);

	return (int)t;
}


int CoordCamera::getViewCoord_x(float x)
{
    float center = ((float)screen->w / 2.0);
	float t = scale / x;

	t = screen->w / t;


    t = t + center + position_x;

	return (int)t;
}

/*
float c = screen->w / 2.0;	 // center offset
    float t = (float)x / (float)screen->w;

    t = t * scale;

    return ((t + c) - position_x);

*/

void CoordCamera::test()
{
    log("test!");
}


Graph::Graph(SDL_Surface* newScreen,  float (&newFunct)(float x) )
{
    screen = newScreen;
    camera.screen = newScreen;
    funct = newFunct;

    camera.position_x = 0;
	camera.position_y = 0;
}




void Graph::dummyDraw()
{
	/*
    //int x = camera.getViewCoord_x(0);
    int y = camera.getViewCoord_y(0);


    //log("X: %i Y: %i\n",x,y);

    for (int x=10; x<screen->w-10; x++)
    {
        put_pixel(screen, camera.getViewCoord_x(x), y, 255,255,255);
    }
	*/

}






float CoordCamera::screenToWorld_x(int x)
{
	float center = (screen->w / 2) - position_x;
	float t = (((x - center)) * 2) / screen->w;
	return t;
}


float CoordCamera::screenToWorld_y(int y)
{
	float center = (screen->h / 2) + position_y;
	float t = ((-y + center) * 2) / screen->h;
	return t;
}




int CoordCamera::worldToScreen_x(float x)
{
	float center = (screen->w / 2) - position_x;
	float t = ((x * screen->w) / 2) + center;
	return t;
}


int CoordCamera::worldToScreen_y(float y)
{
	float center = (screen->h / 2) + position_y;

	float t = ((-y * screen->h) / 2) + center;
	return t;
}






void Graph::draw()
{

	/*
	//TEST COORD CONVERSION
	camera.position_x = 100;
	camera.position_y = 100;

	int screen_point_x = 0;
	int screen_point_y = 0;

	float world_x = camera.screenToWorld_x(screen_point_x);
	float world_y = camera.screenToWorld_y(screen_point_y);


	int screen_x = camera.worldToScreen_x(world_x);
	int screen_y = camera.worldToScreen_y(world_y);
	*/

	
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

