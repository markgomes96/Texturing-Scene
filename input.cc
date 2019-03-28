#ifndef INPUT_CC
#define INPUT_CC

#include "includes.h"
#include "input.h"

extern double centerX, centerY, centerZ;
extern double CAMERA_R, CAMERA_THETA, CAMERA_PHI;
extern double prev_mouse_x, prev_mouse_y;
extern double mouse_dx, mouse_dy;
extern double x_rotat, y_rotat;
extern double sensitivity;
extern glm::vec3 cameraFront;

Input::Input() 
{ }

void Input::passiveMouseMovement(int x, int y){
	//cout << "mouse moved while no buttons were pressed" << endl;
	//cout << "mouse at " << x << " " << y << endl;

	y = 800 - y; //this needs to be dynamic eventually

	//calculate change in x and y
	mouse_dx = x - prev_mouse_x; 
	mouse_dy = y- prev_mouse_y;

	//reset prev mouse x and y
	prev_mouse_x = x;
	prev_mouse_y = y;

	//calculate rotation angle for x and y
    x_rotat = x_rotat + mouse_dx*sensitivity;
	y_rotat = y_rotat + mouse_dy*sensitivity;

	cout << x_rotat << " " << y_rotat << endl;	


	//restrict y
	if(y_rotat > 89.0){
		y_rotat = 89.0;
	}
	if(y_rotat < -89.0){
		y_rotat = -89.0;
	}

	glm::vec3 front;
    front.x = cos(glm::radians((float)y_rotat)) * cos(glm::radians((float)x_rotat));
    front.y = sin(glm::radians((float)y_rotat));
    front.z = cos(glm::radians((float)y_rotat))  * sin(glm::radians((float) x_rotat));
    cameraFront = glm::normalize(front); 


	glutPostRedisplay();
}

void Input::mouseMovement(int x, int y){
	//cout << "mouse moved while buttons were pressed" << endl;
}

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
/*	else if (key == 'w' || key == 'W') {
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
		
	
	} */
	else if (key == 'w') {
		//move forward
		CAMERA_R -= 0.5;
		if (CAMERA_R <= 0.0) {
			CAMERA_R = 0.0;
		}
		glutPostRedisplay();
	}
	else if (key == 's') {
		//move backward
		CAMERA_R += 0.5;
		if (CAMERA_R >= 30.0) {
			CAMERA_R = 30.0;
		}
	}	
}

void Input::specialInput(int key, int x, int y)
{
/*	switch(key)
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
				centerY -= 1.0;
				
			}
			else if (centerY > 30.0) {
				centerX += 1.0;
			}	
			else if (centerY < -30.0) {
				centerY += 1.0;
				centerX -= 1.0;
			}	
			else {		
				centerY += 1.0;
				centerX -= 1.0;
			}	
			glutPostRedisplay();
		break;
			
		case GLUT_KEY_LEFT:
			//pan left
			//centerX += 1.0;
			if (centerX > 30.0 && centerY < 30.0) { 
				centerY += 1.0;
				
			}
			else if (centerX < -30.0 && centerY > 30.0) {
				centerY -= 1.0;
				centerX += 1.0;
			}	
			else if (centerY > 30.0) {
				centerX -= 1.0;
			}		
			else {		
				centerY -= 1.0;
				centerX += 1.0;
			}

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
	}*/
}

#endif
