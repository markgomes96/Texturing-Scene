#ifndef GAME_CC
#define GAME_CC

#include "includes.h"
#include "game.h"
#include "prototypes.h"

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
	cout << "init" << endl;
	loadTextures();
}

void Game::update() 
{
	// Update each phyisc object
	physEng.updateObjects(golist);

	glutLockFrameRate(frameRate);
}

void Game::character() 
{
	


}

void Game::HUD() 
{
	//displays HUD in a 2D square on the bottom left on the screen
	float testNumber = 3.00;

	char *test = (char*) malloc(64*sizeof(char));
	sprintf(test, "STATS: %6.4f", testNumber);

	char *HUDtitle = (char*) malloc(64*sizeof(char));
	sprintf(HUDtitle, "HUD");
	
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
	glRasterPos2i(10, 25);
	for (c=HUDtitle;*c!='\0';c++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}

	glColor3f(1.0, 1.0, 1.0);
	glRecti(0.0, 0.0, 30.0, 30.0);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	//glPopMatrix();

	free(test);
}	

void Game::render()
{
/*
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

	glutSwapBuffers();*/

buildHeritageHall();
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
