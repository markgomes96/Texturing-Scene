#ifndef PHYSICSENGINE_CC
#define PHYSICSENGINE_CC

#include "includes.h"
#include "physicsengine.h"

/*
 * --Possible Bugs--
 * -Object moves so fast it passes colliding object completly
 * -Time scale for the phyics seems too fast?
 */

PhysicsEngine::PhysicsEngine() 
{ }

PhysicsEngine::PhysicsEngine(float fr) 
{ 
	frameRate = fr;
	timeStep = (1.0 / frameRate);
}

void PhysicsEngine::updateObjects(vector<TestObj> &golist)
{
	// update position of every object
	for(int i = 0; i < golist.size(); i++)
	{
		if(!golist[i].isStatic)
		{
			updatePosition(golist[i]);
		}
	}

	//***Add in distance condition to reduce calcs?***
	// check for collisions
	for(int i = 0; i < golist.size(); i++)
	{
		for(int j = 0; j < golist.size(); j++)
		{
			if(!golist[i].isStatic)
				checkCollision(golist[i], golist[j]);
		}
	}
}

void PhysicsEngine::checkCollision(TestObj &go1, TestObj &go2)
{
	float overlap = 0.0;

	// ***Collisions in Z-axis***
	if(go1.wzm[0] < go2.wzm[1] && go1.wzm[0] > go2.wzm[0])		// bottom collision
	{
		go1.velocity = vect3(0.0, 0.0, 0.0);		//reset velocity
		overlap = go2.wzm[1] - go1.wzm[0];			//move go1 back to bounds of go2
		go1.collCenter.z += overlap;
		go1.updatePhysics();						//update go1 box collider
	}
	else if(go1.wzm[1] < go2.wzm[1] && go1.wzm[1] > go2.wzm[0])		//top collision
	{
		go1.velocity = vect3(0.0, 0.0, 0.0);		// reset velocity
		overlap = go1.wzm[1] - go2.wzm[0];			// move go1 back to bounds of go2
		go1.collCenter.z -= overlap;
		go1.updatePhysics();						//update go box collider
	}

	// ***Collisions in Y-axis***

	// ***Collisions in X-axis***

}

void PhysicsEngine::updatePosition(TestObj &go)
{
	// update velocity with acceleration
	go.velocity = vectAdd(go.velocity, vectMult(go.acceleration, timeStep));

	// update position with velocity
	go.collCenter.x += go.velocity.x;	
	go.collCenter.y += go.velocity.y;	
	go.collCenter.z += go.velocity.z;

	// update object box collider
	go.updatePhysics();
}

// ***Vector utility functions***
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
