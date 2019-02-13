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
	vertex bounds[8];	//box collider 3D; World Space

	//vect3 gravity;
	//vect3 velocity;
	//vect3 acceleration;

	bool isStatic;		//isStatic -> not affected by kinematics

	//Constructor
	PhysObj();

	//Game functions
	void createBounds(box *face, vect3 wpos);
};

#endif
