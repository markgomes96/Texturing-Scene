#ifndef INPUT_H
#define INPUT_H

#include "includes.h"
#include "menu.h"

class Input 
{
private:

public:
	
	//Variables related to Input class
	vect3 mousePosition;
	
	//Constructor
	Input();

	//Game functions
	void mouse( int button, int state, int x, int y );
	void passiveMouseMovement(int x, int y);
	void mouseMovement(int x, int y);
	void keyboard( unsigned char key, int x, int y );
	void keyup( unsigned char key, int x, int y );

	void specialInput(int key, int x, int y);
};

#endif
