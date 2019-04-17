#ifndef GAME_CC
#define GAME_CC

#include "includes.h"
#include "game.h"

extern void buildDisplay();
extern void buildCameraScene();
extern void buildHeritageHall();
/*
* Handles all functions of the game
*/

Game::Game()
{ }

void Game::init()
{
	frameRate = 60.0;
	physEng = PhysicsEngine(frameRate);

	// ***Test objects for phyiscs***
	floor = TestObj(vertex(0.0, 0.0, -3.0, 1.0), vect3(5.0, 5.0, 1.0), true);		// (position, scale, isStatic)

	/* senerio one - collision in z-axis
	cube = TestObj(vertex(1.0, 2.0, 5.0, 1.0), vect3(1.0, 1.0, 1.0), false);
	cube2 = TestObj(vertex(0.0, 1.0, 10.0, 1.0), vect3(1.0, 1.0, 1.0), false);
	*/

	// senerio two - collision in x-axis
	cube = TestObj(vertex(4.0, 0.0, 7.0, 1.0), vect3(1.0, 1.0, 1.0), false);
	cube2 = TestObj(vertex(-4.0, 0.0, 7.0, 1.0), vect3(0.5, 0.5, 0.5), false);
	cube.velocity = vect3(-3.0, 0.0, 0.0);
	cube2.velocity = vect3(3.0, 0.0, 0.0);

	golist.push_back(floor);
	golist.push_back(cube);
	golist.push_back(cube2);
}

void Game::update()
{
	// Update each phyisc object
	physEng.updateObjects(golist);

	glutLockFrameRate(frameRate);
}

void Game::character()
{
<<<<<<< HEAD
=======

>>>>>>> master


<<<<<<< HEAD
=======
}
void Game::minimap(){
	buildCameraScene();
	buildHeritageHall();
}
>>>>>>> master
void Game::HUD()
{
	//displays HUD in a 2D square on the bottom left on the screen
//	buildHeritageHall();
	float testNumber = 3.00;

	char *test = (char*) malloc(64*sizeof(char));
	sprintf(test, "STATS: %6.4f", testNumber);

<<<<<<< HEAD
	char *HUDtitle = (char*) malloc(64*sizeof(char));
	sprintf(HUDtitle, "HUD");
=======
	/*char *HUDtitle = (char*) malloc(64*sizeof(char));
	sprintf(HUDtitle, "HUD");*/
>>>>>>> master

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_CULL_FACE);

	glClear(GL_DEPTH_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0); //black

	//test stats
	const char* c;
	glRasterPos2i(5, 20);
	for (c=test;*c!='\0';c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}

	//HUD title
	/*glRasterPos2i(10, 25);
	for (c=HUDtitle;*c!='\0';c++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}*/

	glColor3f(1.0, 1.0, 1.0);
	glRecti(0.0, 0.0, 30.0, 30.0);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	//glPopMatrix();

	//buildCameraScene();
	free(test);
}

void Game::render()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();

<<<<<<< HEAD
	gluLookAt( 0.0 /*20.0*/, //CAMERA_R*sin(CAMERA_THETA*M_PI/180.0)*cos(CAMERA_PHI*M_PI/180.0), 20.0
			   20.0 /*0.0*/ /*5.0*/, //CAMERA_R*sin(CAMERA_THETA*M_PI/180.0)*sin(CAMERA_PHI*M_PI/180.0), 5.0
			   0.0 /*0.0*/ /*5.0*/, //CAMERA_R*cos(CAMERA_THETA*M_PI/180.0), 5.0 Eye
		       0.0,  0.0,  1.0,  	// Center
		       0.0,  0.0,  1.0); 	// Up
=======
	gluLookAt( 20.0, //CAMERA_R*sin(CAMERA_THETA*M_PI/180.0)*cos(CAMERA_PHI*M_PI/180.0), 20.0
			5.0, //CAMERA_R*sin(CAMERA_THETA*M_PI/180.0)*sin(CAMERA_PHI*M_PI/180.0), 5.0
			5.0, //CAMERA_R*cos(CAMERA_THETA*M_PI/180.0), 5.0 Eye
		        0.0,  0.0,  1.0,  	// Center
		        0.0,  0.0,  1.0); 	// Up
>>>>>>> master

	glEnable(GL_DEPTH_TEST);

	glColor3f(0.0,1.0,0.0);

	// Physics test
	for(int i = 0; i < golist.size(); i++)
	{
		drawBox(&golist[i].faces[0], &golist[i].collCenter);	// draw faces
		drawBounds(&golist[i].bounds[0]);						// draw box collider
	}

	glutSwapBuffers();
}

// Input replay functions
void Game::mouse( int button, int state, int x, int y )
{
	input.mouse(button, state, x, y);
}
void Game::keyboard( unsigned char key, int x, int y )
{
	input.keyboard(key, x, y);
}
void Game::specialInput(int key, int x, int y)
{
	input.specialInput(key, x, y);
}

// Physics / Framerate
void Game::glutLockFrameRate(float desiredFrameRate)
{
	int millisecondsToWait = (int)((1.0 / desiredFrameRate) * 1000);

	int startTime = glutGet(GLUT_ELAPSED_TIME);

	do{/*wait*/}
	while((glutGet(GLUT_ELAPSED_TIME)-startTime) < millisecondsToWait);
}

// ***Phys testing functions***
void Game::drawBox( struct box *face, vertex *position )
{
	int i, j;

	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);

	glPushMatrix();
	glTranslatef( position -> x, position -> y, position -> z);		// move box to right position

	for(j = 0; j < 6; j++)		// draw box
	{

	glColor3f(face[j].color.red,
		  face[j].color.green,
		  face[j].color.blue);

	glBegin( GL_POLYGON );
		for (i = 0; i < 4; i++)
		{
			glVertex3f(face[j].point[i].x,
				face[j].point[i].y,
				face[j].point[i].z);
		}
	glEnd();
	}

	glPopMatrix();
}

void Game::drawBounds( vertex *bounds )
{
	glPushMatrix();

	glLineWidth(5.0);
	glColor3f(1.0, 0.0, 0.0);
	for(int i = 0; i < 8; i++)
	{
		glBegin( GL_LINES );
			if(i == 7)
			{
				glVertex3f( bounds[i].x, bounds[i].y, bounds[i].z );
				glVertex3f( bounds[0].x, bounds[0].y, bounds[0].z );
			}
			else
			{
				glVertex3f( bounds[i].x, bounds[i].y, bounds[i].z );
				glVertex3f( bounds[i+1].x, bounds[i+1].y, bounds[i+1].z );
			}
		glEnd();
	}
	glLineWidth(1.0);

	glPopMatrix();
}

#endif
