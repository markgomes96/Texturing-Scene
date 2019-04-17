#ifndef PHYSOBJ_CC
#define PHYSOBJ_CC

#include "includes.h"
#include "physobj.h"

/*
* Makes an object have physical properties
*/

PhysObj::PhysObj() 
{ 
	velocity = vect3(0.0, 0.0, 0.0);
	acceleration = vect3(0.0, 0.0, -0.01);		// initial gravity
}

void PhysObj::updateVelo(float x, float y, float z){
    velocity.x += x;
    velocity.y += y;
    velocity.z += z;
}
void PhysObj::updatePhysics()
{
	// Update bounds to new world position
	wxm[0] = lxm[0] + collCenter.x;	wxm[1] = lxm[1] + collCenter.x;		// update world extrema
	wym[0] = lym[0] + collCenter.y;	wym[1] = lym[1] + collCenter.y;
	wzm[0] = lzm[0] + collCenter.z;	wzm[1] = lzm[1] + collCenter.z;

	int ind = 0;
	for(int x = 0; x < 2; x++)			// update would bounds
	{
		for(int y = 0; y < 2; y++)
		{
			for(int z = 0; z < 2; z++)
			{
				bounds[ind] = vertex(wxm[x], wym[y], wzm[z], 1);
				ind++;
			}
		}
	}
}

void PhysObj::createBounds(box *face, vertex wpos)		// create cube bound around object
{
	// {min, max}
	lxm[0] = face[0].point[0].x;	lxm[1] = face[0].point[0].x;
	lym[0] = face[0].point[0].y;	lym[1] = face[0].point[0].y;
	lzm[0] = face[0].point[0].z;	lzm[1] = face[0].point[0].z;

	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(face[i].point[j].x < lxm[0])		// x min
			{
				lxm[0] = face[i].point[j].x;
			}

			if(face[i].point[j].x > lxm[1])		// x max
			{
				lxm[1] = face[i].point[j].x;
			}

			if(face[i].point[j].y < lym[0])		// y min
			{
				lym[0] = face[i].point[j].y;
			}

			if(face[i].point[j].y > lym[1])		// y max
			{
				lym[1] = face[i].point[j].y;
			}

			if(face[i].point[j].z < lzm[0])		// z min
			{
				lzm[0] = face[i].point[j].z;
			}

			if(face[i].point[j].z > lzm[1])		// z max
			{
				lzm[1] = face[i].point[j].z;
			}
		}
	}

	// Place collision center in center of box collider
	collCenter = vertex( (lxm[1] + lxm[0])/2.0 , (lym[1] + lym[0])/2.0 , (lzm[1] + lzm[0])/2.0 , 1.0);
	collCenter.x = collCenter.x + wpos.x;
	collCenter.y = collCenter.y + wpos.y;
	collCenter.z = collCenter.z + wpos.z;

	// Convert local coordinates to world coordinates
	wxm[0] = lxm[0] + wpos.x;	wxm[1] = lxm[1] + wpos.x;
	wym[0] = lym[0] + wpos.y;	wym[1] = lym[1] + wpos.y;
	wzm[0] = lzm[0] + wpos.z;	wzm[1] = lzm[1] + wpos.z;

	int ind = 0;
	for(int x = 0; x < 2; x++)					// Iterate through possible combinations of extrema
	{
		for(int y = 0; y < 2; y++)
		{
			for(int z = 0; z < 2; z++)
			{
				bounds[ind] = vertex(wxm[x], wym[y], wzm[z], 1);
				ind++;
			}
		}
	}
}

#endif
