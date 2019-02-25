#ifndef PHYSICSENGINE_CC
#define PHYSICSENGINE_CC

#include "includes.h"
#include "physicsengine.h"

PhysicsEngine::PhysicsEngine() 
{ }

PhysicsEngine::PhysicsEngine(float fr) 
{ 
	frameRate = fr;
	timeStep = (1.0 / frameRate);
}

void PhysicsEngine::updateObjects(vector<PhysObj> &objlist)
{
	//cout << objlist[0].collCenter.z << endl;
	//Update collision center in each object after everything

	for(int i = 0; i < objlist.size(); i++)
	{
		updatePostion(objlist[i]);
	}
}

void PhysicsEngine::updatePosition(PhysObj &obj)
{
	obj.velocity = vectAdd(obj.velocity, vectMult(obj.acceleration, timeStep));
	obj.collCenter.x += obj.velocity.x;	
	obj.collCenter.y += obj.velocity.y;	
	obj.collCenter.z += obj.velocity.z;
	
	obj.updatePhysics();
}

// Vector utility functions
vect3 PhysicsEngine::vectUnit(vect3 a)
{
	float magn = vectMagn(a);
	return vect3( (a.x/magn) , (a.y/magn) , (a.z/magn) );
}

vect3 PhysicsEngine::vectDist(vect3 a, vect3 b)
{
	return vect3(b.x - a.x, b.y - a.y, b.z - a.z);
}

vect3 PhysicsEngine::vectCross(vect3 a, vect3 b)
{
	return vect3( (a.y * b.z) - (b.y * a.z), 
				  (b.x * a.z) - (a.x * b.z),
			      (a.x * b.y) - (b.x * a.y));
}

float PhysicsEngine::vectMagn(vect3 a)
{
	return sqrt( (a.x*a.x) + (a.y*a.y) + (a.z*a.z) );
}

vect3 PhysicsEngine::vectAdd(vect3 a, vect3 b)
{
	return vect3(a.x + b.x, a.y + b.y, a.z + b.z);
}

vect3 PhysicsEngine::vectMult(vect3 a, float scalar)
{
	return vect3(a.x * scalar, a.y * scalar, a.z * scalar);
}

#endif
