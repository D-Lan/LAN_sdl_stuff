
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
    //int x = camera.getViewCoord_x(0);
    int y = camera.getViewCoord_y(0);


    //log("X: %i Y: %i\n",x,y);

    for (int x=10; x<screen->w-10; x++)
    {
        put_pixel(screen, camera.getViewCoord_x(x), y, 255,255,255);
    }

}






void Graph::draw()
{

    for (int x=0; x<screen->w ; x++)		// Draw function
    {

		float y = funct( camera.getWorldCoord_x(x) );

		//log("Conv: %f\n", camera.getWorldCoord_x(x));

		//log("X: %i\nY: %i\n", x, y);
		if ( x<screen->w && x>0 && camera.getViewCoord_y(y)<screen->h && camera.getViewCoord_y(y)>0)
		{
            put_pixel(screen, x, camera.getViewCoord_y(y) , 255, 255, 255);
            //log("X: %i\nY: %f\n", x, y);
            //SDL_Delay(1);
            //SDL_Flip(screen);
        }
    }

    //put_pixel(screen, x, y, 0,255,0);

    int x = camera.getWorldCoord_x(0);
    //int x = 0;

    if ( x>0 && x<screen->w)		// Draw Vertical axis line (x=0)
    {
		for (int y = 0; y < screen->h; y++)
        {
            //log("X: %i\nY: %i\n",x,y);
            put_pixel(screen, x, y ,0,255,0);
        }
    }


	int y = camera.getWorldCoord_y(0);
    //int y = 0;

	if (y>0 && y<screen->h)			// Draw Horizontal axis line (y=0)
	{
		for (int x = 0; x<screen->w; x++)
		{
			//log("X: %i\nY: %i\n", x, y);
			put_pixel(screen, x, y, 255, 0, 0);
		}
	}

	//put_pixel(screen, camera.getWorldCoord_x(x), 200, 255, 255,255);

    //put_pixel(screen, 160, 120, 255,255,255);
    //put_pixel(screen, 160, 120, 255,255,255);


}

