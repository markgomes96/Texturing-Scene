#include "includes.h"
#include "game.h"

// Constant values for window size and place
const int WINDOW_POSITION_X = 500;
const int WINDOW_POSITION_Y = 5;
const int WINDOW_MAX_X = 800;
const int WINDOW_MAX_Y = 800;

Game g;		//global objects

void display( void ) 
{
	g.render();
}

void update( void ) 
{
	g.update();
	//display();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
	glMatrixMode(GL_MODELVIEW);
}

// OpenGl initilization
void init(int window_width, int window_height, int window_position_x, int window_position_y) 
{
	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize (window_width, window_height); 
	glutInitWindowPosition (window_position_x, window_position_y);
	glutCreateWindow ("Bear Force One");

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glLoadIdentity();
}

// Relay functions for input handling
void mouse( int button, int state, int x, int y ) { g.mouse(button, state, x, y); }
void keyboard( unsigned char key, int x, int y ) { g.keyboard(key, x, y); }
void specialInput(int key, int x, int y) {g.specialInput(key, x, y); }

int main(int argc, char** argv) 
{
	//set up opengl
	glutInit(&argc, argv);
	init(WINDOW_MAX_X, WINDOW_MAX_Y, WINDOW_POSITION_X, WINDOW_POSITION_Y);

	glutMouseFunc(mouse);		//input functions
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialInput);

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);		//render next frame
	glutIdleFunc(update);			//update game
	
	glutMainLoop();
}