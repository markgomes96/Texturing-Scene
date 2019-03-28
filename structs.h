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

typedef struct vect3		//stores data for a 3D vector used for calculations
{
	float x;
	float y;
	float z;

	vect3()
	{}

	vect3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
} vect3;

typedef struct vertex {
        float x;
        float y;
        float z;
        float w;

	vertex()
	{}

	vertex(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

} vertex;

typedef struct box {
	vertex point[4];
	colortype color;	
} box;

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
#endif
