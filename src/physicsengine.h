#ifndef PHYSICSENGINE_H
#define PHYSOCSENGINE_H

#include "includes.h"
#include "gameobj.h"

/*
* Handles all phsical interactions of PhysObjs
* 1 Meter = 1 Unit
* Time Step = (1.0 / frameRate) seconds
*/

class PhysicsEngine
{
private:

public:
	// Variables
	float frameRate;
	float timeStep;

	// Constructors
	PhysicsEngine();
	PhysicsEngine(float fr);

	// Game functions
	void updateObjects(vector<GameObj> &golist);	//move objects based on velocity/acceleration
    void updateObjects(vector<GameObj> &golist, vector<GameObj> &tarList);	
	void updatePosition(GameObj &go);
	void checkCollision(GameObj &go1, GameObj &go2);
	bool positionTest(GameObj a, GameObj b);
	bool sphereCollsTest(GameObj a, GameObj b);

	// Vector utiltiy functions
	vect3 vectUnit(vect3 a);
	vect3 vectDist(vect3 a, vect3 b);
	vect3 vectDist(vertex a, vertex b);
	vect3 vectCross(vect3 a, vect3 b);
	float vectMagn(vect3 a);
	vect3 vectAdd(vect3 a, vect3 b);
	vect3 vectMult(vect3 a, float scalar);
};

#endif
