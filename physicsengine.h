#ifndef PHYSICSENGINE_H
#define PHYSOCSENGINE_H

#include "includes.h"
#include "physobj.h"

/*
* Handles all phsical interactions of PhysObjs
* 1 Meter = 1 Unit
* Time Step = 0.01 seconds
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
	void updateObjects(vector<PhysObj> &objList);	//move objects based on velocity/acceleration
	void updatePosition(PhysObj &obj);
	//void checkCollisions();		//check new positions for collisions

	// Vector utiltiy functions
	vect3 vectUnit(vect3 a);
	vect3 vectDist(vect3 a, vect3 b);
	vect3 vectCross(vect3 a, vect3 b);
	float vectMagn(vect3 a);
	vect3 vectAdd(vect3 a, vect3 b);
	vect3 vectMult(vect3 a, float scalar);
};

#endif
