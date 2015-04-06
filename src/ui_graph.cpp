
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

    scale = 2.0;

}




float CoordCamera::getWorldCoord_x(int x)   //Get world coord from screen coord
{
	//float c = screen->w / 2;	 // center offset

	float t = (float)x / (float)screen->w;
	return t; //- c;

}









float CoordCamera::getWorldCoord_y(int y)
{
	float t = 0;
	t = (screen->h / 2) + position_y;
	return t;
}








int CoordCamera::getViewCoord_y(float y)
{

	float t = 10.0;
	t = (screen->h / 2) + position_y - y;
	
	//log("Data: %f\n", t);

	return (int)t;




}




void CoordCamera::test()
{
    log("test!");
}







Graph::Graph(SDL_Surface* newScreen,  float (&newFunct)(float x) )
{
    screen = newScreen;
    camera.screen = newScreen;
    funct = newFunct;

    //camera.position_x = 200;
	//camera.position_y = 200;
}








void Graph::draw()
{
    //log("Width: %i\n", screen->w);




    for (int x=0; x<screen->w ; ++x)		// Draw function
    {

		int y = funct( camera.getWorldCoord_x(x) );

		//log("Conv: %f\n", camera.getWorldCoord_x(x));

		//log("X: %i\nY: %i\n", x, y);
        put_pixel(screen, x, camera.getViewCoord_y(y) , 255, 255, 255);



    }

    //put_pixel(screen, x, y, 0,255,0);


    
    int x = camera.getWorldCoord_x(0);
	
    if ( x>0 && x<screen->w)		// Draw Vertical axis line (x=0)
    {
		for (int y = 0; y < screen->h; ++y)
        {
            //log("X: %i\nY: %i\n",x,y);
            put_pixel(screen, x, y ,0,255,0);
        }
    }


	int y = camera.getWorldCoord_y(0);

	if (y>0 && y<screen->h)			// Draw Horizontal axis line (y=0)
	{
		for (int x = 0; x<screen->w; ++x)
		{
			//log("X: %i\nY: %i\n", x, y);
			put_pixel(screen, x, y, 255, 0, 0);
		}
	}

    

}

