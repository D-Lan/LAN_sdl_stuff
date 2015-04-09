
#include"ui_graph.h"


void put_pixel(SDL_Surface* screen,int x,int y, int r, int g, int b)
{
    if (x<screen->w && x>=0 && y<screen->h && y>=0)
    {
        Uint32* p_screen = (Uint32*)screen->pixels;
        p_screen += y*screen->w+x;
        *p_screen = SDL_MapRGB(screen->format, r, g, b);
    }
}


void myLine(SDL_Surface* surface, int x, int y, int x2, int y2) {
	bool yLonger=false;
	int incrementVal, endVal;
	int shortLen=y2-y;
	int longLen=x2-x;
	if (abs(shortLen)>abs(longLen)) {
		int swap=shortLen;
		shortLen=longLen;
		longLen=swap;
		yLonger=true;
	}
	endVal=longLen;
	if (longLen<0) {
		incrementVal=-1;
		longLen=-longLen;
	} else incrementVal=1;
	int decInc;
	if (longLen==0) decInc=0;
	else decInc = (shortLen << 16) / longLen;
	int j=0;
	if (yLonger) {
		for (int i=0;i!=endVal;i+=incrementVal) {
			put_pixel(surface,x+(j >> 16),y+i, 255, 255, 255);
			j+=decInc;
		}
	} else {
		for (int i=0;i!=endVal;i+=incrementVal) {
			put_pixel(surface,x+i,y+(j >> 16), 255, 255, 255);
			j+=decInc;
		}
	}


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

    //myLine(screen, 100, 100, 150, 10);

    for (int x=0; x<screen->w ;x++)
    {



    }





	//Draw the function OLD
    for (int x=0; x<screen->w ;x++)
    {
		float y = funct( camera.screenToWorld_x(x) );

        put_pixel(screen, x, camera.worldToScreen_y(y) , 0, 100, 100);
    }







    // Draw Vertical axis line (x=0)
    int x = camera.worldToScreen_x(0);
    if ( x>0 && x<screen->w)
    {
		for (int y = 0; y < screen->h; y++)
        {
            put_pixel(screen, x, y ,0,255,0);
        }
    }

    // Draw Horizontal axis line (y=0)
	int y = camera.worldToScreen_y(0);
	if (y>0 && y<screen->h)
	{
		for (int x = 0; x<screen->w; x++)
		{
			put_pixel(screen, x, y, 255, 0, 0);
		}
	}
}


/*
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
*/
