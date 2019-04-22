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
	vertex position;		//world position
	
	//Constructors
	TestObj();
	TestObj(vertex wpos, vect3 scale, bool isStat);

	//Game functions
	//void updateObject(vertex wpos);
	void defineBox(box *face, vect3 scale);
};

#endif
