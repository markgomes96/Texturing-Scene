#ifndef GAME_H
#define GAME_H

#include "includes.h"
#include "input.h"
#include "physobj.h"
#include "testobj.h"
#include "physicsengine.h"

/*
* Handles all functions of the game
*/

class Game
{
private:

public:
	// Variables related to Game class
	Input input;
	PhysicsEngine physEng;

	float frameRate;			// phys-time vars
	vector<TestObj> golist;		// game object list

	TestObj floor;				// phys obj test vars
	TestObj cube;
<<<<<<< HEAD
	TestObj cube2;
=======
>>>>>>> master

	// Constructor
	Game();

	// Game functions
	void init();
	void update();
	void character();
	void minimap();
	void HUD();
	void render();


	// Input relay functions
	void mouse( int button, int state, int x, int y );
	void keyboard( unsigned char key, int x, int y );
	void specialInput(int key, int x, int y);

	// Phys-Time functions
	void glutLockFrameRate(float desiredFrameRate);

	// Physics testing functions
	void drawBox( struct box *face, vertex *position );
	void drawBounds( vertex *bounds );
};

#endif
