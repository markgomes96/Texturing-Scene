#include "includes.h"

// Constant values for window size and place
const int WINDOW_POSITION_X = 500;
const int WINDOW_POSITION_Y = 5;
const int WINDOW_MAX_X = 1000;
const int WINDOW_MAX_Y = 1000;

Game g;		//global objects

void display( void ) 
{
	g.render();
}

void update( void ) 
{
	g.update();
	display();
}

// relay functions for input handling
void mouse( int button, int state, int x, int y ) { g.mouse(button, state, x, y); }
void keyboard( unsigned char key, int x, int y ) { g.keyboard(key, x, y); }
void SpecialInput(int key, int x, int y) {g.specialInput(key, x, y); }

int main(int argc, char** argv) 
{
	//set up opengl

	g.init(WINDOW_MAX_X, WINDOW_MAX_Y);
	
	glutDisplayFunc(display);
       	glutIdleFunc(update);
	glutMainLoop();
}
