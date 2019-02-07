#ifndef GAME_CC
#define GAME_CC

#include "includes.h"
#include "game.h"

Game::Game() 
{ }

void Game::init() 
{
	//initilize other objects
}

void Game::update() 
{
	//update gameobjects
}

void Game::render()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();   	//call this before setting the viewing position 

	gluLookAt( 20.0,   2.0, 2.5,  	// Eye
		0.0,   0.0, 0.0,  	// Center
		0.0,   0.0, 1.0); 	// Up

	glEnable(GL_DEPTH_TEST);

	glColor3f(0.0,1.0,0.0);

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

#endif
