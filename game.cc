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
	//initilize other objects
	floor = TestObj(vertex(0.0, 0.0, -3.0, 1.0), vect3(5.0, 5.0, 1.0), true);		// (position, scale, isStatic)
	cube = TestObj(vertex(0.0, 0.0, 3.0, 1.0), vect3(1.0, 1.0, 1.0), false);

	physObjList.push_back(floor);
	physObjList.push_back(cube);
}

void Game::update() 
{
	//update gameobjects

	//***add in PhysicsEngine class to handle all PhysObj interactions
	physEng.updateObjects(physObjList);
}

void Game::render()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();   	//call this before setting the viewing position 

	gluLookAt( 20.0,  5.0,  5.0,  	// Eye
		    0.0,  0.0,  1.0,  	// Center
		    0.0,  0.0,  1.0); 	// Up

	glEnable(GL_DEPTH_TEST);

	glColor3f(0.0,1.0,0.0);

	/*
	// Draw testing base
	glPushMatrix();

	glColor3f (0.0,0.0,1.0);
	//glRotatef(0, 0, 0, 1);
	//glRotatef(0, 1, 0, 0);
	glTranslatef(0.0, 0.0, -3.5);

	gluCylinder(gluNewQuadric(), 
	    (GLdouble) 7,		//base radius
	    (GLdouble) 7,		//top radius
	    (GLdouble) 1,		//hieght
	    (GLint)    4,		//slices
	    (GLint)    20 );		//stacks

	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);

	glColor3f(1.0, 0.0, 0.0);
	glRotatef(45, 0, 0, 1);
	glBegin ( GL_POLYGON );
		glVertex3f ( 4.95, 4.95, 1 );
		glVertex3f ( -4.95, 4.95, 1 );	
		glVertex3f ( -4.95, -4.95, 1 );
		glVertex3f ( 4.95, -4.95, 1 );
	glEnd();

	glPopMatrix();
	*/

	//Physics test
	drawBox(&floor.faces[0], &floor.collCenter);
	drawBox(&cube.faces[0], &cube.collCenter);

	//Draw bounds
	drawBounds(&floor.bounds[0]);
	drawBounds(&cube.bounds[0]);

	glutSwapBuffers();
}

//Input replay functions
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

//phys testing functions
void Game::drawBox( struct box *face, vertex *position )
{
	int i, j;

	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);

	glPushMatrix();
	glTranslatef( position -> x, position -> y, position -> z);		//move box to right position

	for(j = 0; j < 6; j++)	//draw box
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
