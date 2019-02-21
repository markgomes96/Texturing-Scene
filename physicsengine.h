#ifndef PHYSICSENGINE_H
#define PHYSOCSENGINE_H

#include "includes.h"
#include "physobj.h"

/*
* Handles all phsical interactions of PhysObjs
*/

class PhysicsEngine 
{
private:

public:
	//Variables
	
	//Constructor
	PhysicsEngine();

	//Game functions
	void updateObjects(vector<PhysObj> objList);	//move objects based on velocity/acceleration
	//void checkCollisions();		//check new positions for collisions
};

#endif
