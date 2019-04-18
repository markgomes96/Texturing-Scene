#ifndef TEXTURING
#define TEXTURING

#include "includes.h"

extern GLuint textureID[2];


void loadTextures() {
	unsigned char* image;
	int width, height;
	float colorMode[4] = {0.0, 0.0, 0.0, 0.0};
	cout << "here" << endl;

	//to get the actual color of the texture rather than last stored color
	//glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, colorMode);

	//first texture
	glGenTextures(1, &textureID[0]);
	cout << "here2" << endl;	
glBindTexture(GL_TEXTURE_2D, textureID[0]);
	cout << "here3" << endl;

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	//glGenerateMipmap(GL_TEXTURE_2D);
cout << "hello" << endl;	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	cout << "here5" << endl;

	image = SOIL_load_image("./textures/10A.png", &width, &height, 0, SOIL_LOAD_RGB);
	cout << "HERE" << endl;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

	glGenerateMipmap(GL_TEXTURE_2D);

	SOIL_free_image_data(image);

	//second texture
	
	//cout << textureID[0] << endl;

//	glBindTexture(GL_TEXTURE_2D, 0);	
}


#endif
