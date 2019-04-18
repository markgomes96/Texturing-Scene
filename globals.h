#ifndef GLOBALS
#define GLOBALS

double centerX = 1.2;
double centerY = 3.6;
double centerZ = 0.7;

double CAMERA_R = 15.0;
double CAMERA_THETA = 89.0;
double CAMERA_PHI = 85.5;

double directX = 0;
double directY = 0;
double directZ = 0;

enum key_state {NOTPUSHED, PUSHED} keyarr[127];
int jump = 0;
extern void buildHeritageHall(void);
extern void buildCameraScene(void);
void defineBox( struct box* );
void drawBox( struct box* );

Game g;

#endif
