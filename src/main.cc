#include "includes.h"
#include "prototypes.h"
#include "game.h"
#include "menu.h"

// Constant values for window size and place
const int WINDOW_POSITION_X = 0;
const int WINDOW_POSITION_Y = 0;
int WINDOW_MAX_X = 800;
int WINDOW_MAX_Y = 800;

//global objects
extern Game g;
extern void buildHeritageHall(void);
extern void buildCameraScene(void);
extern void buildDisplay(void);
extern double centerX, centerY, centerZ;
extern double CAMERA_R, CAMERA_THETA, CAMERA_PHI;
extern double x_rotat, y_rotat;
enum State activeState;
extern GLuint textureID[50];

void display( void )
{
#ifdef LEVEL
	switch(activeState)
        {
                case gameState:
			buildHeritageHall();
    			g.drawSceneObjects( ); 
			g.HUD();
			buildDisplay();
			break;
		  case startState:
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        startDisplay();
                        break;

                case instructState:
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        instructDisplay();
                        break;

                case pauseState:
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        pauseDisplay();
                        break;

                case overState:
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        overDisplay();
                        break;
        }

		glutSwapBuffers();
#else
	g.HUD();
	g.render();
#endif

}

void update( void )
{
#ifdef LEVEL
	g.update();
#else
	g.update();
#endif
    glutPostRedisplay();
//	display();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 70.0);
	glMatrixMode(GL_MODELVIEW);
}

// OpenGl initilization
void init(int window_width, int window_height, int window_position_x, int window_position_y)
{
	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize (window_width, window_height);
	glutInitWindowPosition (window_position_x, window_position_y);
	glutCreateWindow ("Bear Force One");

	//Enable gamemode if possible
/*	glutGameModeString("1920x1080:32");
	if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)){
		glutEnterGameMode();
	}else{
		printf("ERROR! --> Game mode not possible\n");
		exit(1);
	}*/
	activeState = startState;
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glLoadIdentity();
}

// Relay functions for input handling
void mouse( int button, int state, int x, int y ) { g.mouse(button, state, x, y); }
void keyboard( unsigned char key, int x, int y ) { g.keyboard(key, x, y); }
void passiveMouseMovement(int x, int y) {g.passiveMouseMovement(x, y);}
void mouseMovement(int x, int y) {g.mouseMovement(x, y);}
void keyup( unsigned char key, int x, int y ) { g.keyup(key, x, y); }
void specialInput(int key, int x, int y) {g.specialInput(key, x, y); }

int main(int argc, char** argv)
{
	//set up opengl
	glutInit(&argc, argv);

	//Max display at 1920x1080
	WINDOW_MAX_X = glutGet(GLUT_SCREEN_WIDTH);
	WINDOW_MAX_Y = glutGet(GLUT_SCREEN_HEIGHT);
	if(WINDOW_MAX_X > 1920 || WINDOW_POSITION_Y > 1080){
		WINDOW_MAX_X = 1920;
		WINDOW_MAX_Y = 1080;
	}

	init(WINDOW_MAX_X, WINDOW_MAX_Y, WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glewInit();
	g.init();

	glutMouseFunc(mouse);		//input functions
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyup);
	glutSpecialFunc(specialInput);
    // This needs to be changed to reflect that vertices is in the ../objs directory
	g.loadVerticesFileData( (char *) "vertices" ); //file name is "vertices"
	//initalize mouse movement function
	glutPassiveMotionFunc(passiveMouseMovement);
	glutMotionFunc(mouseMovement);
	//make cursor invisible
	if(activeState == gameState){
	glutSetCursor(GLUT_CURSOR_NONE);
}
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);		//render next frame
	glutIdleFunc(update);			//update game

	glutMainLoop();
}
