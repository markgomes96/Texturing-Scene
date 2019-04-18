#ifndef LEVELS
#define LEVELS

#include "includes.h"
#include "game.h"
#include "globals.h"
#include "structs.h"
#include "prototypes.h"


extern glm::vec3 cameraPos, cameraTarget, up;



extern double scaleX, scaleY, scaleZ ;
extern const int WINDOW_MAX_X, WINDOW_MAX_Y;
extern int jump;
extern key_state keyarr[127];
void showMinimap(){
	//Function to generate minimap
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glEnable(GL_SCISSOR_TEST);
	glScissor(WINDOW_MAX_X-300, 50, 200, 200);
	glLoadIdentity();
	gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0 ,0 ,1);
	glMatrixMode(GL_MODELVIEW);

	buildHeritageHall();
	glPopMatrix();

}
void buildDisplay(){


	buildCameraScene();
	buildHeritageHall();

}
void buildCameraScene(){

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	//glPushMatrix();
	glEnable(GL_SCISSOR_TEST);
	glLoadIdentity();   	//call this before setting the viewing position

    glScissor(WINDOW_MAX_X-200, 200, 200, 200);
	if(true){
		showMinimap();
	}
	glViewport(0, 0, WINDOW_MAX_X, WINDOW_MAX_Y);
	glScissor(0, 0, WINDOW_MAX_X, WINDOW_MAX_Y);
	
    if ( keyarr['z']){
        scaleX *= 1.1;
        scaleY *= 1.1;
        scaleZ *= 1.1;
    }
 if ( keyarr['x']){
        scaleX /= 1.1;
        scaleY /= 1.1;
        scaleZ /= 1.1;
    }
	if ( keyarr['t']){
		//Throw Object
		g.createProjectile( CAMERA_R*sin(CAMERA_THETA*M_PI/180.0)*cos(CAMERA_PHI*M_PI
					/180.0),
				CAMERA_R*sin(CAMERA_THETA*M_PI/180.0)*sin(CAMERA_PHI*M_PI
					/180.0),
				CAMERA_R*cos(CAMERA_THETA*M_PI/180.0),1,
				scaleX, scaleY, scaleZ);
	}
#ifdef DEV
	if ( keyarr['e']){
		// Create a box where the eye is
		g.createEye(centerX, centerY, centerZ, 1, 0.2, 0.2, 0.2);
	}
#endif
	if ( keyarr['j']){
		if (jump == 0)
			jump = 1;
	}
    // If jump = 0, do nothing
    // if 0 < jump < 5, go up, increase jump by 1
    // if jump = 5, turn jump = -1
    // if jump < 0 , go down
    // if jump = -5, set jump = 0 
    if (jump!= 0){
        if (jump == 5){
            jump = -1;
        } else if (jump > 0){
            CAMERA_THETA -= 1.0;
            if (CAMERA_THETA < 0.0)
                CAMERA_THETA += 360.0;
            jump+=1;
        } else if ((jump < 0) && (jump > -5)){
            CAMERA_THETA += 1.0;
            if (CAMERA_THETA > 0.0){
                CAMERA_THETA -= 360.0;
            }
            jump -= 1;
        } else{
                jump =0;
            }
   }
   
}
void buildHeritageHall(void){

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
	
	gluLookAt( (double)cameraPos.x, (double)cameraPos.y, (double)cameraPos.z,
			(double) cameraTarget.x, // + cameraFront.x,
			(double) cameraTarget.y, // + cameraFront.y,
			(double) cameraTarget.z, // + cameraFront.z,
			(double) up.x, (double) up.y, (double) up.z); 	// Up */


	

//floor//
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, textureID[0]);	

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureID[0]);	
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(1.0, 0.0, 0.0);
	glBegin ( GL_POLYGON );

		glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0, 0, 0 );
		glTexCoord2d(0.0, 1.0);
		glVertex3f ( 7.3152, 0, 0 );
		glTexCoord2d(1.0, 1.0);	
		glVertex3f ( 7.3152, 55.1688, 0 );
		glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0, 55.1688, 0 );

	glEnd();
	glPopMatrix();
	//glDisable(GL_TEXTURE_2D);

	glPushMatrix();
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(1.0, 0.0, 1.0);

	glBegin ( GL_POLYGON );

		glVertex3f ( 0, 0, 0 );
		glVertex3f ( 7.3152, 0, 0 );	
		glVertex3f ( 7.3152, -7.3152, 0 );
		glVertex3f ( 0, -7.3152, 0 );
	glEnd();
	glPopMatrix();
//////////////////////////////////////////////
//ceiling//

//ceiling above front area
	glPushMatrix();
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(1.0, 0.6, 0.6);
	glBegin ( GL_POLYGON );

		glVertex3f ( 0, 0, 5.4864 );
		glVertex3f ( 7.3152, 0, 5.4864 );	
		glVertex3f ( 7.3152, -7.3152, 5.4864 );
		glVertex3f ( 0, -7.3152, 5.4864 );

	glEnd();
	glPopMatrix();



// the ceiling of heritage hall is set up as arches and flats

  //flats from front to back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );

		glVertex3f ( 0, 0, 5.4864 );
		glVertex3f ( 7.3152, 0, 5.4864 );	
		glVertex3f ( 7.3152, 5.01396, 5.4864 );
		glVertex3f ( 0, 5.01396, 5.4864 );

	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );

		glVertex3f ( 0, 10.02792, 5.4864 );
		glVertex3f ( 7.3152, 10.02792, 5.4864 );	
		glVertex3f ( 7.3152, 15.04188, 5.4864 );
		glVertex3f ( 0, 15.04188, 5.4864 );


	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );

		glVertex3f ( 0, 20.05584, 5.4864 );
		glVertex3f ( 7.3152, 20.05584, 5.4864 );	
		glVertex3f ( 7.3152, 25.0698, 5.4864 );
		glVertex3f ( 0, 25.0698, 5.4864 );

	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,      30.08376, 5.4864 );
		glVertex3f ( 7.3152, 30.08376, 5.4864 );	
		glVertex3f ( 7.3152, 35.09772, 5.4864 );
		glVertex3f ( 0,      35.09772, 5.4864 );

	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );

		glVertex3f ( 0,      40.11168, 5.4864 );
		glVertex3f ( 7.3152, 40.11168, 5.4864 );	
		glVertex3f ( 7.3152, 45.12564, 5.4864 );
		glVertex3f ( 0,      45.12564, 5.4864 );

	  glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );

		glVertex3f ( 0,      50.1396, 5.4864 );
		glVertex3f ( 7.3152, 50.1396, 5.4864 );	
		glVertex3f ( 7.3152, 55.1688, 5.4864 );
		glVertex3f ( 0,      55.1688, 5.4864 );

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
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,      5.01396, 5.4864 );
		glVertex3f ( 0,      5.01396, 6.4008 );	
		glVertex3f ( 7.3152, 5.01396, 6.4008 );
		glVertex3f ( 7.3152, 5.01396, 5.4864 );

	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );

		glVertex3f ( 0,      10.02792, 5.4864 );
		glVertex3f ( 0,      10.02792, 6.4008 );	
		glVertex3f ( 7.3152, 10.02792, 6.4008 );
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
		glVertex3f ( 0,      5.01396, 6.4008 );
		glVertex3f ( 7.3152, 5.01396, 6.4008 );	
		glVertex3f ( 7.3152, 7.52094, 7.62 );
		glVertex3f ( 0,      7.52094, 7.62 );

	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,      10.02792, 6.4008 );
		glVertex3f ( 7.3152, 10.02792, 6.4008 );	
		glVertex3f ( 7.3152, 7.52094,  7.62 );
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
		glVertex3f ( 0,      15.04188, 5.4864 );
		glVertex3f ( 0,      15.04188, 6.4008 );	
		glVertex3f ( 7.3152, 15.04188, 6.4008 );
		glVertex3f ( 7.3152, 15.04188, 5.4864 );

	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,      20.05584, 5.4864 );
		glVertex3f ( 0,      20.05584, 6.4008 );	
		glVertex3f ( 7.3152, 20.05584, 6.4008 );
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
		glVertex3f ( 0,      15.04188, 6.4008 );
		glVertex3f ( 7.3152, 15.04188, 6.4008 );	
		glVertex3f ( 7.3152, 17.54886, 7.62 );
		glVertex3f ( 0,      17.54886, 7.62 );

	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,      20.05584, 6.4008 );
		glVertex3f ( 7.3152, 20.05584, 6.4008 );	
		glVertex3f ( 7.3152, 17.54886,  7.62 );
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
		glVertex3f ( 0,      25.0698, 5.4864 );
		glVertex3f ( 0,      25.0698, 6.4008 );	
		glVertex3f ( 7.3152, 25.0698, 6.4008 );
		glVertex3f ( 7.3152, 25.0698, 5.4864 );

	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,      30.08376, 5.4864 );
		glVertex3f ( 0,      30.08376, 6.4008 );	
		glVertex3f ( 7.3152, 30.08376, 6.4008 );
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
		glVertex3f ( 0,      25.0698, 6.4008 );
		glVertex3f ( 7.3152, 25.0698, 6.4008 );	
		glVertex3f ( 7.3152, 27.57678, 7.62 );
		glVertex3f ( 0,      27.57678, 7.62 );

	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,      30.08376, 6.4008 );
		glVertex3f ( 7.3152, 30.08376, 6.4008 );	
		glVertex3f ( 7.3152, 27.57678,  7.62 );
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
		glVertex3f ( 0,      35.09772, 5.4864 );
		glVertex3f ( 0,      35.09772, 6.4008 );	
		glVertex3f ( 7.3152, 35.09772, 6.4008 );
		glVertex3f ( 7.3152, 35.09772, 5.4864 );

	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,      40.11168, 5.4864 );
		glVertex3f ( 0,      40.11168, 6.4008 );	
		glVertex3f ( 7.3152, 40.11168, 6.4008 );
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
		glVertex3f ( 0,      35.09772, 6.4008 );
		glVertex3f ( 7.3152, 35.09772, 6.4008 );	
		glVertex3f ( 7.3152, 37.6047, 7.62 );
		glVertex3f ( 0,      37.6047, 7.62 );

	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,      40.11168, 6.4008 );
		glVertex3f ( 7.3152, 40.11168, 6.4008 );	
		glVertex3f ( 7.3152, 37.6047,  7.62 );
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
		glVertex3f ( 0,      45.12564, 5.4864 );
		glVertex3f ( 0,      45.12564, 6.4008 );	
		glVertex3f ( 7.3152, 45.12564, 6.4008 );
		glVertex3f ( 7.3152, 45.12564, 5.4864 );

	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.5, 0.5);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,      50.1396, 5.4864 );
		glVertex3f ( 0,      50.1396, 6.4008 );	
		glVertex3f ( 7.3152, 50.1396, 6.4008 );
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
		glVertex3f ( 0,      45.12564, 6.4008 );
		glVertex3f ( 7.3152, 45.12564, 6.4008 );	
		glVertex3f ( 7.3152, 47.63262, 7.62 );
		glVertex3f ( 0,      47.63262, 7.62 );

	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.5, 0.5, 0.8);
	  glBegin ( GL_POLYGON );
		glVertex3f ( 0,      50.1396, 6.4008 );
		glVertex3f ( 7.3152, 50.1396, 6.4008 );	
		glVertex3f ( 7.3152, 47.63262,  7.62 );
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
		glVertex3f ( 0, 0, 0 );
		glVertex3f ( 0, 0, 7.62 );	
		glVertex3f ( 0, 55.1688, 7.62 );
		glVertex3f ( 0, 55.1688, 0 );

	 glEnd();
	glPopMatrix();
    //rightwall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(1.0, 0.5, 0.0);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, -7.3152, 0 );
		glVertex3f ( 7.3152, -7.3152, 7.62 );	
		glVertex3f ( 7.3152, 55.1688, 7.62 );
		glVertex3f ( 7.3152, 55.1688, 0 );

	 glEnd();
	glPopMatrix();
   //backwall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 1.0, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, 55.1688, 5.4864 );
		glVertex3f ( 0,      55.1688, 5.4864 );	
		glVertex3f ( 0,      55.1688, 0 );
		glVertex3f ( 7.3152, 55.1688, 0 );

	 glEnd();
	glPopMatrix();
   //frontwall
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, 0, 5.4864 );
		glVertex3f ( 0, 0, 5.4864 );	
		glVertex3f ( 0, 0, 3.9624 );
		glVertex3f ( 7.3152, 0, 3.9624 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, -0.3048, 5.4864 );
		glVertex3f ( 0, -0.3048, 5.4864 );	
		glVertex3f ( 0, -0.3048, 3.9624 );
		glVertex3f ( 7.3152, -0.3048, 3.9624 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, 0, 3.9624 );
		glVertex3f ( 0, 0, 3.9624 );	
		glVertex3f ( 0, -0.3048, 3.9624 );
		glVertex3f ( 7.3152, -0.3048, 3.9624 );

	 glEnd();
	glPopMatrix();
       //frontwall leftindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, 0, 0 );
		glVertex3f ( 0, 0, 3.9624 );	
		glVertex3f ( 0.6096, 0, 3.9624 );
		glVertex3f ( 0.6096, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, -0.3048, 0 );
		glVertex3f ( 0, -0.3048, 3.9624 );	
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glVertex3f ( 0.6096, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0.6096, 0, 0 );
		glVertex3f ( 0.6096, 0, 3.9624 );	
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glVertex3f ( 0.6096, -0.3048, 0 );

	 glEnd();
	glPopMatrix();
       //frontwall rightindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, 0, 0 );
		glVertex3f ( 7.3152, 0, 3.9624 );	
		glVertex3f ( 6.7056, 0, 3.9624 );
		glVertex3f ( 6.7056, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, -0.3048, 0 );
		glVertex3f ( 7.3152, -0.3048, 3.9624 );	
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
		glVertex3f ( 6.7056, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	
	 glBegin ( GL_POLYGON );
		glVertex3f ( 6.7056, 0,       0 );
		glVertex3f ( 6.7056, 0,       3.9624 );	
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
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
		glVertex3f ( 2.286, 0, 0 );
		glVertex3f ( 2.286, 0, 3.9624 );	
		glVertex3f ( 2.7432, 0, 3.9624 );
		glVertex3f ( 2.7432, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2.286, -0.3048, 0 );
		glVertex3f ( 2.286, -0.3048, 3.9624 );	
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glVertex3f ( 2.7432, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2.286, 0, 0 );
		glVertex3f ( 2.286, 0, 3.9624 );	
		glVertex3f ( 2.286, -0.3048, 3.9624 );
		glVertex3f ( 2.286, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2.7432, 0, 0 );
		glVertex3f ( 2.7432, 0, 3.9624 );	
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glVertex3f ( 2.7432, -0.3048, 0 );

	 glEnd();
	glPopMatrix();
	 //right
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 5.0292, 0, 0 );
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glVertex3f ( 4.572, 0, 3.9624 );
		glVertex3f ( 4.572, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 5.0292, -0.3048, 0 );
		glVertex3f ( 5.0292, -0.3048, 3.9624 );	
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glVertex3f ( 4.572, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 4.572, 0, 0 );
		glVertex3f ( 4.572, 0, 3.9624 );	
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glVertex3f ( 4.572, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 5.0292, 0, 0 );
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glVertex3f ( 5.0292, -0.3048, 3.9624 );
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
		glVertex3f ( 7.3152, 0, 5.4864 );
		glVertex3f ( 0, 0, 5.4864 );	
		glVertex3f ( 0, 0, 3.9624 );
		glVertex3f ( 7.3152, 0, 3.9624 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, -0.3048, 5.4864 );
		glVertex3f ( 0, -0.3048, 5.4864 );	
		glVertex3f ( 0, -0.3048, 3.9624 );
		glVertex3f ( 7.3152, -0.3048, 3.9624 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, 0, 3.9624 );
		glVertex3f ( 0, 0, 3.9624 );	
		glVertex3f ( 0, -0.3048, 3.9624 );
		glVertex3f ( 7.3152, -0.3048, 3.9624 );

	 glEnd();
	glPopMatrix();
       //frontwall leftindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, 0, 0 );
		glVertex3f ( 0, 0, 3.9624 );	
		glVertex3f ( 0.6096, 0, 3.9624 );
		glVertex3f ( 0.6096, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, -0.3048, 0 );
		glVertex3f ( 0, -0.3048, 3.9624 );	
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glVertex3f ( 0.6096, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0.6096, 0, 0 );
		glVertex3f ( 0.6096, 0, 3.9624 );	
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glVertex3f ( 0.6096, -0.3048, 0 );

	 glEnd();
	glPopMatrix();
       //frontwall rightindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, 0, 0 );
		glVertex3f ( 7.3152, 0, 3.9624 );	
		glVertex3f ( 6.7056, 0, 3.9624 );
		glVertex3f ( 6.7056, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, -0.3048, 0 );
		glVertex3f ( 7.3152, -0.3048, 3.9624 );	
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
		glVertex3f ( 6.7056, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	
	 glBegin ( GL_POLYGON );
		glVertex3f ( 6.7056, 0,       0 );
		glVertex3f ( 6.7056, 0,       3.9624 );	
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
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
		glVertex3f ( 2.286, 0, 0 );
		glVertex3f ( 2.286, 0, 3.9624 );	
		glVertex3f ( 2.7432, 0, 3.9624 );
		glVertex3f ( 2.7432, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2.286, -0.3048, 0 );
		glVertex3f ( 2.286, -0.3048, 3.9624 );	
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glVertex3f ( 2.7432, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2.286, 0, 0 );
		glVertex3f ( 2.286, 0, 3.9624 );	
		glVertex3f ( 2.286, -0.3048, 3.9624 );
		glVertex3f ( 2.286, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2.7432, 0, 0 );
		glVertex3f ( 2.7432, 0, 3.9624 );	
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glVertex3f ( 2.7432, -0.3048, 0 );

	 glEnd();
	glPopMatrix();
	 //right
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 5.0292, 0, 0 );
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glVertex3f ( 4.572, 0, 3.9624 );
		glVertex3f ( 4.572, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 5.0292, -0.3048, 0 );
		glVertex3f ( 5.0292, -0.3048, 3.9624 );	
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glVertex3f ( 4.572, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 4.572, 0, 0 );
		glVertex3f ( 4.572, 0, 3.9624 );	
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glVertex3f ( 4.572, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 5.0292, 0, 0 );
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glVertex3f ( 5.0292, -0.3048, 3.9624 );
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
		glVertex3f ( 7.3152, 0, 5.4864 );
		glVertex3f ( 0, 0, 5.4864 );	
		glVertex3f ( 0, 0, 3.9624 );
		glVertex3f ( 7.3152, 0, 3.9624 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, -0.3048, 5.4864 );
		glVertex3f ( 0, -0.3048, 5.4864 );	
		glVertex3f ( 0, -0.3048, 3.9624 );
		glVertex3f ( 7.3152, -0.3048, 3.9624 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, 0, 3.9624 );
		glVertex3f ( 0, 0, 3.9624 );	
		glVertex3f ( 0, -0.3048, 3.9624 );
		glVertex3f ( 7.3152, -0.3048, 3.9624 );

	 glEnd();
	glPopMatrix();
       //frontwall leftindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, 0, 0 );
		glVertex3f ( 0, 0, 3.9624 );	
		glVertex3f ( 0.6096, 0, 3.9624 );
		glVertex3f ( 0.6096, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, -0.3048, 0 );
		glVertex3f ( 0, -0.3048, 3.9624 );	
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glVertex3f ( 0.6096, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0.6096, 0, 0 );
		glVertex3f ( 0.6096, 0, 3.9624 );	
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glVertex3f ( 0.6096, -0.3048, 0 );
	 glEnd();
	glPopMatrix();
       //frontwall rightindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, 0, 0 );
		glVertex3f ( 7.3152, 0, 3.9624 );	
		glVertex3f ( 6.7056, 0, 3.9624 );
		glVertex3f ( 6.7056, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, -0.3048, 0 );
		glVertex3f ( 7.3152, -0.3048, 3.9624 );	
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
		glVertex3f ( 6.7056, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	
	 glBegin ( GL_POLYGON );
		glVertex3f ( 6.7056, 0,       0 );
		glVertex3f ( 6.7056, 0,       3.9624 );	
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
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
		glVertex3f ( 2.286, 0, 0 );
		glVertex3f ( 2.286, 0, 3.9624 );	
		glVertex3f ( 2.7432, 0, 3.9624 );
		glVertex3f ( 2.7432, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2.286, -0.3048, 0 );
		glVertex3f ( 2.286, -0.3048, 3.9624 );	
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glVertex3f ( 2.7432, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2.286, 0, 0 );
		glVertex3f ( 2.286, 0, 3.9624 );	
		glVertex3f ( 2.286, -0.3048, 3.9624 );
		glVertex3f ( 2.286, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2.7432, 0, 0 );
		glVertex3f ( 2.7432, 0, 3.9624 );	
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glVertex3f ( 2.7432, -0.3048, 0 );

	 glEnd();
	glPopMatrix();
	 //right
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 5.0292, 0, 0 );
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glVertex3f ( 4.572, 0, 3.9624 );
		glVertex3f ( 4.572, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 5.0292, -0.3048, 0 );
		glVertex3f ( 5.0292, -0.3048, 3.9624 );	
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glVertex3f ( 4.572, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 4.572, 0, 0 );
		glVertex3f ( 4.572, 0, 3.9624 );	
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glVertex3f ( 4.572, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 5.0292, 0, 0 );
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glVertex3f ( 5.0292, -0.3048, 3.9624 );
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
		glVertex3f ( 7.3152, 0, 5.4864 );
		glVertex3f ( 0, 0, 5.4864 );	
		glVertex3f ( 0, 0, 3.9624 );
		glVertex3f ( 7.3152, 0, 3.9624 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, -0.3048, 5.4864 );
		glVertex3f ( 0, -0.3048, 5.4864 );	
		glVertex3f ( 0, -0.3048, 3.9624 );
		glVertex3f ( 7.3152, -0.3048, 3.9624 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, 0, 3.9624 );
		glVertex3f ( 0, 0, 3.9624 );	
		glVertex3f ( 0, -0.3048, 3.9624 );
		glVertex3f ( 7.3152, -0.3048, 3.9624 );

	 glEnd();
	glPopMatrix();
       //frontwall leftindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, 0, 0 );
		glVertex3f ( 0, 0, 3.9624 );	
		glVertex3f ( 0.6096, 0, 3.9624 );
		glVertex3f ( 0.6096, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0, -0.3048, 0 );
		glVertex3f ( 0, -0.3048, 3.9624 );	
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glVertex3f ( 0.6096, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 0.6096, 0, 0 );
		glVertex3f ( 0.6096, 0, 3.9624 );	
		glVertex3f ( 0.6096, -0.3048, 3.9624 );
		glVertex3f ( 0.6096, -0.3048, 0 );

	 glEnd();
	glPopMatrix();
       //frontwall rightindent
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, 0, 0 );
		glVertex3f ( 7.3152, 0, 3.9624 );	
		glVertex3f ( 6.7056, 0, 3.9624 );
		glVertex3f ( 6.7056, 0, 0 );
	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 7.3152, -0.3048, 0 );
		glVertex3f ( 7.3152, -0.3048, 3.9624 );	
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
		glVertex3f ( 6.7056, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	
	 glBegin ( GL_POLYGON );
		glVertex3f ( 6.7056, 0,       0 );
		glVertex3f ( 6.7056, 0,       3.9624 );	
		glVertex3f ( 6.7056, -0.3048, 3.9624 );
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
		glVertex3f ( 2.286, 0, 0 );
		glVertex3f ( 2.286, 0, 3.9624 );	
		glVertex3f ( 2.7432, 0, 3.9624 );
		glVertex3f ( 2.7432, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2.286, -0.3048, 0 );
		glVertex3f ( 2.286, -0.3048, 3.9624 );	
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glVertex3f ( 2.7432, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2.286, 0, 0 );
		glVertex3f ( 2.286, 0, 3.9624 );	
		glVertex3f ( 2.286, -0.3048, 3.9624 );
		glVertex3f ( 2.286, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 2.7432, 0, 0 );
		glVertex3f ( 2.7432, 0, 3.9624 );	
		glVertex3f ( 2.7432, -0.3048, 3.9624 );
		glVertex3f ( 2.7432, -0.3048, 0 );

	 glEnd();
	glPopMatrix();
	 //right
	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 5.0292, 0, 0 );
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glVertex3f ( 4.572, 0, 3.9624 );
		glVertex3f ( 4.572, 0, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.6, 0.6);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 5.0292, -0.3048, 0 );
		glVertex3f ( 5.0292, -0.3048, 3.9624 );	
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glVertex3f ( 4.572, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 4.572, 0, 0 );
		glVertex3f ( 4.572, 0, 3.9624 );	
		glVertex3f ( 4.572, -0.3048, 3.9624 );
		glVertex3f ( 4.572, -0.3048, 0 );

	 glEnd();
	glPopMatrix();

	glPushMatrix();
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	 glBegin ( GL_POLYGON );
		glVertex3f ( 5.0292, 0, 0 );
		glVertex3f ( 5.0292, 0, 3.9624 );	
		glVertex3f ( 5.0292, -0.3048, 3.9624 );
		glVertex3f ( 5.0292, -0.3048, 0 );

	 glEnd();
	glPopMatrix();
glPopMatrix();

glDisable(GL_DEPTH_TEST);
glDisable(GL_TEXTURE_2D);
///////////////////////////////////////////
//objects inside the level//

//display cases "rough"

   //defining a cube
   struct box faces[6];
   defineBox(&faces[0]);

	//drawing 8 cases in rough location
//left side cubes front to back
	glPushMatrix();
	 glTranslatef(0.55, 2.4675, 0.0);
	 glScalef(0.15, 0.4, 0.6);
	 drawBox(&faces[0]);
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

     for(int i = 0; i < g.golist.size(); i++)
     {
         g.drawBox(&g.golist[i].faces[0], &g.golist[i].collCenter);    // draw faces
         g.drawBounds(&g.golist[i].bounds[0]);                       // draw box collider
     }

     ////////////////////////////////////////////////////
//food court area




}
#endif
