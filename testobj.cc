#ifndef TESTOBJ_CC
#define TESTOBJ_CC

#include "includes.h"
#include "testobj.h"

/*
* Creates a cube test object
*/

TestObj::TestObj() 
{ }

TestObj::TestObj(vertex wpos, vect3 scale, bool isStat) 
{
	position = wpos;
	isStatic = isStat;
	
	defineBox(&faces[0], scale);
	
	//if(PhysObj* physobj = dynamic_cast< PhysObj* >( &this ))
	PhysObj::createBounds(&faces[0], position);
	position = collCenter;
}

void TestObj::defineBox(box *face, vect3 scale)
{
	face[0].point[0].x = -1.0 * scale.x;  // Bottom
	face[0].point[0].y = -1.0 * scale.y;
	face[0].point[0].z = -1.0 * scale.z;
	face[0].point[0].w =  1.0;

	face[0].point[1].x = -1.0 * scale.x;
	face[0].point[1].y =  1.0 * scale.y;
	face[0].point[1].z = -1.0 * scale.z;
	face[0].point[1].w =  1.0;

	face[0].point[2].x =  1.0 * scale.x;
	face[0].point[2].y =  1.0 * scale.y;
	face[0].point[2].z = -1.0 * scale.z;
	face[0].point[2].w =  1.0;

	face[0].point[3].x =  1.0 * scale.x;
	face[0].point[3].y = -1.0 * scale.y;
	face[0].point[3].z = -1.0 * scale.z;
	face[0].point[3].w =  1.0;

	face[1].point[0].x = -1.0 * scale.x;  // Left Side
	face[1].point[0].y = -1.0 * scale.y;
	face[1].point[0].z = -1.0 * scale.z;
	face[1].point[0].w =  1.0;

	face[1].point[1].x = -1.0 * scale.x;
	face[1].point[1].y = -1.0 * scale.y;
	face[1].point[1].z =  1.0 * scale.z;
	face[1].point[1].w =  1.0;

	face[1].point[2].x =  1.0 * scale.x;
    face[1].point[2].y = -1.0 * scale.y;
	face[1].point[2].z =  1.0 * scale.z;
	face[1].point[2].w =  1.0;

	face[1].point[3].x =  1.0 * scale.x;
	face[1].point[3].y = -1.0 * scale.y;
	face[1].point[3].z = -1.0 * scale.z;
	face[1].point[3].w =  1.0;

	face[2].point[0].x = -1.0 * scale.x;  // Right Side 
	face[2].point[0].y =  1.0 * scale.y;
	face[2].point[0].z = -1.0 * scale.z;
	face[2].point[0].w =  1.0;

	face[2].point[1].x = -1.0 * scale.x;
	face[2].point[1].y =  1.0 * scale.y;
	face[2].point[1].z =  1.0 * scale.z;
	face[2].point[1].w =  1.0;

	face[2].point[2].x =  1.0 * scale.x;
	face[2].point[2].y =  1.0 * scale.y;
	face[2].point[2].z =  1.0 * scale.z;
	face[2].point[2].w =  1.0;

	face[2].point[3].x =  1.0 * scale.x;
	face[2].point[3].y =  1.0 * scale.y;
	face[2].point[3].z = -1.0 * scale.z;
	face[2].point[3].w =  1.0;
	
	face[3].point[0].x = -1.0 * scale.x;  // Back Side 
	face[3].point[0].y = -1.0 * scale.y;
	face[3].point[0].z = -1.0 * scale.z;
	face[3].point[0].w =  1.0;

	face[3].point[1].x = -1.0 * scale.x;
	face[3].point[1].y = -1.0 * scale.y;
	face[3].point[1].z =  1.0 * scale.z;
	face[3].point[1].w =  1.0;

	face[3].point[2].x = -1.0 * scale.x;
	face[3].point[2].y =  1.0 * scale.y;
	face[3].point[2].z =  1.0 * scale.z;
	face[3].point[2].w =  1.0;

	face[3].point[3].x = -1.0 * scale.x;
	face[3].point[3].y =  1.0 * scale.y;
	face[3].point[3].z = -1.0 * scale.z;
	face[3].point[3].w =  1.0;

	face[4].point[0].x =  1.0 * scale.x;  // Front Side 
	face[4].point[0].y = -1.0 * scale.y;
	face[4].point[0].z = -1.0 * scale.z;
	face[4].point[0].w =  1.0;

	face[4].point[1].x =  1.0 * scale.x;
	face[4].point[1].y = -1.0 * scale.y;
	face[4].point[1].z =  1.0 * scale.z;
	face[4].point[1].w =  1.0;

	face[4].point[2].x =  1.0 * scale.x;
	face[4].point[2].y =  1.0 * scale.y;
	face[4].point[2].z =  1.0 * scale.z;
	face[4].point[2].w =  1.0;

	face[4].point[3].x =  1.0 * scale.x;
	face[4].point[3].y =  1.0 * scale.y;
	face[4].point[3].z = -1.0 * scale.z;
	face[4].point[3].w =  1.0;

	face[5].point[0].x = -1.0 * scale.x;  // Top 
	face[5].point[0].y = -1.0 * scale.y;
	face[5].point[0].z =  1.0 * scale.z;
	face[5].point[0].w =  1.0;

	face[5].point[1].x = -1.0 * scale.x;
	face[5].point[1].y =  1.0 * scale.y;
	face[5].point[1].z =  1.0 * scale.z;
	face[5].point[1].w =  1.0;

	face[5].point[2].x =  1.0 * scale.x;
	face[5].point[2].y =  1.0 * scale.y;
	face[5].point[2].z =  1.0 * scale.z;
	face[5].point[2].w =  1.0;

	face[5].point[3].x =  1.0 * scale.x;
	face[5].point[3].y = -1.0 * scale.y;
	face[5].point[3].z =  1.0 * scale.z;
	face[5].point[3].w =  1.0;


	// Define the colors
	face[0].color.red   = 1.0;
	face[0].color.green = 0.0;
	face[0].color.blue  = 0.0;
	
	face[1].color.red   = 0.0;
	face[1].color.green = 1.0;
	face[1].color.blue  = 0.0;
	
	face[2].color.red   = 0.0;
	face[2].color.green = 0.0;
	face[2].color.blue  = 1.0;

	face[3].color.red   = 1.0;
	face[3].color.green = 1.0;
	face[3].color.blue  = 0.0;

	face[4].color.red   = 1.0;
	face[4].color.green = 0.0;
	face[4].color.blue  = 1.0;

	face[5].color.red   = 0.0;
	face[5].color.green = 1.0;
	face[5].color.blue  = 1.0;
	
}

#endif
