#ifndef INPUT_CC
#define INPUT_CC

#include "includes.h"
#include "game.h"
#include "input.h"

extern double prev_mouse_x, prev_mouse_y;
extern double mouse_dx, mouse_dy;
extern double x_rotat, y_rotat;
extern double scaleAccZ;
extern float sensitivity;
extern glm::vec3 cameraFront, cameraTarget, cameraPos, up, cameraDirection;
extern bool camera, unhold;
extern int jump, changeAcc;
extern double addAcc[3];
extern Game g;
extern enum key_state {NOTPUSHED,PUSHED} keyarr[127];


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
		keyarr['q'] = PUSHED;
	}
	if( key == 'w' || key == 'Q') {
		keyarr['w'] = PUSHED;
	}
	if( key == 's' || key == 'S') {
		keyarr['s'] = PUSHED;
	}
	if( key == 'a' || key == 'A') {
		keyarr['a'] = PUSHED;
	}
	if( key == 'd' || key == 'D') {
		keyarr['d'] = PUSHED;
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
	if (( key == 'r' ) || (key == 'R')){
		//Reverse gravity
		keyarr['r'] = PUSHED;
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
    if (key == '+'){
        addAcc[changeAcc-1] += 1.0;
    }
    if (key == '-'){
        addAcc[changeAcc-1] -= 1.0;
    }
}

void Input::keyup( unsigned char key, int x, int y )
{
     if ( key == '1'){
        changeAcc = 1;
    }
  if ( key == '2'){
        changeAcc = 2;
    }
  if ( key == '3'){
        changeAcc = 3;
    }
	if ( key == 'q' || key == 'Q') {
		//exit the program
		keyarr['q'] = NOTPUSHED;
	}
	 if (key == 'w' || key == 'W') {
    	//move forward
		keyarr['w'] = NOTPUSHED;
	}
	if (key == 's' || key == 'S') {
		keyarr['s'] = NOTPUSHED;
	}
	if (key == 'a' || key == 'A') {
		//move left
		keyarr['a'] = NOTPUSHED;
	}
    if (key == 'd' || key == 'D') {
		//move right
		keyarr['d'] = NOTPUSHED;
	}
   	if (( key == 't' ) || (key == 'T')){ 
		//Throw Object 
		keyarr['t'] = NOTPUSHED;
		unhold = true;
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
	if ((key == 'r' ) || (key == 'R')){
		//reset Acceleration
		keyarr['r'] = NOTPUSHED;
		addAcc[0] = 0.0;
		addAcc[1] = 0.0; 
	    addAcc[2] = 1.0;
	 //printf("%f \n", scaleAccZ);
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
