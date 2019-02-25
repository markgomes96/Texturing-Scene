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
	//Variables related to PhysObj class

	//expirement with just using mins/maxs
	float lxm[2];	float lym[2];	float lzm[2];
	float wxm[2];	float wym[2];	float wzm[2];
	//

	vertex bounds[8];		//box collider 3D; World Space
	vertex collCenter;		//collision center

	// kinematic motion
	vect3 velocity;
	vect3 acceleration;

	bool isStatic;		//isStatic -> not affected by kinematics

	//Constructor
	PhysObj();

	//Game functions
	void updatePhysics();
	void createBounds(box *face, vertex wpos);
};

#endif
