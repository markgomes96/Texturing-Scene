#ifndef GLOBALS
#define GLOBALS
#include "includes.h"

double centerX = 0.0;
double centerY = 0.0;
double centerZ = 0.0;

double CAMERA_R = 15.0;
double CAMERA_THETA = 89.0;
double CAMERA_PHI = 85.5;

bool camera = false;

//mouse vars
glm::vec3 cameraPos = glm::vec3(1.2f, -0.2f, 1.2f);
glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 cameraDirection = glm::normalize(cameraPos-cameraTarget);

glm::vec3 up = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
float fov = 45.0f;


double prev_mouse_x = 0;
double prev_mouse_y = 0;
double mouse_dx = 0;
double mouse_dy = 0;
double x_rotat = 0.0;
double y_rotat = 0.0;
float sensitivity = 0.05;

extern void buildHeritageHall(void);
void defineBox( struct box* );
void drawBox( struct box* );

Game g;

#endif
