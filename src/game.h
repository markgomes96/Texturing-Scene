#ifndef GAME_H
#define GAME_H

#include "includes.h"
#include "input.h"
#include "physobj.h"
#include "gameobj.h"
#include "physicsengine.h"

/*
* Handles all functions of the game
*/

class Game {
private:

public:
	// Variables related to Game class
	Input input;
	PhysicsEngine physEng;

	float frameRate;			// phys-time vars
	vector<GameObj> obList;		// Objectile list
    vector<GameObj> tarList;    // Target list	
	vector<object>  SceneObjects; 

	GameObj floor;				// phys obj test vars
	GameObj cube;
	GameObj cube2;

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
	void createTarget( double, double, double, double, double, double, double );
	void createEye( double, double, double, double, double, double, double ); 

	// object rendering functions
	void drawObject(GameObj go);
	void drawFreeForm(vector<polygon> polygons, vertex position);
	void drawCube(struct box *face, vertex *position);
	void drawBounds( vertex *bounds );

	// Input relay functions
	void mouse( int button, int state, int x, int y );
	void keyboard( unsigned char key, int x, int y );
	void keyup( unsigned char key, int x, int y );

	void specialInput(int key, int x, int y);
	void passiveMouseMovement(int x, int y);
	void mouseMovement(int x, int y);

	// Phys-Time functions
	void glutLockFrameRate(float desiredFrameRate);
};

float randomize(float LO, float HI);
#endif
