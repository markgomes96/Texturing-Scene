#ifndef INCLUDES 
#define INCLUDES

#ifdef LINUX
	#include <GL/gl.h>		//graphics libraries
	#include <GL/glu.h>
	#include <GL/glut.h>
	#include <glm/glm.hpp>
	#include <glm/gtc/matrix_transform.hpp>

	#include <vector>		//utility libraries
	#include <cmath>
	#include <stdlib.h>
	#include <time.h>
	#include <iostream>
	#include <ctime>

	#include "structs.h"

	using namespace std;
#endif 

#ifdef OSX
	#include <GLUT/glut.h>		//graphics libraries

	#include <vector>		//utility libraries
	#include <cmath>
	#include <stdlib.h>
	#include <time.h>
	#include <iostream>
	#include <ctime>

	#include "structs.h"

	using namespace std;
#endif

#endif
