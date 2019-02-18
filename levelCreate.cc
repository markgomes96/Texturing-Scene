#ifndef LEVELS
#define LEVELS

#include "includes.h"
#include "game.h"
#include "globals.h"
void buildHeritageHall(){

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();   	//call this before setting the viewing position 

	gluLookAt( 20.0,   2.0, 2.5,  	// Eye
		0.0,   0.0, 0.0,  	// Center
		0.0,   0.0, 1.0); 	// Up

	glEnable(GL_DEPTH_TEST);

	glPushMatrix();

	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);

	glColor3f(1.0, 0.0, 0.0);
	//glRotatef(45, 0, 0, 1);
	glBegin ( GL_POLYGON );
		glVertex3f ( 5, 5, -2 );
		glVertex3f ( -5, 5, -2 );	
		glVertex3f ( -5, -5, -2 );
		glVertex3f ( 5, -5, -2 );
	glEnd();

	glPopMatrix();

	glutSwapBuffers();

}
#endif
