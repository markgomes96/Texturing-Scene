#ifndef INPUT_H
#define INPUT_H

#include "includes.h"

class Input 
{
private:

public:
	
	//Variables related to Input class
	vect3d mousePosition;
	
	//Constructor
	Input();

	//Game functions
	void mouse( int button, int state, int x, int y );
	void keyboard( unsigned char key, int x, int y );
	void specialInput(int key, int x, int y);
};

#endif
