#ifndef GLOBALS
#define GLOBALS
#include "includes.h"

double centerX = 1.2;
double centerY = 3.6;
double centerZ = 0.7;

double CAMERA_R = 15.0;
double CAMERA_THETA = 89.0;
double CAMERA_PHI = 85.5;

//mouse vars
glm::vec3 cameraPos = glm::vec3(1.2f, 3.6f, 0.7f);
glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 cameraDirection = glm::normalize(cameraPos-cameraTarget);

glm::vec3 up = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
float fov = 45.0f;


double prev_mouse_x = 450;
double prev_mouse_y = 450;
double mouse_dx = 0;
double mouse_dy = 0;
double x_rotat = -90;
double y_rotat = 0;
double sensitivity = 0.5;

extern void buildHeritageHall(void);
void defineBox( struct box* );
void drawBox( struct box* );

Game g;

#endif
