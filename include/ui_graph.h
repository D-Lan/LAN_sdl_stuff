
#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include<SDL/SDL.h>


class CoordCamera
{
    public:

		SDL_Surface *screen;

        int position_x;
		int position_y;
		float scale_x;
		float scale_y;

        CoordCamera();

		float screenToWorld_x(int x);
		float screenToWorld_y(int y);
		int  worldToScreen_x(float x);
		int  worldToScreen_y(float y);
};



class Graph
{
    public:

        SDL_Surface* screen;
        CoordCamera camera;
        float (*funct)(float input);
        void draw();
		//void test_Coord_conversion();

		Graph(SDL_Surface* newScreen, float (&newFunct)(float x));
};


#endif
