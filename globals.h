#ifndef GLOBALS
#define GLOBALS
#include "includes.h"

double centerX = 0.0;
double centerY = 0.0;
double centerZ = 0.0;

double CAMERA_R = 15.0;
double CAMERA_THETA = 89.0;
double CAMERA_PHI = 85.5;


//mouse vars
glm::vec3 cameraPos = glm::vec3(3.8f, 0.0f, 2.0f); //1.2f, -0.2f, 0.5f);
glm::vec3 cameraTarget = glm::vec3(3.8f, 4.0f, 2.0f);
glm::vec3 cameraDirection = glm::normalize(cameraPos-cameraTarget);

glm::vec3 up = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));

glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 1.0f); //this keeps it upright
float fov = 45.0f;


double prev_mouse_x = 0;
double prev_mouse_y = 0;
double mouse_dx = 0;
double mouse_dy = 0;
double x_rotat = 0.0;
double y_rotat = 0.0;
float sensitivity = 0.1;
bool first_mouse = true;

double directX = 0;
double directY = 0;
double directZ = 0;

double scaleX = 0.1;
double scaleY = 0.1;
double scaleZ = 0.1;

enum key_state {NOTPUSHED, PUSHED} keyarr[127];
int jump = 0;

extern void buildHeritageHall(void);
extern void buildCameraScene(void);
void defineBox( struct box* );
void drawBox( struct box* );

Game g;

GLuint textureID[2];

#endif
