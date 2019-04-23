#ifndef LEVELS
#define LEVELS

#include "includes.h"
#include "game.h"
#include "globals.h"
#include "structs.h"
#include "prototypes.h"

//extern double centerX, centerY, centerZ;
//extern double CAMERA_R, CAMERA_THETA, CAMERA_PHI;
//extern GLuint textureID[45];

void buildHeritageHall(void){

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();   	//call this before setting the viewing positi
	gluLookAt( CAMERA_R*sin(CAMERA_THETA*M_PI/180.0)*cos(CAMERA_PHI*M_PI/180.0), //1.2  
		CAMERA_R*sin(CAMERA_THETA*M_PI/180.0)*sin(CAMERA_PHI*M_PI/180.0),  //-0.2
		CAMERA_R*cos(CAMERA_THETA*M_PI/180.0),  // 0.2 Eye
		centerX,  //1.2
		centerY, //3.6
		centerZ,
        0,0,1 //0.7 Center
);
	glEnable(GL_DEPTH_TEST);

//floor//
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, textureID[37]);//42]);	
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(1.0, 0.0, 0.0);
	glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, 0, 0 );
		glTexCoord2d(0.0, 10.0);
		glVertex3f ( 7.3152, 0, 0 );
		glTexCoord2d(10.0, 10.0);	
		glVertex3f ( 7.3152, 55.1688, 0 );
		glTexCoord2d(10.0, 0.0);
		glVertex3f ( 0, 55.1688, 0 );
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	glPushMatrix();
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(1.0, 0.0, 1.0);

	glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 0, 0 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, -7.3152, 0 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0, -7.3152, 0 );
	glEnd();
	glPopMatrix();
//////////////////////////////////////////////
//ceiling//

//ceiling above front area
	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	glPushMatrix();
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(1.0, 0.6, 0.6);
	glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, 0, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 0, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, -7.3152, 5.4864 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0, -7.3152, 5.4864 );
	glEnd();
	glPopMatrix();



// the ceiling of heritage hall is set up as arches and flats

  //flats from front to back	
	glBindTexture(GL_TEXTURE_2D, textureID[2]);
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, 0, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 0, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 5.01396, 5.4864 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0, 5.01396, 5.4864 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, 10.02792, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 10.02792, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 15.04188, 5.4864 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0, 15.04188, 5.4864 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, 20.05584, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 20.05584, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 25.0698, 5.4864 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0, 25.0698, 5.4864 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      30.08376, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 30.08376, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 35.09772, 5.4864 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      35.09772, 5.4864 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      40.11168, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 40.11168, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 45.12564, 5.4864 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      45.12564, 5.4864 );
	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      50.1396, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 50.1396, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 55.1688, 5.4864 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      55.1688, 5.4864 );
	  glEnd();
	glPopMatrix();
 //arches (multi rectangles) from front to back
    //first arch combo
      //veritcal flat short walls that connect to the angled ceiling pieces
	glBindTexture(GL_TEXTURE_2D, textureID[3]);
        //front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      5.01396, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0,      5.01396, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 5.01396, 6.4008 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 5.01396, 5.4864 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      10.02792, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0,      10.02792, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 10.02792, 6.4008 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 10.02792, 5.4864 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.9, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      5.01396, 6.4008 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 5.01396, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 7.52094, 7.62 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      7.52094, 7.62 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      10.02792, 6.4008 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 10.02792, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 7.52094,  7.62 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      7.52094,  7.62 );
	  glEnd();
	glPopMatrix();

    //second arch combo
      //veritcal flat short walls that connect to the angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      15.04188, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0,      15.04188, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 15.04188, 6.4008 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 15.04188, 5.4864 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      20.05584, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0,      20.05584, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 20.05584, 6.4008 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 20.05584, 5.4864 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.9, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      15.04188, 6.4008 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 15.04188, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 17.54886, 7.62 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      17.54886, 7.62 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      20.05584, 6.4008 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 20.05584, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 17.54886,  7.62 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      17.54886,  7.62 );
	  glEnd();
	glPopMatrix();

    //third arch combo
      //veritcal flat short walls that connect to the angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      25.0698, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0,      25.0698, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 25.0698, 6.4008 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 25.0698, 5.4864 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      30.08376, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0,      30.08376, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 30.08376, 6.4008 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 30.08376, 5.4864 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.9, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      25.0698, 6.4008 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 25.0698, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 27.57678, 7.62 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      27.57678, 7.62 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      30.08376, 6.4008 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 30.08376, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 27.57678,  7.62 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      27.57678,  7.62 );
	  glEnd();
	glPopMatrix();

    //forth arch combo
      //veritcal flat short walls that connect to the angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      35.09772, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0,      35.09772, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 35.09772, 6.4008 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 35.09772, 5.4864 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      40.11168, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0,      40.11168, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 40.11168, 6.4008 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 40.11168, 5.4864 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.9, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      35.09772, 6.4008 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 35.09772, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 37.6047, 7.62 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      37.6047, 7.62 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      40.11168, 6.4008 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 40.11168, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 37.6047,  7.62 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      37.6047,  7.62 );
	  glEnd();
	glPopMatrix();

    //fifth arch combo
      //veritcal flat short walls that connect to the angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      45.12564, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0,      45.12564, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 45.12564, 6.4008 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 45.12564, 5.4864 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      50.1396, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0,      50.1396, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 50.1396, 6.4008 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 50.1396, 5.4864 );
	  glEnd();
	glPopMatrix();
      //angled ceiling pieces
	//front
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.9, 0.5);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      45.12564, 6.4008 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 45.12564, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 47.63262, 7.62 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      47.63262, 7.62 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	  glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0,      50.1396, 6.4008 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 50.1396, 6.4008 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 47.63262,  7.62 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0,      47.63262,  7.62 );
	  glEnd();
	glPopMatrix();

//////////////////////////////////////////////
//walls//
   //left wall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.4, 0.8, 1.0); 
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 7.62 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, 55.1688, 7.62 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0, 55.1688, 0 );
	 glEnd();
	glPopMatrix();
    //rightwall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(1.0, 0.5, 0.0);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, -7.3152, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, -7.3152, 7.62 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 7.3152, 55.1688, 7.62 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 55.1688, 0 );
	 glEnd();
	glPopMatrix();
   //backwall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 1.0, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 55.1688, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0,      55.1688, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0,      55.1688, 0 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 55.1688, 0 );
	 glEnd();
	glPopMatrix();
   //frontwall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 0, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 0, 3.9624 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, -0.3048, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 3.9624 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 0, 3.9624 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 3.9624 );
	 glEnd();
	glPopMatrix();
       //frontwall leftindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.6096, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.6096, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.6096, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.6096, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.6096, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.6096, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
       //frontwall rightindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 6.7056, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 6.7056, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 6.7056, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 6.7056, 0,       0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 6.7056, 0,       3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 6.7056, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
	//flats for pillars
	 //left
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.286, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.286, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.7432, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.7432, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.286, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.286, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.7432, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.286, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.286, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.286, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.286, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.7432, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.7432, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.7432, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
	 //right
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 5.0292, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 4.572, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 4.572, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 5.0292, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 5.0292, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 4.572, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 4.572, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 4.572, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 4.572, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 5.0292, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 5.0292, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 5.0292, -0.3048, 0 );
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
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 0, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 0, 3.9624 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, -0.3048, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 3.9624 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 0, 3.9624 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 3.9624 );
	 glEnd();
	glPopMatrix();
       //frontwall leftindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.6096, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.6096, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.6096, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.6096, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.6096, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.6096, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
       //frontwall rightindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 6.7056, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 6.7056, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 6.7056, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 6.7056, 0,       0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 6.7056, 0,       3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 6.7056, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
	//flats for pillars
	 //left
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.286, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.286, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.7432, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.7432, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.286, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.286, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.7432, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.286, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.286, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.286, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.286, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.7432, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.7432, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.7432, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
	 //right
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 5.0292, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 4.572, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 4.572, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 5.0292, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 5.0292, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 4.572, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 4.572, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 4.572, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 4.572, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 5.0292, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 5.0292, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 5.0292, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

glPopMatrix();

/////////////////////////////////////////////////////////////////////////
//arches in wall oppisite food court route///////////////////////////////

glPushMatrix();

glTranslatef(7.4676, 0.0, 0.0);
glRotatef(-90, 0.0, 0.0, 1.0);
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 0, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 0, 3.9624 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, -0.3048, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 3.9624 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 0, 3.9624 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 3.9624 );
	 glEnd();
	glPopMatrix();
       //frontwall leftindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.6096, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.6096, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.6096, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.6096, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.6096, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.6096, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
       //frontwall rightindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 6.7056, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 6.7056, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 6.7056, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 6.7056, 0,       0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 6.7056, 0,       3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 6.7056, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
	//flats for pillars
	 //left
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.286, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.286, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.7432, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.7432, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.286, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.286, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.7432, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.286, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.286, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.286, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.286, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.7432, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.7432, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.7432, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
	 //right
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 5.0292, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 4.572, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 4.572, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 5.0292, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 5.0292, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 4.572, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 4.572, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 4.572, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 4.572, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 5.0292, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 5.0292, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 5.0292, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

glPopMatrix();

/////////////////////////////////////////////////////////////////////////
//arches in front of pres room///////////////////////////////

glPushMatrix();

glTranslatef(0.0, -7.3152, 0.0);

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 0, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, 0, 3.9624 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 5.4864 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, -0.3048, 5.4864 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 3.9624 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 0, 3.9624 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 3.9624 );
	 glEnd();
	glPopMatrix();
       //frontwall leftindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.6096, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.6096, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.6096, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.6096, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.6096, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.6096, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
       //frontwall rightindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 6.7056, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 6.7056, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 7.3152, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 6.7056, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 6.7056, 0,       0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 6.7056, 0,       3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 6.7056, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
	//flats for pillars
	 //left
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.286, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.286, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.7432, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.7432, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.286, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.286, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.7432, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.286, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.286, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.286, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.286, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 2.7432, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 2.7432, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 2.7432, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
	 //right
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 5.0292, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 4.572, 0, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 4.572, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 5.0292, -0.3048, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 5.0292, -0.3048, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 4.572, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 4.572, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 4.572, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 4.572, -0.3048, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 5.0292, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glTexCoord2d(1.0, 1.0);
		glVertex3f ( 5.0292, -0.3048, 3.9624 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 5.0292, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
glPopMatrix();

glDisable(GL_DEPTH_TEST);
//glDisable(GL_TEXTURE_2D);
///////////////////////////////////////////
//objects inside the level//

//display cases "rough"
drawDisplayCase();
////////////////////////////////////////////////////
//food court area




}
#endif
