#ifndef INCLUDES 
#define INCLUDES

#ifdef LINUX
	#include <GL/glew.h>		//graphics libraries
	#include <GL/glut.h>
	#include <GL/glu.h>
	#include <GL/gl.h>
	#include <glm/glm.hpp>
	#include <glm/gtc/matrix_transform.hpp>

	#include <vector>		//utility libraries
	#include <cmath>
	#include <stdlib.h>
	#include <time.h>
	#include <iostream>
	#include <ctime>

	#include "structs.h"
	#include "SOIL.h"

	using namespace std;
#endif 

#ifdef OSX
	#include <GL/glew.h>		//graphics libraries
	#include <GLUT/glut.h>

	#include <vector>		//utility libraries
	#include <cmath>
	#include <stdlib.h>
	#include <time.h>
	#include <iostream>
	#include <ctime>

	#include "structs.h"
	#include "SOIL.h"

	using namespace std;
#endif

#endif
