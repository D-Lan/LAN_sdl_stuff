


#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include<SDL/SDL.h>

class CoordCamera
{
    private:

		

		

    public:

		SDL_Surface *screen;


        int position_x;
		int position_y;
		float scale_x;
		float scale_y;

        CoordCamera();
        
        void zoomIn();
        void zoomOut();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();


		float screenToWorld_x(int x);
		float screenToWorld_y(int y);


		int  worldToScreen_x(float x);
		int  worldToScreen_y(float y);




};



class Graph
{

    public:

        SDL_Surface* screen;

        Graph(SDL_Surface* newScreen, float (&newFunct)(float x));

        CoordCamera camera;

        float (*funct)(float input);

        void draw();


		void test_Coord_conversion();
};




#endif
