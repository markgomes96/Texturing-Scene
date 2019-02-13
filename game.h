#ifndef GAME_H
#define GAME_H

#include "includes.h"
#include "input.h"
#include "physobj.h"
#include "testobj.h"

/*
* Handles all functions of the game
*/

class Game 
{
private:

public:
	//Variables related to Game class
	Input input;
	TestObj floor;
	TestObj cube;
	
	//Constructor
	Game();

	//Game functions
	void init();
	void update();
	void render();

	//Input relay functions
	void mouse( int button, int state, int x, int y );
	void keyboard( unsigned char key, int x, int y );
	void specialInput(int key, int x, int y);

	//Physics testing functions
	void drawBox( struct box *face, vect3 *position );
};

#endif
