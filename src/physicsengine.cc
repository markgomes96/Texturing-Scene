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

void PhysicsEngine::updateObjects(vector<GameObj> &golist)
{
	// update position of every object
	for(int i = 0; i < golist.size(); i++)
	{
		if(!golist[i].isStatic)
		{
			updatePosition(golist[i]);
		}
	}

	// check for collisions
	for(int i = 0; i < golist.size(); i++)
	{
		for(int j = 0; j < golist.size(); j++)
		{
			if(i != j)		// don't check object with itself
			{
				if(!golist[i].isStatic)		// don't check static objects
				{
					if(positionTest(golist[i], golist[j]))	// check if any object is moving
					{
						if(sphereCollsTest(golist[i], golist[j]))		// check if objects are in range to collide
						{
							checkCollision(golist[i], golist[j]);
						}
					}
				}
			}
		}
	}
}

void PhysicsEngine::checkCollision(GameObj &go1, GameObj &go2)
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

    else if(go2.wzm[0] < go1.wzm[1] && go2.wzm[0] > go1.wzm[0])          // bottom collision
    {
        colls[0] = 1;
    }
    else if(go2.wzm[1] < go1.wzm[1] && go2.wzm[1] > go1.wzm[0])     // top collision
    {
        colls[0] = 1;
    }
    else if(go2.wzm[0] == go1.wzm[0] && go2.wzm[1] == go1.wzm[1])       // same positions
    {
        colls[0] = 1;
    }
	//                                                      ***Collisions in Y-axis***
	if(go1.wym[0] < go2.wym[1] && go1.wym[0] > go2.wym[0])			// left collision
	{
		colls[1] = -1;
	}
	else if(go1.wym[1] < go2.wym[1] && go1.wym[1] > go2.wym[0])		// right collision
	{
		colls[1] = 1;
	}
	else if(go2.wym[0] < go1.wym[1] && go2.wym[0] > go1.wym[0])			// left collision
	{
		colls[1] = 1;
	}
	else if(go2.wym[1] < go1.wym[1] && go2.wym[1] > go1.wym[0])		// right collision
	{
		colls[1] = 1;
	}
	else if(go1.wym[0] == go2.wym[0] && go1.wym[1] == go2.wym[1])		// same positions
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
	else if(go2.wxm[0] < go1.wxm[1] && go2.wxm[0] > go1.wxm[0])			// back collision
	{
		colls[2] = 1;
	}
	else if(go2.wxm[1] < go1.wxm[1] && go2.wxm[1] > go1.wxm[0])		// front collision
	{
		colls[2] = 1;
	}
	else if(go1.wxm[0] == go2.wxm[0] && go1.wxm[1] == go2.wxm[1])		// same positions
	{
		colls[2] = 1;
	}

	// collision only occurs when collide in all 3 dimensions
	if(colls[0] != 0 && colls[1] != 0 && colls[2] != 0)
	{
			// bounce object outside of collided object
			vect3 bounceVect = vectMult(go1.velocity, -timeStep);
			go1.collCenter.x += bounceVect.x;
			go1.collCenter.y += bounceVect.y;
			go1.collCenter.z += bounceVect.z;

			go1.updatePhysics();					// update go1 box collider

			//check for horizontal collison
			bool horizColl = true;
			if(go1.wzm[0] > go2.wzm[1])		// bottom collision
				horizColl = false;
			else if(go1.wzm[1] < go2.wzm[0])	// top collision
				horizColl = false;

			bounceVect = vectMult(go1.velocity, -go1.elasticity);
			if(horizColl)
			{
				bounceVect.z = bounceVect.z * -1.0;
			}
			else
			{
				bounceVect.x = bounceVect.x * -1.0;
				bounceVect.y = bounceVect.y * -1.0;
			}
			go1.velocity = bounceVect;

			// check if object is stationary
			vect3 deltaVec = vectMult(go1.acceleration, -timeStep);
			if (abs(go1.velocity.z) <= abs(deltaVec.z))
				go1.stationary = true;
			else
				go1.stationary = false;
	}
}

void PhysicsEngine::updatePosition(GameObj &go)
{
	// record objects last position
	go.prevPos.x = go.collCenter.x;
	go.prevPos.y = go.collCenter.y;
	go.prevPos.z = go.collCenter.z;

	if(!go.stationary)
	{
		// update velocity with acceleration
		go.velocity = vectAdd(go.velocity, vectMult(go.acceleration, timeStep));
		vect3 deltaPos = vectMult(go.velocity, timeStep);

		// update position with velocity
		go.collCenter.x += deltaPos.x;
		go.collCenter.y += deltaPos.y;
		go.collCenter.z += deltaPos.z;
	}
	// update object box collider
	go.updatePhysics();
}

bool PhysicsEngine::positionTest(GameObj a, GameObj b)
{
	bool flag = false;
	float delta = 0.001;
	if(abs(a.collCenter.x - a.prevPos.x) > delta)
		flag = true;
	else if(abs(a.collCenter.y - a.prevPos.y) > delta)
		flag = true;
	else if(abs(a.collCenter.z - a.prevPos.z) > delta)
		flag = true;

	if(!flag)
	{
		if(abs(b.collCenter.x - b.prevPos.x) > delta)
			flag = true;
		else if(abs(b.collCenter.y - b.prevPos.y) > delta)
			flag = true;
		else if(abs(b.collCenter.z - b.prevPos.z) > delta)
			flag = true;
	}

	return flag;
}

bool PhysicsEngine::sphereCollsTest(GameObj a, GameObj b)
{
	float centerDist = vectMagn(vectDist(a.collCenter, b.collCenter));
	float collSphDist = a.csDist + b.csDist;

	if(centerDist <= collSphDist)
		return true;
	else
		return false;
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

vect3 PhysicsEngine::vectDist(vertex a, vertex b)
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
