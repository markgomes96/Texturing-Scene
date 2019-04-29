#ifndef LEVELS
#define LEVELS

#include "includes.h"
#include "game.h"
#include "globals.h"
#include "structs.h"
#include "prototypes.h"

extern double scaleObX, scaleObY, scaleObZ, scaleAccZ ,power ;
extern const int WINDOW_MAX_X, WINDOW_MAX_Y;
extern double prev_mouse_x, prev_mouse_y;
extern double mouse_dx, mouse_dy;
extern double x_rotat, y_rotat;
extern float sensitivity;
extern glm::vec3 cameraFront, cameraTarget, cameraPos, up, cameraDirection;
extern bool camera, unhold;
extern int jump, counter;
extern Game g;
extern key_state keyarr[127];
extern bool left_mouse_down, left_mouse_released;


void showMinimap(){
    //Function to generate minimap
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glEnable(GL_SCISSOR_TEST);
    glScissor(WINDOW_MAX_X-300, 50, 200, 200);
    glLoadIdentity();
    //gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0 ,0 ,1);
    glMatrixMode(GL_MODELVIEW);

    buildHeritageHall();
    glPopMatrix();

}
void buildDisplay(){

    buildCameraScene();
    buildHeritageHall();
    //g.drawSceneObjects( ); 

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



    if (keyarr['w']){
        // Move forward
        cameraDirection = cameraTarget - cameraPos;
        cameraDirection = glm::normalize(cameraDirection);
        cameraPos.x = cameraPos.x + sensitivity*cameraDirection.x;
        cameraPos.y = cameraPos.y + sensitivity*cameraDirection.y;
        cameraTarget.x = cameraTarget.x + sensitivity*cameraDirection.x;
        cameraTarget.y = cameraTarget.y + sensitivity*cameraDirection.y;
    }

    if (keyarr['s']){
        // Move backward
        cameraDirection = cameraTarget - cameraPos;
        cameraDirection = glm::normalize(cameraDirection);
        cameraPos.x = cameraPos.x - sensitivity*cameraDirection.x;
        cameraPos.y = cameraPos.y - sensitivity*cameraDirection.y;
        cameraTarget.x = cameraTarget.x - sensitivity*cameraDirection.x;
        cameraTarget.y = cameraTarget.y - sensitivity*cameraDirection.y;
    }
    if (keyarr['a']){
        // Move left
        cameraDirection = cameraTarget - cameraPos;
        cameraDirection = glm::normalize(cameraDirection);
        cameraPos = cameraPos - glm::normalize(glm::cross(cameraDirection, up)) * sensitivity;
        cameraTarget = cameraTarget - glm::normalize(glm::cross(cameraDirection, up)) * sensitivity;
    }

    if (keyarr['d']){
        cameraDirection = cameraTarget - cameraPos;
        cameraDirection = glm::normalize(cameraDirection);
        cameraPos = cameraPos + glm::normalize(glm::cross(cameraDirection, up)) * sensitivity;
        cameraTarget = cameraTarget + glm::normalize(glm::cross(cameraDirection, up)) * sensitivity;
    }

    if ( keyarr['z']){
        scaleObX *= 1.1;
        scaleObY *= 1.1;
        scaleObZ *= 1.1;
    }
    if ( keyarr['x']){
        scaleObX /= 1.1;
        scaleObY /= 1.1;
        scaleObZ /= 1.1;
    }

	//throwing with mouse
	if(left_mouse_down){
        //cout << "increasing power" << endl;
        power *=1.01;
    }
    if(left_mouse_released){
        g.createProjectile((double) cameraPos.x,
                           (double) cameraPos.y,
                           (double) cameraPos.z,
                           1, scaleObX, scaleObY, scaleObZ);
        //reset power
        power = 1.0;
		left_mouse_released = false;
    }


    /*if ( keyarr['t']){
        //Throw Object
        power *= 1.01;
    } else if (unhold){
        g.createProjectile( (double) cameraPos.x, 
                (double) cameraPos.y, 
                (double) cameraPos.z, 
                1, scaleObX, scaleObY, scaleObZ);
        unhold = false;
        power = 1.0;
    }*/

#ifdef DEV
    if ( keyarr['e']){
        // Create a box where the eye is
    /*    g.createEye((double) cameraTarget.x, // + cameraFront.x,
                (double) cameraTarget.y, // + cameraFront.y,
                (double) cameraTarget.z, // + cameraFront.z,
                1, 0.2, 0.2, 0.2);
*/
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
    int jumpTime = 20; // The higher it is the longer the jump is
    double jumpChange = 10.0 / (double) jumpTime;
    if (jump != 0){
        if (jump == jumpTime){
            jump = -1;
        } else if (jump > 0){
            cameraPos.z += jumpChange * sensitivity;
        //    cameraTarget.z += jumpChange * sensitivity;
            jump +=1;
        } else if ((jump < 0) && (jump > -20)){
            cameraPos.z -= jumpChange * sensitivity;
      //      cameraTarget.z += jumpChange * sensitivity;
            jump -= 1;
        } else{
            jump =0;
        }
    }

}
void buildHeritageHall(void){
	GLfloat lightPos1[] = {3.5, 5.0, 5.0, 0.0};
	GLfloat lightColor[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat ambient[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat spec[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat diff[] = {0.8, 0.8, 0.8, 1.0};
	GLfloat on[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat direction[] = {0.0, 0.0, -1.0};
	GLfloat emiss[] = {0.0, 0.0, 0., 1.0};
	//GLfloat dir[] = {0.0, 0.0, -1.0};
	//GLfloat spotamb[] = {0.5, 0.5, 0.5, 1.0};
	//GLfloat spotdiff[] = {0.0, 0.5, 0.0, 1.0};
	//GLfloat spotspec[] = {0.0, 0.5, 0.0, 1.0};

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 

    gluLookAt( (double)cameraPos.x, (double)cameraPos.y, (double)cameraPos.z,
            (double) cameraTarget.x, // + cameraFront.x,
            (double) cameraTarget.y, // + cameraFront.y,
            (double) cameraTarget.z, // + cameraFront.z,
            (double) up.x, (double) up.y, (double) up.z); 	// Up */
   
    if (counter == 10){
        printf("You won you sneaky bastard\n");
        exit(0);
    }
    if (destroy){
        g.createTarget(randomize(MIN_X, MAX_X), // + cameraFront.x,
                randomize(MIN_Y, MAX_Y), // + cameraFront.y,
                randomize(MIN_Z, MAX_Z), // + cameraFront.z,
                1, 0.2, 0.001, 0.2);
        destroy = false;
    }

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_NORMALIZE);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
	glEnable(GL_COLOR_MATERIAL);
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.0);
	//glMaterialfv(GL_FRONT and GL_BACK, GL_EMISSION, emiss);
	

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, on);
	glLightfv(GL_LIGHT0, GL_SPECULAR, on);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.2);
	glEnable(GL_LIGHT0);
	glDisable( GL_LIGHTING ); 
	glEnable( GL_COLOR_MATERIAL ); 

    // Draw objectiles directly after setting the camera 
    // ****** WARNING ******
    // Camera and objectile must go hand in hand. Please DO NOT move this. 
    for(int i = 0; i < g.obList.size(); i++)
    {
        g.drawObject(g.obList[i]);    
    }
    
    for(int i = 0; i < g.tarList.size(); i++)
    {
        g.drawObject(g.tarList[i]);    
    }


	//draw heritage hall
	buildHH();
 	
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(3.5, 5.0, 5.0);
	glColor3f(1.0, 1.0, 0.0);
	glutWireSphere(1.5, 10.0, 10.0);
	glPopMatrix();
	glEnable(GL_LIGHTING);
	



    ////////////////////////////////////////////////////
    //food court area




}
#endif
