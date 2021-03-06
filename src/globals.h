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
glm::vec3 cameraTarget = glm::vec3(6.8f, 8.0f, 2.0f);
glm::vec3 cameraDirection = glm::normalize(cameraPos-cameraTarget);

glm::vec3 zVec = glm::vec3(0.0, 8.0, 2.0);


glm::vec3 up = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));

glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 1.0f); //this keeps it upright
float fov = 45.0f;

double MIN_X = 1.0;
double MAX_X = 6.5;
double MIN_Y = -6.5;
double MAX_Y = 54.5;
double MIN_Z = 1.0;
double MAX_Z = 4.5;

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

// Scale of projectile
double scaleObX = 0.1;
double scaleObY = 0.1;
double scaleObZ = 0.1;

// acceleration of the object, at the beginning, there is only gravity
double scaleAccX = 0;
double scaleAccY = 0;
double scaleAccZ = 0;
double addAcc[3] = {0,0,0};
// 1 is change scaleAccX, 2 is scaleAccY and 3 is scaleAccZ
int changeAcc = 1;

double power = 1;
enum key_state {NOTPUSHED, PUSHED} keyarr[127];
int jump = 0;
bool unhold = false;

bool left_mouse_down = false;
bool left_mouse_released = false;

// This is for the target mechanism
bool destroy = false;
bool SHOW_HUD = true;
int counter = 0;
int score = 0;
int penalty = 0;

extern void buildHeritageHall(void);
extern void buildCameraScene(void);
void defineBox( struct box* );
void drawBox( struct box* );
Game g;

GLuint textureID[100];

/*int starT = 0;
int startP = 0;
int pauseT = 0;*/

#endif
