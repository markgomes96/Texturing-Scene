#ifndef GAME_H
#define GAME_H

#include "includes.h"
#include "input.h"

class Game 
{
private:

public:
	//Variables related to Game class
	Input input;
	
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
};

#endif
