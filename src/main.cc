#include "includes.h"
#include "prototypes.h"
#include "game.h"

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

extern GLuint textureID[50];

void display( void )
{
#ifdef LEVEL

	buildHeritageHall();
    g.drawSceneObjects( ); 
/*	//lighting
	GLfloat lightPos1[] = {3.5, 5.0, 3.0, 1.0};
	GLfloat lightColor[] = {0.0, 1.0, 1.0, 1.0};
	GLfloat ambient[] = {0.2, 0.2, 0.2, 0.2};
	GLfloat spec[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat diff[] = {0.5, 0.5, 0.5, 1.0};
	GLfloat on[] = {1.0, 1.0, 1.0, 1.0};

	//to mark light position
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(1.0, 1.0, 1.0);
	glColor3f(1.0, 1.0, 0.0);
	glutWireSphere(5.5, 10.0, 10.0);
	glPopMatrix();
	glEnable(GL_LIGHTING);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glColorMaterial(GL_FRONT, GL_SPECULAR);
	glEnable(GL_COLOR_MATERIAL);

	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
	glMaterialf(GL_FRONT, GL_SHININESS, 10.0);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, on);
	glLightfv(GL_LIGHT0, GL_SPECULAR, on);	
	
	buildHeritageHall();
*/
	glDisable(GL_LIGHTING);
	g.HUD();
	glEnable(GL_LIGHTING);	

	buildDisplay();
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
	glutSetCursor(GLUT_CURSOR_NONE);

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);		//render next frame
	glutIdleFunc(update);			//update game

	glutMainLoop();
}
