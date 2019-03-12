#ifndef INPUT_CC
#define INPUT_CC

#include "includes.h"
#include "input.h"

extern double centerX, centerY, centerZ;
extern double CAMERA_R, CAMERA_THETA, CAMERA_PHI;

Input::Input() 
{ }

void Input::mouse( int button, int state, int x, int y )
{ 	
	switch (button) 
	{
        	case GLUT_LEFT_BUTTON:
		    	if (state == GLUT_DOWN)
		    	{
				//left click
		    	}
            	break;

        	case GLUT_RIGHT_BUTTON:
		    	if (state == GLUT_DOWN)
		    	{
				//right click
		    	}
            	break;

        	default:
            	break;
    	}
}

void Input::keyboard( unsigned char key, int x, int y )
{ 	
	if ( key == 'q' || key == 'Q') {
		//exit the program
		exit(0);
	}
	else if (key == 'w' || key == 'W') {
		//move up
		CAMERA_THETA -= 1.0;
		if (CAMERA_THETA < 0.0) {
			CAMERA_THETA += 360.0;
		}
		glutPostRedisplay();	
	}
	else if (key == 's' || key == 'S') {
		//move down
		CAMERA_THETA += 1.0;
		if (CAMERA_THETA > 0.0) {
			CAMERA_THETA -= 360.0;
		}
		glutPostRedisplay();	
	}
	else if (key == 'a' || key == 'A') {
		//move left
		CAMERA_PHI -= 1.0;
		if (CAMERA_PHI < 0.0) {
			CAMERA_PHI += 360.0;
		}
		glutPostRedisplay();	
	}
	else if (key == 'd' || key == 'D') {
		//move right
		CAMERA_PHI += 1.0;
		if (CAMERA_PHI > 0.0) {
			CAMERA_PHI -= 360.0;
		}
		glutPostRedisplay();	
		
	}
	else if (key == '+') {
		//move forward
		CAMERA_R -= 0.5;
		if (CAMERA_R <= 0.0) {
			CAMERA_R = 0.0;
		}
		glutPostRedisplay();
	}
	else if (key == '-') {
		//move backward
		CAMERA_R += 0.5;
		if (CAMERA_R >= 30.0) {
			CAMERA_R = 30.0;
		}
	}	
}

void Input::specialInput(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			//pan up
			centerZ += 1.0;
			glutPostRedisplay();
		break;
			
		case GLUT_KEY_DOWN:
			//pan down
			centerZ -= 1.0;
			glutPostRedisplay();
		break;

		case GLUT_KEY_RIGHT:
			//pan right
			if (centerX > 30.0 && centerY > -30.0) { 
				//centerX += 1.0;
				centerY -= 1.0;
				
			}
			else if (centerY > 30.0) {
				centerX += 1.0;
				//centerY -= 1.0;
			}	
			else if (centerY < -30.0) {
				centerY += 1.0;
				centerX -= 1.0;
			}	
			else{
			//else if (centerY > 0.0) {
			//	centerY += 1.0;
			//	centerX -= 0.0;
			//	break;
			//}	
				
			centerY += 1.0;
			centerX -= 1.0;
			//if (centerX < -30.0) {
			//	centerY = -centerY;
			//}
			}	
			glutPostRedisplay();
		break;
			
		case GLUT_KEY_LEFT:
			//pan left
			//centerY += 1.0;
			centerX += 1.0;
			glutPostRedisplay();
		break;
		
		case GLUT_KEY_PAGE_UP:
			//move forward
			CAMERA_R -= 0.5;
			if (CAMERA_R <= 0.0) {
				CAMERA_R = 0.0;
			}
			glutPostRedisplay();
		break;

		case GLUT_KEY_PAGE_DOWN:
			//move backward
			CAMERA_R += 0.5;
			if (CAMERA_R >= 30.0) {
				CAMERA_R = 30.0;
			}
		break;	
	}
}

#endif
