#ifndef INPUT_CC
#define INPUT_CC

#include "includes.h"
#include "input.h"

extern double centerX, centerY, centerZ;
extern double CAMERA_R, CAMERA_THETA, CAMERA_PHI;
extern double prev_mouse_x, prev_mouse_y;
extern double mouse_dx, mouse_dy;
extern double x_rotat, y_rotat;
extern float sensitivity;
extern glm::vec3 cameraFront, cameraTarget, cameraPos, up, cameraDirection;
extern bool camera;

Input::Input() 
{ }

void Input::passiveMouseMovement(int x, int y){
	
	y = 800 - y; //this needs to be dynamic eventually

	//calculate change in x and y
	mouse_dx = x - prev_mouse_x; 
	mouse_dy = y- prev_mouse_y;

	//reset prev mouse x and y
	prev_mouse_x = x;
	prev_mouse_y = y;


	
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
	if(key == 'g'){
		camera = true;
	}
	if(key == 'r'){
		camera = false;
	}
	if(key == 'w'){
		cameraDirection = cameraTarget - cameraPos;
		cameraDirection = glm::normalize(cameraDirection);
		cameraPos.x = cameraPos.x + sensitivity*cameraDirection.x;
		cameraPos.y = cameraPos.y + sensitivity*cameraDirection.y;
		cameraTarget.x = cameraTarget.x + sensitivity*cameraDirection.x;
		cameraTarget.y = cameraTarget.y + sensitivity*cameraDirection.y;
	
	}
	if(key == 's'){
		cameraDirection = cameraTarget - cameraPos;
		cameraDirection = glm::normalize(cameraDirection);
		cameraPos.x = cameraPos.x - sensitivity*cameraDirection.x;
		cameraPos.y = cameraPos.y - sensitivity*cameraDirection.y;
		cameraTarget.x = cameraTarget.x - sensitivity*cameraDirection.x;
		cameraTarget.y = cameraTarget.y - sensitivity*cameraDirection.y;
	}
	if(key == 'a'){
		 cameraDirection = cameraTarget - cameraPos;
		 cameraDirection = glm::normalize(cameraDirection);
		 cameraPos = cameraPos - glm::normalize(glm::cross(cameraDirection, up)) * sensitivity;
		 cameraTarget = cameraTarget - glm::normalize(glm::cross(cameraDirection, up)) * sensitivity;
	}
	if(key == 'd'){
		cameraDirection = cameraTarget - cameraPos;
		cameraDirection = glm::normalize(cameraDirection);
		cameraPos = cameraPos + glm::normalize(glm::cross(cameraDirection, up)) * sensitivity;
		cameraTarget = cameraTarget + glm::normalize(glm::cross(cameraDirection, up)) * sensitivity;
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
