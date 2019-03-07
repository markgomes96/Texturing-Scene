#ifndef LEVELS
#define LEVELS

#include "includes.h"
#include "game.h"
#include "globals.h"
#include "structs.h"

void buildHeritageHall(){

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();   	//call this before setting the viewing position 

	gluLookAt( 1.2,   -0.4, 0.2,  	// Eye
		1.2,   3.6, 0.7,  	// Center
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

	glPushMatrix();
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(1.0, 0.0, 1.0);
	glScalef(0.1, 0.1, 0.1);
	glBegin ( GL_POLYGON );
		glVertex3f ( 0, 0, -2 );
		glVertex3f ( 24, 0, -2 );	
		glVertex3f ( 24, -24, -2 );
		glVertex3f ( 0, -24, -2 );
	glEnd();
	glPopMatrix();
//////////////////////////////////////////////
//ceiling//

//ceiling above front area
	glPushMatrix();
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(1.0, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	glBegin ( GL_POLYGON );
		glVertex3f ( 0, 0, 18 );
		glVertex3f ( 24, 0, 18 );	
		glVertex3f ( 24, -24, 18 );
		glVertex3f ( 0, -24, 18 );
	glEnd();
	glPopMatrix();



// the ceiling of heritage hall is set up as arches and flats

  //flats from front to back	
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 0, 18 );
		glVertex3f ( 24, 0, 18 );	
		glVertex3f ( 24, 16.45, 18 );
		glVertex3f ( 0, 16.45, 18 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 32.9, 18 );
		glVertex3f ( 24, 32.9, 18 );	
		glVertex3f ( 24, 49.35, 18 );
		glVertex3f ( 0, 49.35, 18 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 65.8, 18 );
		glVertex3f ( 24, 65.8, 18 );	
		glVertex3f ( 24, 82.25, 18 );
		glVertex3f ( 0, 82.25, 18 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 98.7, 18 );
		glVertex3f ( 24, 98.7, 18 );	
		glVertex3f ( 24, 115.15, 18 );
		glVertex3f ( 0, 115.15, 18 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 131.6, 18 );
		glVertex3f ( 24, 131.6, 18 );	
		glVertex3f ( 24, 148.05, 18 );
		glVertex3f ( 0, 148.05, 18 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 164.5, 18 );
		glVertex3f ( 24, 164.5, 18 );	
		glVertex3f ( 24, 180.95, 18 );
		glVertex3f ( 0, 180.95, 18 );
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
		glVertex3f ( 0, 16.45, 18 );
		glVertex3f ( 0, 16.45, 21 );	
		glVertex3f ( 24, 16.45, 21 );
		glVertex3f ( 24, 16.45, 18 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 32.9, 18 );
		glVertex3f ( 0, 32.9, 21 );	
		glVertex3f ( 24, 32.9, 21 );
		glVertex3f ( 24, 32.9, 18 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.9, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 16.45, 21 );
		glVertex3f ( 24, 16.45, 21 );	
		glVertex3f ( 24, 24.675, 25 );
		glVertex3f ( 0, 24.675, 25 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 32.9, 21 );
		glVertex3f ( 24, 32.9, 21 );	
		glVertex3f ( 24, 24.675, 25 );
		glVertex3f ( 0, 24.675, 25 );
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
		glVertex3f ( 0, 49.35, 18 );
		glVertex3f ( 0, 49.35, 21 );	
		glVertex3f ( 24, 49.35, 21 );
		glVertex3f ( 24, 49.35, 18 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 65.8, 18 );
		glVertex3f ( 0, 65.8, 21 );	
		glVertex3f ( 24, 65.8, 21 );
		glVertex3f ( 24, 65.8, 18 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.9, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 49.35, 21 );
		glVertex3f ( 24, 49.35, 21 );	
		glVertex3f ( 24, 57.575, 25 );
		glVertex3f ( 0, 57.575, 25 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0, 65.8, 21 );
		glVertex3f ( 24, 65.8, 21 );	
		glVertex3f ( 24, 57.575, 25 );
		glVertex3f ( 0, 57.575, 25 );
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
		glVertex3f ( 0,  82.25, 18 );
		glVertex3f ( 0,  82.25, 21 );	
		glVertex3f ( 24, 82.25, 21 );
		glVertex3f ( 24, 82.25, 18 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,  98.7, 18 );
		glVertex3f ( 0,  98.7, 21 );	
		glVertex3f ( 24, 98.7, 21 );
		glVertex3f ( 24, 98.7, 18 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.9, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,  82.25, 21 );
		glVertex3f ( 24, 82.25, 21 );	
		glVertex3f ( 24, 90.475, 25 );
		glVertex3f ( 0,  90.475, 25 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,  98.7, 21 );
		glVertex3f ( 24, 98.7, 21 );	
		glVertex3f ( 24, 90.475, 25 );
		glVertex3f ( 0,  90.475, 25 );
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
		glVertex3f ( 0,  115.15, 18 );
		glVertex3f ( 0,  115.15, 21 );	
		glVertex3f ( 24, 115.15, 21 );
		glVertex3f ( 24, 115.15, 18 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,  131.6, 18 );
		glVertex3f ( 0,  131.6, 21 );	
		glVertex3f ( 24, 131.6, 21 );
		glVertex3f ( 24, 131.6, 18 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.9, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,  115.15, 21 );
		glVertex3f ( 24, 115.15, 21 );	
		glVertex3f ( 24, 123.375, 25 );
		glVertex3f ( 0,  123.375, 25 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,  131.6, 21 );
		glVertex3f ( 24, 131.6, 21 );	
		glVertex3f ( 24, 123.375, 25 );
		glVertex3f ( 0,  123.375, 25 );
	  glEnd();
	glPopMatrix();

    //fifth arch combo
      //veritcal flat short walls that connect to the angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,  148.05, 18 );
		glVertex3f ( 0,  148.05, 21 );	
		glVertex3f ( 24, 148.05, 21 );
		glVertex3f ( 24, 148.05, 18 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,  164.5, 18 );
		glVertex3f ( 0,  164.5, 21 );	
		glVertex3f ( 24, 164.5, 21 );
		glVertex3f ( 24, 164.5, 18 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.9, 0.5);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,  148.05, 21 );
		glVertex3f ( 24, 148.05, 21 );	
		glVertex3f ( 24, 156.275, 25 );
		glVertex3f ( 0,  156.275, 25 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	 glScalef(0.1, 0.1, 0.1);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,  164.5, 21 );
		glVertex3f ( 24, 164.5, 21 );	
		glVertex3f ( 24, 156.275, 25 );
		glVertex3f ( 0,  156.275, 25 );
	  glEnd();
	glPopMatrix();
//////////////////////////////////////////////
//walls//
   //left wall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.4, 0.8, 1.0);
	glScalef(0.1, 0.1, 0.1); 
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, 0, -2 );
		glVertex3f ( 0, 0, 25 );	
		glVertex3f ( 0, 181, 25 );
		glVertex3f ( 0, 181, -2 );
	 glEnd();
	glPopMatrix();
    //rightwall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(1.0, 0.5, 0.0);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, -24, -2 );
		glVertex3f ( 24, -24, 25 );	
		glVertex3f ( 24, 181, 25 );
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
		glVertex3f ( 24, 181, 18 );
		glVertex3f ( 0, 181, 18 );	
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
		glVertex3f ( 24, 0, 18 );
		glVertex3f ( 0, 0, 18 );	
		glVertex3f ( 0, 0, 13 );
		glVertex3f ( 24, 0, 13 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, -1, 18 );
		glVertex3f ( 0, -1, 18 );	
		glVertex3f ( 0, -1, 13 );
		glVertex3f ( 24, -1, 13 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, 0, 13 );
		glVertex3f ( 0, 0, 13 );	
		glVertex3f ( 0, -1, 13 );
		glVertex3f ( 24, -1, 13 );
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
		glVertex3f ( 0, 0, 13 );	
		glVertex3f ( 2, 0, 13 );
		glVertex3f ( 2, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, -1, -2 );
		glVertex3f ( 0, -1, 13 );	
		glVertex3f ( 2, -1, 13 );
		glVertex3f ( 2, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2, 0, -2 );
		glVertex3f ( 2, 0, 13 );	
		glVertex3f ( 2, -1, 13 );
		glVertex3f ( 2, -1, -2 );
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
		glVertex3f ( 24, 0, 13 );	
		glVertex3f ( 22, 0, 13 );
		glVertex3f ( 22, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, -1, -2 );
		glVertex3f ( 24, -1, 13 );	
		glVertex3f ( 22, -1, 13 );
		glVertex3f ( 22, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 22, 0, -2 );
		glVertex3f ( 22, 0, 13 );	
		glVertex3f ( 22, -1, 13 );
		glVertex3f ( 22, -1, -2 );
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
		glVertex3f ( 7.5, 0, 13 );	
		glVertex3f ( 9, 0, 13 );
		glVertex3f ( 9, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.5, -1, -2 );
		glVertex3f ( 7.5, -1, 13 );	
		glVertex3f ( 9, -1, 13 );
		glVertex3f ( 9, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.5, 0, -2 );
		glVertex3f ( 7.5, 0, 13 );	
		glVertex3f ( 7.5, -1, 13 );
		glVertex3f ( 7.5, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 9, 0, -2 );
		glVertex3f ( 9, 0, 13 );	
		glVertex3f ( 9, -1, 13 );
		glVertex3f ( 9, -1, -2 );
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
		glVertex3f ( 16.5, 0, 13 );	
		glVertex3f ( 15, 0, 13 );
		glVertex3f ( 15, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 16.5, -1, -2 );
		glVertex3f ( 16.5, -1, 13 );	
		glVertex3f ( 15, -1, 13 );
		glVertex3f ( 15, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 15, 0, -2 );
		glVertex3f ( 15, 0, 13 );	
		glVertex3f ( 15, -1, 13 );
		glVertex3f ( 15, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 16.5, 0, -2 );
		glVertex3f ( 16.5, 0, 13 );	
		glVertex3f ( 16.5, -1, 13 );
		glVertex3f ( 16.5, -1, -2 );
	 glEnd();
	glPopMatrix();
///////////////////////////////////////////////////////////
//arches towards food court///////////////////////////////

glPushMatrix();
glRotatef(-90, 0.0, 0.0, 1.0);

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, 0, 18 );
		glVertex3f ( 0, 0, 18 );	
		glVertex3f ( 0, 0, 13 );
		glVertex3f ( 24, 0, 13 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, -1, 18 );
		glVertex3f ( 0, -1, 18 );	
		glVertex3f ( 0, -1, 13 );
		glVertex3f ( 24, -1, 13 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, 0, 13 );
		glVertex3f ( 0, 0, 13 );	
		glVertex3f ( 0, -1, 13 );
		glVertex3f ( 24, -1, 13 );
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
		glVertex3f ( 0, 0, 13 );	
		glVertex3f ( 2, 0, 13 );
		glVertex3f ( 2, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, -1, -2 );
		glVertex3f ( 0, -1, 13 );	
		glVertex3f ( 2, -1, 13 );
		glVertex3f ( 2, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2, 0, -2 );
		glVertex3f ( 2, 0, 13 );	
		glVertex3f ( 2, -1, 13 );
		glVertex3f ( 2, -1, -2 );
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
		glVertex3f ( 24, 0, 13 );	
		glVertex3f ( 22, 0, 13 );
		glVertex3f ( 22, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, -1, -2 );
		glVertex3f ( 24, -1, 13 );	
		glVertex3f ( 22, -1, 13 );
		glVertex3f ( 22, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 22, 0, -2 );
		glVertex3f ( 22, 0, 13 );	
		glVertex3f ( 22, -1, 13 );
		glVertex3f ( 22, -1, -2 );
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
		glVertex3f ( 7.5, 0, 13 );	
		glVertex3f ( 9, 0, 13 );
		glVertex3f ( 9, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.5, -1, -2 );
		glVertex3f ( 7.5, -1, 13 );	
		glVertex3f ( 9, -1, 13 );
		glVertex3f ( 9, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.5, 0, -2 );
		glVertex3f ( 7.5, 0, 13 );	
		glVertex3f ( 7.5, -1, 13 );
		glVertex3f ( 7.5, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 9, 0, -2 );
		glVertex3f ( 9, 0, 13 );	
		glVertex3f ( 9, -1, 13 );
		glVertex3f ( 9, -1, -2 );
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
		glVertex3f ( 16.5, 0, 13 );	
		glVertex3f ( 15, 0, 13 );
		glVertex3f ( 15, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 16.5, -1, -2 );
		glVertex3f ( 16.5, -1, 13 );	
		glVertex3f ( 15, -1, 13 );
		glVertex3f ( 15, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 15, 0, -2 );
		glVertex3f ( 15, 0, 13 );	
		glVertex3f ( 15, -1, 13 );
		glVertex3f ( 15, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 16.5, 0, -2 );
		glVertex3f ( 16.5, 0, 13 );	
		glVertex3f ( 16.5, -1, 13 );
		glVertex3f ( 16.5, -1, -2 );
	 glEnd();
	glPopMatrix();

glPopMatrix();

/////////////////////////////////////////////////////////////////////////
//arches in wall oppisite food court route///////////////////////////////

glPushMatrix();

glTranslatef(2.45, 0.0, 0.0);
glRotatef(-90, 0.0, 0.0, 1.0);

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, 0, 18 );
		glVertex3f ( 0, 0, 18 );	
		glVertex3f ( 0, 0, 13 );
		glVertex3f ( 24, 0, 13 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, -1, 18 );
		glVertex3f ( 0, -1, 18 );	
		glVertex3f ( 0, -1, 13 );
		glVertex3f ( 24, -1, 13 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, 0, 13 );
		glVertex3f ( 0, 0, 13 );	
		glVertex3f ( 0, -1, 13 );
		glVertex3f ( 24, -1, 13 );
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
		glVertex3f ( 0, 0, 13 );	
		glVertex3f ( 2, 0, 13 );
		glVertex3f ( 2, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, -1, -2 );
		glVertex3f ( 0, -1, 13 );	
		glVertex3f ( 2, -1, 13 );
		glVertex3f ( 2, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2, 0, -2 );
		glVertex3f ( 2, 0, 13 );	
		glVertex3f ( 2, -1, 13 );
		glVertex3f ( 2, -1, -2 );
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
		glVertex3f ( 24, 0, 13 );	
		glVertex3f ( 22, 0, 13 );
		glVertex3f ( 22, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, -1, -2 );
		glVertex3f ( 24, -1, 13 );	
		glVertex3f ( 22, -1, 13 );
		glVertex3f ( 22, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 22, 0, -2 );
		glVertex3f ( 22, 0, 13 );	
		glVertex3f ( 22, -1, 13 );
		glVertex3f ( 22, -1, -2 );
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
		glVertex3f ( 7.5, 0, 13 );	
		glVertex3f ( 9, 0, 13 );
		glVertex3f ( 9, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.5, -1, -2 );
		glVertex3f ( 7.5, -1, 13 );	
		glVertex3f ( 9, -1, 13 );
		glVertex3f ( 9, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.5, 0, -2 );
		glVertex3f ( 7.5, 0, 13 );	
		glVertex3f ( 7.5, -1, 13 );
		glVertex3f ( 7.5, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 9, 0, -2 );
		glVertex3f ( 9, 0, 13 );	
		glVertex3f ( 9, -1, 13 );
		glVertex3f ( 9, -1, -2 );
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
		glVertex3f ( 16.5, 0, 13 );	
		glVertex3f ( 15, 0, 13 );
		glVertex3f ( 15, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 16.5, -1, -2 );
		glVertex3f ( 16.5, -1, 13 );	
		glVertex3f ( 15, -1, 13 );
		glVertex3f ( 15, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 15, 0, -2 );
		glVertex3f ( 15, 0, 13 );	
		glVertex3f ( 15, -1, 13 );
		glVertex3f ( 15, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 16.5, 0, -2 );
		glVertex3f ( 16.5, 0, 13 );	
		glVertex3f ( 16.5, -1, 13 );
		glVertex3f ( 16.5, -1, -2 );
	 glEnd();
	glPopMatrix();

glPopMatrix();

/////////////////////////////////////////////////////////////////////////
//arches in front of pres room///////////////////////////////

glPushMatrix();

glTranslatef(0.0, -2.4, 0.0);


	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, 0, 18 );
		glVertex3f ( 0, 0, 18 );	
		glVertex3f ( 0, 0, 13 );
		glVertex3f ( 24, 0, 13 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, -1, 18 );
		glVertex3f ( 0, -1, 18 );	
		glVertex3f ( 0, -1, 13 );
		glVertex3f ( 24, -1, 13 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, 0, 13 );
		glVertex3f ( 0, 0, 13 );	
		glVertex3f ( 0, -1, 13 );
		glVertex3f ( 24, -1, 13 );
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
		glVertex3f ( 0, 0, 13 );	
		glVertex3f ( 2, 0, 13 );
		glVertex3f ( 2, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, -1, -2 );
		glVertex3f ( 0, -1, 13 );	
		glVertex3f ( 2, -1, 13 );
		glVertex3f ( 2, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2, 0, -2 );
		glVertex3f ( 2, 0, 13 );	
		glVertex3f ( 2, -1, 13 );
		glVertex3f ( 2, -1, -2 );
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
		glVertex3f ( 24, 0, 13 );	
		glVertex3f ( 22, 0, 13 );
		glVertex3f ( 22, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 24, -1, -2 );
		glVertex3f ( 24, -1, 13 );	
		glVertex3f ( 22, -1, 13 );
		glVertex3f ( 22, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 22, 0, -2 );
		glVertex3f ( 22, 0, 13 );	
		glVertex3f ( 22, -1, 13 );
		glVertex3f ( 22, -1, -2 );
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
		glVertex3f ( 7.5, 0, 13 );	
		glVertex3f ( 9, 0, 13 );
		glVertex3f ( 9, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.5, -1, -2 );
		glVertex3f ( 7.5, -1, 13 );	
		glVertex3f ( 9, -1, 13 );
		glVertex3f ( 9, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.5, 0, -2 );
		glVertex3f ( 7.5, 0, 13 );	
		glVertex3f ( 7.5, -1, 13 );
		glVertex3f ( 7.5, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 9, 0, -2 );
		glVertex3f ( 9, 0, 13 );	
		glVertex3f ( 9, -1, 13 );
		glVertex3f ( 9, -1, -2 );
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
		glVertex3f ( 16.5, 0, 13 );	
		glVertex3f ( 15, 0, 13 );
		glVertex3f ( 15, 0, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 16.5, -1, -2 );
		glVertex3f ( 16.5, -1, 13 );	
		glVertex3f ( 15, -1, 13 );
		glVertex3f ( 15, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 15, 0, -2 );
		glVertex3f ( 15, 0, 13 );	
		glVertex3f ( 15, -1, 13 );
		glVertex3f ( 15, -1, -2 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	glScalef(0.1, 0.1, 0.1);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 16.5, 0, -2 );
		glVertex3f ( 16.5, 0, 13 );	
		glVertex3f ( 16.5, -1, 13 );
		glVertex3f ( 16.5, -1, -2 );
	 glEnd();
	glPopMatrix();

glPopMatrix();

///////////////////////////////////////////
//objects inside the level//

//display cases "rough"

   //defining a cube
   struct box faces[6];
   defineBox(&faces[0]);

	//drawing 8 cases in rough location
//left side cubes front to back
	/*bottom 1*/
	glPushMatrix();
	glBegin(GL_POLYGON);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,2.8702,0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
	glPopMatrix();

	/*top base 1*/
	glPushMatrix();
    glTranslated(0.0,0.0,0.4572);
	glBegin(GL_POLYGON);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,2.8702,0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
	glPopMatrix();
	
	/*left base 1*/
	glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,2.8702,0.0);
    glVertex3f(0.0,2.8702,0.4572);
    glVertex3f(0.0,0.0,0.4572);
    glEnd();
    glPopMatrix();
 
	/*right base 1*/	
	glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(1.5748,0.0,0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glVertex3f(1.5748,0.0,0.4572);
    glEnd();
    glPopMatrix();

	/*back base 1*/
	glPushMatrix();
   	glColor3f(0.0,1.0,1.0); 
	glBegin(GL_POLYGON);
    glVertex3f(0.0,2.8702,0.0);
    glVertex3f(0.0,2.8702,0.4572);
    glVertex3f(1.5748,2.8702,0.4572);
    glVertex3f(1.5748,2.8702,0.0);
    glEnd();
    glPopMatrix();

	/*front base 1*/
	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
    glVertex3f(1.5748,0.0,0.0);
    glVertex3f(1.5748,0.0,0.4572);
    glVertex3f(0.0,0.0,0.4572);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    glPopMatrix();

	/*front glass 1*/
	glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.127,0.127,0.4572);
    glVertex3f(1.4478,0.127,0.4572);
    glVertex3f(1.4478,0.127,2.5146);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();
	
	/*back glass 1*/
	glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.127,2.7432,2.5146);
    glVertex3f(1.4478,2.7432,2.5146);
    glVertex3f(1.4478,2.7432,0.4572);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

	/*left glass 1*/
	glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.127,2.7432,2.5146);
    glVertex3f(0.127,0.127,2.5146);
    glVertex3f(0.127,0.127,0.4572);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();
	
	/*right glass 1*/
	glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(1.4478,0.127,2.5146);
    glVertex3f(1.4478,2.7432,2.5146);
    glVertex3f(1.4478,2.7432,0.4572);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

	/*top glass 1*/
	glPushMatrix();
    glTranslated(0.0,0.0,2.5146);
    glBegin(GL_POLYGON);
    glVertex3f(0.127,0.127,2.5146);
    glVertex3f(0.127,2.7432,2.5146);
    glVertex3f(1.4478,2.7432,2.5146);
    glVertex3f(1.4478,0.127,2.5146);
    glEnd();
    glPopMatrix();

	glPushMatrix();
	 glTranslatef(0.55, 5.7575, 0.0);
	 glScalef(0.15, 0.4, 0.6);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(0.55, 9.0475, 0.0);
	 glScalef(0.15, 0.4, 0.6);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(0.55, 12.3375, 0.0);
	 glScalef(0.15, 0.4, 0.6);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(0.55, 15.6275, 0.0);
	 glScalef(0.15, 0.4, 0.6);
	 drawBox(&faces[0]);
	glPopMatrix();
//right side cubes front to back
	glPushMatrix();
	 glTranslatef(1.85, 2.4675, 0.0);
	 glScalef(0.15, 0.4, 0.6);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(1.85, 5.7575, 0.0);
	 glScalef(0.15, 0.4, 0.6);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(1.85, 9.0475, 0.0);
	 glScalef(0.15, 0.4, 0.6);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(1.85, 12.3375, 0.0);
	 glScalef(0.15, 0.4, 0.6);
	 drawBox(&faces[0]);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(1.85, 15.6275, 0.0);
	 glScalef(0.15, 0.4, 0.6);
	 drawBox(&faces[0]);
	glPopMatrix();
////////////////////////////////////////////////////
//food court area


//swap buffers
	glutSwapBuffers();

}
#endif
