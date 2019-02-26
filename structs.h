#ifndef STRUCTS
#define STRUCTS

typedef struct colortype	//stores object color
{
	float red;
	float green;
	float blue;
    
	colortype()
	{};

	colortype(float _red, float _green, float _blue)
	{
		red = _red;
		green = _green;
		blue = _blue;
	}
} colortype;

typedef struct vect3d		//stores data for a 3D vector used for calculations
{
	float x;
	float y;
	float z;

	vect3d()
	{}

	vect3d(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
} vect3d;

//structs to create cubes for display cases//
/*
typedef struct vertex {
        float x;
        float y;
        float z;
        float w;
} vertex;

typedef struct colortype {
	float red;
	float green;
	float blue;
} colortype;
*/
typedef struct box {
	vect3d point[4];
	colortype color;	
} box;
//////////////////////////////////////////////
#endif
