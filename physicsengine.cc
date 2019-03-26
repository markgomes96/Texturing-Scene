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
	// { collz, colly, collx }
	// -1 -> collision in negative direction / 1 -> collision in positive direction
	int colls[] = {0, 0, 0};
	float overlap = 0.0;

	// ***Collisions in Z-axis***
	if(go1.wzm[0] < go2.wzm[1] && go1.wzm[0] > go2.wzm[0])			// bottom collision
	{	
		colls[0] = -1;
	}
	else if(go1.wzm[1] < go2.wzm[1] && go1.wzm[1] > go2.wzm[0])		// top collision
	{
		colls[0] = 1;
	}

	// ***Collisions in Y-axis***
	if(go1.wym[0] < go2.wym[1] && go1.wym[0] > go2.wym[0])			// left collision
	{
		colls[1] = -1;
	}
	else if(go1.wym[1] < go2.wym[1] && go1.wym[1] > go2.wym[0])		// right collision
	{
		colls[1] = 1;
	}

	// ***Collisions in X-axis***
	if(go1.wxm[0] < go2.wxm[1] && go1.wxm[0] > go2.wxm[0])			// back collision
	{
		colls[2] = -1;
	}
	else if(go1.wxm[1] < go2.wxm[1] && go1.wxm[1] > go2.wxm[0])		// front collision
	{
		colls[2] = 1;
	}

	// collision only occurs when collide in all 3 dimensions
	if(colls[0] != 0 && colls[1] != 0 && colls[2] != 0) 
	{
		/*
		* Handle collisions based on velocity vector
		* reverse velocity vector, convert to unit, scale by distance to collision point
		* apply (collision vector) to colliding objects position
		*/

		overlap = go2.wzm[1] - go1.wzm[0];		// z adjustment
		go1.collCenter.z += (-1) * colls[0] * abs(overlap);

		/*
		overlap = go2.wym[1] - go1.wym[0];		// y adjustment
		go1.collCenter.y += (-1) * colls[1] * abs(overlap);
	
		overlap = go2.wxm[1] - go1.wxm[0];		// x adjustment
		go1.collCenter.x += (-1) * colls[2] * abs(overlap);
		*/

		go1.velocity = vect3(0.0, 0.0, 0.0);	// reset velocity
		go1.updatePhysics();					// update go1 box collider
	}
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
