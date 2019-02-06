#ifndef STRUCTS
#define STRUCTS

typedef struct colortype
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

typedef struct vect3d		//stores data for a 3D vector used for calcualtions
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

#endif
