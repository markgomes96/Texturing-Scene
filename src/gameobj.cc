#ifndef GAMEOBJ_CC
#define GAMEOBJ_CC

#include "includes.h"
#include "gameobj.h"

/*
* Creates an game object
* Handles drawing, texturing, phyics
*/

GameObj::GameObj()
{ }

GameObj::GameObj(vertex _position, vect3 _scale, vector<polygon> _polygons,colortype _color, bool isStat)
{
    position = _position;
    scale = _scale;
	isStatic = isStat;
    isBox = false;
    isScene = false;
    polygons = _polygons;
    color = _color;
	PhysObj::createBounds(&faces[0], position);
	position = collCenter;
}

GameObj::GameObj(vertex _position, vect3 _scale, bool isStat, bool colorChange) {
    position = _position;
    scale = _scale;
	isStatic = isStat;
    isBox = true;
    isScene = false;
	defineBox(&faces[0], scale, colorChange);

	PhysObj::createBounds(&faces[0], position);
	position = collCenter;
}

// bounds[xmin, xmax, ymin, ymax, zmin, zmax]
GameObj::GameObj(float* bs)
{
    isStatic = true;
    isBox = false;
    isScene = true;
    PhysObj::createSceneBounds(bs);
    //cout << collCenter.x << "," << collCenter.y << "," << collCenter.z <<  endl;
    position = collCenter;

    /*
    cout << "xmin : " << wxm[0] << "  |  xmax : " << wxm[1] << endl;
    cout << "ymin : " << wym[0] << "  |  ymax : " << wym[1] << endl;
    cout << "zmin : " << wzm[0] << "  |  zmax : " << wzm[1] << endl;
    */
}

void GameObj::defineBox(box *face, vect3 scale, bool colorChange)
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
	if (!colorChange)
    {
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
    else
    {
        float HI = 0.9;
        float LO = 0.2;
        srand(static_cast <unsigned> (time(0)));
        for (int i = 0; i<6;i++)
        {
            face[i].color.red   = LO + static_cast <float> (rand()) / static_cast <float> (RAND_MAX)/(HI-LO);
            face[i].color.green = LO + static_cast <float> (rand()) / static_cast <float> (RAND_MAX)/(HI-LO);
            face[i].color.blue  = LO + static_cast <float> (rand()) / static_cast <float> (RAND_MAX)/(HI-LO);
        }
    }

}

#endif
