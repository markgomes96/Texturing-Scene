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
	vector<object>  SceneObjects; 

	TestObj floor;				// phys obj test vars
	TestObj cube;
	TestObj cube2;

	// Constructor
	Game();

	// Game functions
	void init();
	void update();
	void character();
	void minimap();
	void HUD();
	void render();
	void createProjectile( double, double, double, double, double, double, double ); 
	void createEye( double, double, double, double, double, double, double ); 


	// Input relay functions
	void mouse( int button, int state, int x, int y );
	void keyboard( unsigned char key, int x, int y );
	void keyup( unsigned char key, int x, int y );

	void specialInput(int key, int x, int y);
	void passiveMouseMovement(int x, int y);
	void mouseMovement(int x, int y);

	// Phys-Time functions
	void glutLockFrameRate(float desiredFrameRate);

	// Physics testing functions
	void drawBox( struct box *face, vertex *position );
	void drawBounds( vertex *bounds );
};

#endif
