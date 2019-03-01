#ifndef INCLUDES 
#define INCLUDES

#ifdef LINUX
	#include <GL/gl.h>		//graphics libraries
	#include <GL/glu.h>
	#include <GL/glut.h>
#endif 

#ifdef OSX
	#include <GLUT/glut.h>
	//#include <GLUT/glu.h>
	//#include <GLUT/gl.h>

	#include <vector>		//utility libraries
	#include <cmath>
	#include <stdlib.h>
	#include <time.h>
	#include <iostream>
	#include <ctime>

	#include "structs.h"
	//#include "globals.h"

	using namespace std;
#endif

/*
#include <vector>		//utility libraries
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <ctime>

#include "structs.h"
#include "globals.h"

using namespace std;
*/
#endif
