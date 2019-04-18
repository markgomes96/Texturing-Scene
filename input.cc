#ifndef INPUT_CC
#define INPUT_CC

#include "includes.h"
#include "game.h"
#include "input.h"

extern double centerX, centerY, centerZ;
extern double CAMERA_R, CAMERA_THETA, CAMERA_PHI;
extern int jump;
extern Game g;
extern enum key_state {NOTPUSHED,PUSHED} keyarr[127];

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
		keyarr['q'] = PUSHED;
	}
    if (key == 'w' || key == 'W') {
    	//move forward
		keyarr['w'] = PUSHED;
	}
	if (key == 's' || key == 'S') {
		keyarr['s'] = PUSHED;
	}
	if (key == 'a' || key == 'A') {
		//move left
		keyarr['a'] = PUSHED;
	}
    if (key == 'd' || key == 'D') {
		//move right
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
	    #ifdef DEV
		case GLUT_KEY_PAGE_UP:
   		//move up
		CAMERA_THETA -= 1.0;
		if (CAMERA_THETA < 0.0) {
			CAMERA_THETA += 360.0;
		}
		glutPostRedisplay();
		break;
		case GLUT_KEY_PAGE_DOWN:
				//move down
		CAMERA_THETA += 1.0;
		if (CAMERA_THETA > 0.0) {
			CAMERA_THETA -= 360.0;
		}
		glutPostRedisplay();
		break;
        #endif
	}
}

#endif
