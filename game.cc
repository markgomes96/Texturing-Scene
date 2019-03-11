#ifndef GAME_CC
#define GAME_CC

#include "includes.h"
#include "game.h"


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
	cube = TestObj(vertex(0.0, 0.0, 6.0, 1.0), vect3(1.0, 1.0, 1.0), false);
	golist.push_back(floor);
	golist.push_back(cube);
}

void Game::update() 
{
	// Update each phyisc object
	physEng.updateObjects(golist);

	glutLockFrameRate(frameRate);
}

void Game::HUD() 
{
	//displays HUD in a 2D square on the bottom left on the screen
	float testNumber = 3.0000;

	char *test = (char*) malloc(64*sizeof(char));
	sprintf(test, "TEST: %6.4f", testNumber);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 30.0);
	glVertex2f(30.0, 30.0);
	glVertex2f(30.0, 0.0);
	glEnd();
	glFlush();

	glColor3f(1.0, 0.0, 1.0);
	//drawString(10, 10, GLUT_BITMAP_HELVETICA_12, test);

	const char* c;
	glRasterPos2i(10, 10);
	for (c=test;*c!='\0';c++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}	

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	free(test);
}	

void Game::render()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity(); 

	gluLookAt( 20.0, //CAMERA_R*sin(CAMERA_THETA*M_PI/180.0)*cos(CAMERA_PHI*M_PI/180.0), 20.0 
			5.0, //CAMERA_R*sin(CAMERA_THETA*M_PI/180.0)*sin(CAMERA_PHI*M_PI/180.0), 5.0
			5.0, //CAMERA_R*cos(CAMERA_THETA*M_PI/180.0), 5.0 Eye
		        0.0,  0.0,  1.0,  	// Center
		        0.0,  0.0,  1.0); 	// Up

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
