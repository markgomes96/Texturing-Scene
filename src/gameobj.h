#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "includes.h"
#include "physobj.h"

/*
* Creates an game object
* Handles drawing, texturing, phyics
*/

class GameObj : public PhysObj
{
private:

public:
	//Variables related to GameObj class
	vertex position;		//world position
	vect3 scale;
	bool drawBounds;

	vector<polygon> polygons;	// varibles for freeform objects
	colortype color;

	bool isBox;				// variables for cube objects
	struct box faces[6];

	bool isScene;		// object has virtual box collider

	//Constructors
	GameObj();
	// freeform constructor
	GameObj(vertex _position, vect3 _scale, vector<polygon> _polygons, colortype _color, bool isStat);
	// cube constructor
	GameObj(vertex _position, vect3 _scale, bool isStat, bool colorChange = false);
	// scene object constructor
	// bounds[xmin, xmax, ymin, ymax, zmin, zmax]
	GameObj(float* bounds);

	//Game functions
	void defineBox(box *face, vect3 scale, bool colorChange);
};

#endif
