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

void PhysicsEngine::updateObjects(vector<GameObj> &obList, vector<GameObj> &tarList)
{
	// update position of every object
	for(int i = 0; i < obList.size(); i++){
		if(!obList[i].isStatic){
			updatePosition(obList[i]);
		}
	}


	for(int i = 0; i < tarList.size(); i++){
		if(!tarList[i].isStatic){
			updatePosition(tarList[i]);
		}
	}

	// check for collisions
	for(int i = 0; i < obList.size(); i++){
		for(int j = 0; j < obList.size(); j++){
			if(i != j){		// don't check object with itself
				if(!obList[i].isStatic){		// don't check static objects
					if(positionTest(obList[i], obList[j])){	// check if any object is moving
						if(sphereCollsTest(obList[i], obList[j])){		// check if objects are in range to collide
							checkCollision(obList[i], obList[j]);
						}
					}
				}
			}
		}
	}


	for(int i = 0; i < tarList.size(); i++){
		for(int j = 0; j < tarList.size(); j++){
			if(i != j){		// don't check tarject with itself
				if(!tarList[i].isStatic){		// don't check static tarjects
					if(positionTest(tarList[i], tarList[j])){	// check if any tarject is moving
						if(sphereCollsTest(tarList[i], tarList[j])){		// check if tarjects are in range to collide
							checkCollision(tarList[i], tarList[j]);
						}
					}
				}
			}
		}
	}

    int countOb = 0;
    int countTar = 0;
    while (countOb < obList.size()){
        countTar = 0;
        while (countTar < tarList.size()){
            if(!tarList[countTar].isStatic){	
		        if(positionTest(obList[countOb], tarList[countTar])){
                    if (sphereCollsTest(obList[countOb], tarList[countTar])){
                        tarList.erase(tarList.begin() + countTar);
                        obList.erase(obList.begin() + countOb);
                        countOb--;
                        break;
                    }
                }

            }
            countTar++;
        }
        countOb++;
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
	    printf("What's up" );
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
