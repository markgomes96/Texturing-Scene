#ifndef INPUT_CC
#define INPUT_CC

#include "includes.h"

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
	if ( key == 'q' || key == 'Q') 		//exit the program
	{
		exit(0);
	}
}

void Input::specialInput(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			rotX--;
		break;
			
		case GLUT_KEY_DOWN:
			rotX++;
		break;

		case GLUT_KEY_RIGHT:
			rotZ++;
		break;
			
		case GLUT_KEY_LEFT:
			rotZ--;
		break;
	}
}

#endif
