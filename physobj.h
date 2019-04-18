#ifndef PHYSOBJ_H
#define PHYSOBJ_H

#include "includes.h"

/*
* Makes an object have physical properties
*/

class PhysObj
{
private:

public:
	// Variables related to PhysObj class

	float lxm[2];	float lym[2];	float lzm[2];
	float wxm[2];	float wym[2];	float wzm[2];

	vertex bounds[8];		//box collider 3D; World Space
	vertex collCenter;		//collision center

	// Kinematic motion variables
	vect3 velocity;
	vect3 acceleration;

	// material properties varibles
	float elasticity;		// range [0.0:1.0]

	// collision variables
	bool isStatic;		// isStatic -> not affected by kinematics
	float csDist;	// collsion sphere distance
	vertex prevPos;
	bool stationary;

	// Constructor
	PhysObj();

	// Game functions
	void updatePhysics();
	void createBounds(box *face, vertex wpos);
};

#endif
