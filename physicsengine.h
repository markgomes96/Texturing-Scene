#ifndef PHYSICSENGINE_H
#define PHYSOCSENGINE_H

#include "includes.h"
#include "testobj.h"

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
	void updateObjects(vector<TestObj> &golist);	//move objects based on velocity/acceleration
	void updatePosition(TestObj &go);
	void checkCollision(TestObj &go1, TestObj &go2);

	// Vector utiltiy functions
	vect3 vectUnit(vect3 a);
	vect3 vectDist(vect3 a, vect3 b);
	vect3 vectCross(vect3 a, vect3 b);
	float vectMagn(vect3 a);
	vect3 vectAdd(vect3 a, vect3 b);
	vect3 vectMult(vect3 a, float scalar);
};

#endif