


#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include<SDL/SDL.h>

class CoordCamera
{
    private:





        int position_z;     // Zoom

        float scale;

    public:


        int position_x;
		int position_y;

        CoordCamera();
        CoordCamera(SDL_Surface *newScreen);

        SDL_Surface *screen;

        void zoomIn();
        void zoomOut();

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

        float getWorldCoord_x(int x);
        float getWorldCoord_y(int y);

		int getViewCoord_y(float y);
        int getViewCoord_x(float x);

        void test();

};



class Graph
{

    public:

        SDL_Surface* screen;

        Graph(SDL_Surface* newScreen, float (&newFunct)(float x));

        CoordCamera camera;

        float (*funct)(float input);

        void draw();
        void dummyDraw();
};




#endif
