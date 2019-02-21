#ifndef PHYSICSENGINE_CC
#define PHYSICSENGINE_CC

#include "includes.h"
#include "physicsengine.h"

PhysicsEngine::PhysicsEngine() 
{ }

void PhysicsEngine::updateObjects(vector<PhysObj> objlist)
{
	//cout << objlist[0].collCenter.z << endl;

	//***Need fixed time intervals -> fixed frame rate or calc deltatimestep for current framerate

	//Update collision center in each object after everything
}

#endif
