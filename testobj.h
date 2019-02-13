#ifndef TESTOBJ_H
#define TESTOBJ_H

#include "includes.h"
#include "physobj.h"

/*
* Creates a cube test object
*/

class TestObj : public PhysObj
{
private:

public:
	//Variables related to TestObj class
	struct box faces[6];
	vect3 position;		//world position
	
	//Constructors
	TestObj();
	TestObj(vect3 wpos, vect3 scale);

	//Game functions
	void defineBox(box *face, vect3 scale);
};

#endif
