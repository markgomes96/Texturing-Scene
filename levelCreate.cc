#ifndef LEVELS
#define LEVELS

#include "includes.h"
#include "game.h"
#include "globals.h"
#include "structs.h"

void buildHeritageHall(){

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();   	//call this before setting the viewing position 

	gluLookAt( 1.2,   -3.0, 0.5,  	// Eye
		1.2,   10.0, 1.0,  	// Center
		0.0,   0.0, 1.0); 	// Up

	glEnable(GL_DEPTH_TEST);


//floor//
	glPushMatrix();
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(1.0, 0.0, 0.0);
	glScalef(0.1, 0.1, 0.1);
	glBegin ( GL_POLYGON );
		glVertex3f ( 0, 0, -2 );
		glVertex3f ( 24, 0, -2 );	
		glVertex3f ( 24, 181, -2 );
		glVertex3f ( 0, 181, -2 );
	glEnd();

	glPopMatrix();
//////////////////////////////////////////////
//ceiling//
// the ceiling is set up as arches and flats

  //flats from front to back	
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 0, 14 );
		glVertex3f ( 24, 0, 14 );	
		glVertex3f ( 24, 20, 14 );
		glVertex3f ( 0, 20, 14 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 40, 14 );
		glVertex3f ( 24, 40, 14 );	
		glVertex3f ( 24, 60, 14 );
		glVertex3f ( 0, 60, 14 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 80, 14 );
		glVertex3f ( 24, 80, 14 );	
		glVertex3f ( 24, 100, 14 );
		glVertex3f ( 0, 100, 14 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 120, 14 );
		glVertex3f ( 24, 120, 14 );	
		glVertex3f ( 24, 140, 14 );
		glVertex3f ( 0, 140, 14 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 160, 14 );
		glVertex3f ( 24, 160, 14 );	
		glVertex3f ( 24, 180, 14 );
		glVertex3f ( 0, 180, 14 );
	  glEnd();
	glPopMatrix();


 //arches (multi rectangles) from front to back
    //first arch combo
      //veritcal flat short walls that connect to the angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 20, 14 );
		glVertex3f ( 0, 20, 16 );	
		glVertex3f ( 24, 20, 16 );
		glVertex3f ( 24, 20, 14 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 40, 14 );
		glVertex3f ( 0, 40, 16 );	
		glVertex3f ( 24, 40, 16 );
		glVertex3f ( 24, 40, 14 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 20, 16 );
		glVertex3f ( 24, 20, 16 );	
		glVertex3f ( 24, 25, 18 );
		glVertex3f ( 0, 25, 18 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 40, 16 );
		glVertex3f ( 24, 40, 16 );	
		glVertex3f ( 24, 35, 18 );
		glVertex3f ( 0, 35, 18 );
	  glEnd();
	glPopMatrix();
      //horizontal ceiling piece
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.8, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 25, 18 );
		glVertex3f ( 24, 25, 18 );	
		glVertex3f ( 24, 35, 18 );
		glVertex3f ( 0, 35, 18 );
	  glEnd();
	glPopMatrix();
    //second arch combo
      //veritcal flat short walls that connect to the angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 60, 14 );
		glVertex3f ( 0, 60, 16 );	
		glVertex3f ( 24, 60, 16 );
		glVertex3f ( 24, 60, 14 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 80, 14 );
		glVertex3f ( 0, 80, 16 );	
		glVertex3f ( 24, 80, 16 );
		glVertex3f ( 24, 80, 14 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 60, 16 );
		glVertex3f ( 24, 60, 16 );	
		glVertex3f ( 24, 65, 18 );
		glVertex3f ( 0, 65, 18 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 80, 16 );
		glVertex3f ( 24, 80, 16 );	
		glVertex3f ( 24, 75, 18 );
		glVertex3f ( 0, 75, 18 );
	  glEnd();
	glPopMatrix();
      //horizontal ceiling piece
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.8, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 65, 18 );
		glVertex3f ( 24, 65, 18 );	
		glVertex3f ( 24, 75, 18 );
		glVertex3f ( 0, 75, 18 );
	  glEnd();
	glPopMatrix();

    //third arch combo
      //veritcal flat short walls that connect to the angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 100, 14 );
		glVertex3f ( 0, 100, 16 );	
		glVertex3f ( 24, 100, 16 );
		glVertex3f ( 24, 100, 14 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 120, 14 );
		glVertex3f ( 0, 120, 16 );	
		glVertex3f ( 24, 120, 16 );
		glVertex3f ( 24, 120, 14 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 100, 16 );
		glVertex3f ( 24, 100, 16 );	
		glVertex3f ( 24, 105, 18 );
		glVertex3f ( 0, 105, 18 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 120, 16 );
		glVertex3f ( 24, 120, 16 );	
		glVertex3f ( 24, 115, 18 );
		glVertex3f ( 0, 115, 18 );
	  glEnd();
	glPopMatrix();
      //horizontal ceiling piece
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.8, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 105, 18 );
		glVertex3f ( 24, 105, 18 );	
		glVertex3f ( 24, 115, 18 );
		glVertex3f ( 0, 115, 18 );
	  glEnd();
	glPopMatrix();


    //forth arch combo
      //veritcal flat short walls that connect to the angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 140, 14 );
		glVertex3f ( 0, 140, 16 );	
		glVertex3f ( 24, 140, 16 );
		glVertex3f ( 24, 140, 14 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 160, 14 );
		glVertex3f ( 0, 160, 16 );	
		glVertex3f ( 24, 160, 16 );
		glVertex3f ( 24, 160, 14 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 140, 16 );
		glVertex3f ( 24, 140, 16 );	
		glVertex3f ( 24, 145, 18 );
		glVertex3f ( 0, 145, 18 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 160, 16 );
		glVertex3f ( 24, 160, 16 );	
		glVertex3f ( 24, 155, 18 );
		glVertex3f ( 0, 155, 18 );
	  glEnd();
	glPopMatrix();
      //horizontal ceiling piece
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.8, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 145, 18 );
		glVertex3f ( 24, 145, 18 );	
		glVertex3f ( 24, 155, 18 );
		glVertex3f ( 0, 155, 18 );
	  glEnd();
	glPopMatrix();

//////////////////////////////////////////////
//walls//
   //left wall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.0, 0.0, 1.0);
	glScalef(0.1, 0.1, 0.1); 
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, 0, -2 );
		glVertex3f ( 0, 0, 18 );	
		glVertex3f ( 0, 181, 18 );
		glVertex3f ( 0, 181, -2 );
	 glEnd();
	glPopMatrix();
    //rightwall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(1.0, 1.0, 1.0);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, 0, -2 );
		glVertex3f ( 24, 0, 18 );	
		glVertex3f ( 24, 181, 18 );
		glVertex3f ( 24, 181, -2 );
	 glEnd();
	glPopMatrix();
   //backwall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 1.0, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, 181, 14 );
		glVertex3f ( 0, 181, 14 );	
		glVertex3f ( 0, 181, -2 );
		glVertex3f ( 24, 181, -2 );
	 glEnd();
	glPopMatrix();
   //frontwall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, 0, 14 );
		glVertex3f ( 0, 0, 14 );	
		glVertex3f ( 0, 0, 9 );
		glVertex3f ( 24, 0, 9 );
	 glEnd();
	glPopMatrix();
       //frontwall leftindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, 0, -2 );
		glVertex3f ( 0, 0, 9 );	
		glVertex3f ( 2, 0, 9 );
		glVertex3f ( 2, 0, -2 );
	 glEnd();
	glPopMatrix();
       //frontwall rightindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, 0, -2 );
		glVertex3f ( 24, 0, 9 );	
		glVertex3f ( 22, 0, 9 );
		glVertex3f ( 22, 0, -2 );
	 glEnd();
	glPopMatrix();

	//flats for pillars
	 //left
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.5, 0, -2 );
		glVertex3f ( 7.5, 0, 9 );	
		glVertex3f ( 9, 0, 9 );
		glVertex3f ( 9, 0, -2 );
	 glEnd();
	glPopMatrix();
	 //right
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 16.5, 0, -2 );
		glVertex3f ( 16.5, 0, 9 );	
		glVertex3f ( 15, 0, 9 );
		glVertex3f ( 15, 0, -2 );
	 glEnd();
	glPopMatrix();

///////////////////////////////////////////
//objects inside the level//

//display cases "rough"

   //defining a cube
   struct box faces[6];
   defineBox(&faces[0]);

	//drawing 8 cases in rough location
//left side cubes front to back
	glPushMatrix();
	 glTranslatef(0.6, 3.5, 0.0);
	 glScalef(0.15, 0.4, 0.4);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(0.6, 7.0, 0.0);
	 glScalef(0.15, 0.4, 0.4);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(0.6, 10.5, 0.0);
	 glScalef(0.15, 0.4, 0.4);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(0.6, 14.0, 0.0);
	 glScalef(0.15, 0.4, 0.4);
	 drawBox(&faces[0]);
	glPopMatrix();
//right side cubes front to back
	glPushMatrix();
	 glTranslatef(1.8, 3.5, 0.0);
	 glScalef(0.15, 0.4, 0.4);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(1.8, 7.0, 0.0);
	 glScalef(0.15, 0.4, 0.4);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(1.8, 10.5, 0.0);
	 glScalef(0.15, 0.4, 0.4);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(1.8, 14.0, 0.0);
	 glScalef(0.15, 0.4, 0.4);
	 drawBox(&faces[0]);
	glPopMatrix();
	glutSwapBuffers();

}
#endif
