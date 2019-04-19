#ifndef INPUT_CC
#define INPUT_CC

#include "includes.h"
#include "game.h"
#include "input.h"

extern double centerX, centerY, centerZ;
extern double CAMERA_R, CAMERA_THETA, CAMERA_PHI;
extern double prev_mouse_x, prev_mouse_y;
extern double mouse_dx, mouse_dy;
extern double x_rotat, y_rotat;
extern float sensitivity;
extern glm::vec3 cameraFront, cameraTarget, cameraPos, up, cameraDirection; 
extern bool camera;
extern int jump;
extern Game g;
extern enum key_state {NOTPUSHED,PUSHED} keyarr[127];
extern const int WINDOW_MAX_X, WINDOW_MAX_Y;
extern bool first_mouse;

Input::Input()
{ }

void Input::passiveMouseMovement(int x, int y){
	float sensitivity = 0.2f;


	y = WINDOW_MAX_Y  - y; //this needs to be dynamic eventually

	if(first_mouse){
		prev_mouse_x = x;
		prev_mouse_y = y;
		first_mouse = false;
	}

	//calculate change in x and y
	mouse_dx = x - prev_mouse_x; 
	mouse_dy = y- prev_mouse_y;

	cout << x << " " << y << endl;

	//reset prev mouse x and y
	prev_mouse_x = x;
	prev_mouse_y = y;

	mouse_dx = mouse_dx * sensitivity;
	mouse_dy = mouse_dy * sensitivity;

	//cout << mouse_dx << " " << mouse_dy << endl;

	static float yaw, pitch;
	yaw = yaw + mouse_dx;
	pitch = pitch + mouse_dy;

	cout << "yaw: " << yaw << endl;
	cout << "pitch: " << pitch << endl;
	
	if(pitch > 89.0){
		pitch = 89.0;
	}
	if(pitch < -89.0){
		pitch = 89.0;
	}

	float cosp = cos(glm::radians(pitch));
	float sinp = sin(glm::radians(pitch));
	float cosy = cos(glm::radians(yaw));
	float siny = sin(glm::radians(yaw));
	float nsinp = -sin(glm::radians(pitch));
	float nsiny = -sin(glm::radians(yaw));

	float tmpx, tmpy, tmpz;
	//calculate new camera target
	cameraDirection = cameraTarget - cameraPos;
	cout << cameraDirection.x << " " << cameraDirection.y << " " << cameraDirection.z << endl;
	tmpx = cameraDirection.x*cosp + cameraDirection.z*sinp + cameraDirection.x*cosy + cameraDirection.y*nsiny;
	tmpy = cameraDirection.y + cameraDirection.x*siny + cameraDirection.y * cosy;
	tmpz = cameraDirection.x * nsinp + cameraDirection.z * cosp + cameraDirection.z;

	cameraTarget.x = tmpx;
	cameraTarget.y = tmpy;
	cameraTarget.z = tmpz;
	cout << cameraTarget.x << " " << cameraTarget.y << endl; 

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
		exit(0);
		keyarr['q'] = PUSHED;
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

   	if (( key == 't' ) || (key == 'T')){
		//Throw Object
		keyarr['t'] = PUSHED;
	}
	if (( key == 'z' ) || (key == 'Z')){
		//Make object smaller
		keyarr['z'] = PUSHED;
	}
	if (( key == 'x' ) || (key == 'X')){
		//Make object bigger
		keyarr['x'] = PUSHED;
	}
	if ( key == 27 ){
		//Exit gracefully
		glutLeaveGameMode();
		exit(0);
	}
#ifdef DEV
    if ( key == 'e' || key == 'E'){
        // Create a box where the eye is
   		keyarr['e'] = PUSHED;
    }
#endif
    if (key == 'j' || key == 'J'){
   		keyarr['j'] = PUSHED;
       }
}

void Input::keyup( unsigned char key, int x, int y )
{
	if ( key == 'q' || key == 'Q') {
		//exit the program
		keyarr['q'] = NOTPUSHED;
	}
   	if (( key == 't' ) || (key == 'T')){
		//Throw Object
		keyarr['t'] = NOTPUSHED;
	}
	if (( key == 'z' ) || (key == 'Z')){
		//Make object smaller
		keyarr['z'] = NOTPUSHED;
	}
	if (( key == 'x' ) || (key == 'X')){
		//Make object bigger
		keyarr['x'] = NOTPUSHED;
	}
#ifdef DEV
    if ( key == 'e' || key == 'E'){
        // Create a box where the eye is
   		keyarr['e'] = NOTPUSHED;
    }
#endif
    if (key == 'j' || key == 'J'){
   		keyarr['j'] = NOTPUSHED;
       }
}
void Input::specialInput(int key, int x, int y)
{

}

#endif
