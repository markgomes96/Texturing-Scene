#ifndef GAME_CC
#define GAME_CC

#include "includes.h"
#include "game.h"
#include "prototypes.h"
#include <fstream>
#include <stdlib.h>

extern void buildDisplay();
extern void buildCameraScene();
extern void buildHeritageHall();
extern double directX,directY, directZ, scaleAccX, scaleAccY, scaleAccZ, power;
extern double MIN_X, MIN_Y, MIN_Z, MAX_X, MAX_Y, MAX_Z;
extern glm::vec3 cameraFront, cameraTarget, cameraPos, up, cameraDirection;
extern double addAcc[3];
/*
 * Handles all functions of the game
 */

Game::Game()
{ }

void Game::init()
{

	//cout << "in game init" << endl;
    frameRate = 60.0;
    physEng = PhysicsEngine(frameRate);
    loadTextures();

	addSceneObjects();		// add scene objects to physics engine

    frameRate = 60.0;
    physEng = PhysicsEngine(frameRate);
    loadTextures();
    createTarget(randomize(MIN_X, MAX_X), // + cameraFront.x,
             randomize(MIN_Y, MAX_Y), // + cameraFront.y,
            randomize(MIN_Z, MAX_Z), // + cameraFront.z,
            1, 0.2, 0.001, 0.2);
}

// Create throwing object
void Game::createProjectile(double posX, double posY, double posZ, double posW, double scaleX, double scaleY, double scaleZ){
    GameObj projectile = GameObj(vertex(posX, posY, posZ ,posW), vect3(scaleX , scaleY ,scaleZ), false, true);
    directX =  ((double)cameraTarget.x - (double)cameraPos.x) * power;
    directY =  ((double)cameraTarget.y - (double)cameraPos.y) * power;
    directZ =  ((double)cameraTarget.z - (double)cameraPos.z) * power;
    projectile.updateVelo(directX, directY, directZ);
    projectile.updateAcc(addAcc[0], addAcc[1], addAcc[2]);

    obList.push_back(projectile);
}

void Game::createTarget(double posX, double posY, double posZ, double posW, double scaleX, double scaleY, double scaleZ){
    GameObj projectile = GameObj(vertex(posX, posY, posZ ,posW), vect3(scaleX , scaleY ,scaleZ), false, true);

    // randomize the velocity
    float HI = 0.5;
    float LO = -0.5;
    float veloX, veloY, veloZ;
    srand(time(NULL));
    veloX   = randomize(LO,HI);
    veloY   = randomize(LO,HI);
    veloZ   = randomize(LO,HI);

    // Update the velocity and also remove gravity
    projectile.updateVelo(veloX, veloY, veloZ);
    projectile.updateAcc(0,0,9.8);
    //printf("velocity %f %f %f\n", projectile.velocity.x, projectile.velocity.y, projectile.velocity.z);
//    printf("acceleration %f %f %f\n", projectile.acceleration.x, projectile.acceleration.y, projectile.acceleration.z);

    tarList.push_back(projectile);
}

// Create an object where the eye is
void Game::createEye(double posX, double posY, double posZ, double posW, double scaleX, double scaleY, double scaleZ){
    GameObj projectile = GameObj(vertex(posX, posY, posZ ,posW), vect3(scaleX , scaleY ,scaleZ), false, true);
    obList.push_back(projectile);
}

void Game::update()
{
    // Update each phyisc object
    physEng.updateObjects(obList, tarList);
    glutLockFrameRate(frameRate);
}

void Game::character()
{
}

void Game::minimap()
{
    buildCameraScene();
    buildHeritageHall();
}

void Game::HUD()
{
    //displays HUD in a 2D square on the bottom left on the screen
    //	buildHeritageHall();
    float testNumber = 3.00;

    char *test = (char*) malloc(64*sizeof(char));
    sprintf(test, "STATS: %6.4f", testNumber);

    char *HUDtitle = (char*) malloc(64*sizeof(char));
    sprintf(HUDtitle, "HUD");

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_CULL_FACE);

    glClear(GL_DEPTH_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); //black

    //test stats
    const char* c;
    glRasterPos2i(5, 20);
    for (c=test;*c!='\0';c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    //HUD title
    /*glRasterPos2i(10, 25);
      for (c=HUDtitle;*c!='\0';c++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
      }*/

    glColor3f(1.0, 1.0, 1.0);
    glRecti(0.0, 0.0, 30.0, 30.0);

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    //glPopMatrix();

    //buildCameraScene();
    free(test);
}

void Game::render()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();

    gluLookAt(  20.0, 5.0,   5.0,   // Eye
            0.0,  0.0,  1.0,  	// Center
            0.0,  0.0,  1.0); 	// Up
    glEnable(GL_DEPTH_TEST);

    glColor3f(0.0,1.0,0.0);

	buildHeritageHall();
	buildDisplay();

    // Physics test
    for(int i = 0; i < obList.size(); i++)
    {
        drawObject(obList[i]);

        // draws collision boundary in red lines
        /*
        if(obList[i].isScene)
        {
            drawBounds(&obList[i].bounds[0]);
        }
        */
    }

    glutSwapBuffers();
}

void Game::drawObject(GameObj go)
{
	if(!go.isScene)		// don't draw scene objects
	{
	    if(go.isBox)
	        drawCube(&go.faces[0], &go.collCenter);
	    else
	        drawFreeForm(go.polygons, go.collCenter);
	}
}


//Renders the SceneObjects vector
void Game::drawSceneObjects( ){

  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity( );

  gluLookAt( (double)cameraPos.x, (double)cameraPos.y, (double)cameraPos.z,
     (double) cameraTarget.x, // + cameraFront.x,
     (double) cameraTarget.y, // + cameraFront.y,
     (double) cameraTarget.z, // + cameraFront.z,
     (double) up.x, (double) up.y, (double) up.z);       // Up */


  for( int i = 0; i < SceneObjects.size(); i++ ){
    drawPoly( SceneObjects[ i ] );
  }
}

/* Generate a random float */
float randColorVal( ){
  return (float) rand() / RAND_MAX;
}

/* Draw polygon shapes */
void Game::drawPoly( object ob ){
  glPushMatrix( );
  glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
  glColor3f( 0.0, 0.0, 1.0 );
  glBegin( GL_POLYGON );
  for( int i = 0; i < ob.polygons.size(); i++) {
      polygon p = ob.polygons[i];
      for (int j = 0; j < p.vertices.size(); j++){
            glVertex3f( p.vertices[j].x,
		    p.vertices[j].y,
		    p.vertices[j].z );
      }
  }
  glEnd( );
  glPopMatrix( );
}

/* Helper function to read in the vertices from the data file */
void Game::loadVertex( string buffer, vertex& ver ){
  string token;
  size_t pos = 0;
  buffer.erase(0,1);
  pos = buffer.find(",");
  token = buffer.substr(0,pos);
  ver.x = atof(token.c_str());
  //cout << ver.x << endl;
  buffer.erase( 0, pos );

  buffer.erase(0,1);
  pos = buffer.find(",");
  token = buffer.substr(0,pos);
  ver.y = atof(token.c_str());
  //cout << ver.y << endl;
  buffer.erase( 0, pos );

  buffer.erase(0,1);
  pos = buffer.find(",");
  token = buffer.substr(0,pos);
  ver.z = atof(token.c_str());
  //cout << ver.z << endl;
  buffer.erase( 0, pos );
}

/*
 *  Read in the vertices file and load them into the game object. This function should be
 *  called only ONCE -- probably somewhere in init.
 */
void Game::loadVerticesFileData( char* fileName ){
  fstream file( fileName, ios::in );
  string buffer;
  object ob;

  while( getline( file, buffer ) ){
    vertex v;
    if( buffer[0] == 'v' ){
	loadVertex( buffer, v );
	ob.polygons[0].vertices.push_back( v );
    } else if ( buffer[0] == '#' ) {
      SceneObjects.push_back( ob );
      object newPol;
      ob = newPol;
    }
  }
}


// Physics / Framerate
void Game::drawFreeForm(vector<polygon> polygons, vertex position)
{
    for(int p = 0; p < polygons.size(); p++)
    {
        glBegin( GL_POLYGON );
        for (int v = 0; v < polygons[p].vertices.size(); v++)
        {
            glVertex3f(polygons[p].vertices[v].x,
                    polygons[p].vertices[v].y,
                    polygons[p].vertices[v].z);
        }
        glEnd();
    }
}

void Game::drawCube(struct box *face, vertex *position)
{
    int i, j;

    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    glPushMatrix();
    glTranslatef( position -> x, position -> y, position -> z);		// move box to right position

    for(j = 0; j < 6; j++)		// draw box
    {

        glColor3f(face[j].color.red,
                face[j].color.green,
                face[j].color.blue);

        glBegin( GL_POLYGON );
        for (i = 0; i < 4; i++)
        {
            glVertex3f(face[j].point[i].x,
                    face[j].point[i].y,
                    face[j].point[i].z);
        }
        glEnd();
    }
    glPopMatrix();
}

void Game::drawBounds( vertex *bounds )
{
    glPushMatrix();

    glLineWidth(5.0);
    glColor3f(1.0, 0.0, 0.0);
    for(int i = 0; i < 8; i++)
    {
        glBegin( GL_LINES );
        if(i == 7)
        {
            glVertex3f( bounds[i].x, bounds[i].y, bounds[i].z );
            glVertex3f( bounds[0].x, bounds[0].y, bounds[0].z );
        }
        else
        {
            glVertex3f( bounds[i].x, bounds[i].y, bounds[i].z );
            glVertex3f( bounds[i+1].x, bounds[i+1].y, bounds[i+1].z );
        }
        glEnd();
    }
    glLineWidth(1.0);

    glPopMatrix();
}

// Physics / Framerate
void Game::glutLockFrameRate(float desiredFrameRate)
{
    int millisecondsToWait = (int)((1.0 / desiredFrameRate) * 1000);

    int startTime = glutGet(GLUT_ELAPSED_TIME);

    do{/*wait*/}
    while((glutGet(GLUT_ELAPSED_TIME)-startTime) < millisecondsToWait);
}

// Input replay functions
void Game::mouse( int button, int state, int x, int y )
{
	input.mouse(button, state, x, y);
}
void Game::keyboard( unsigned char key, int x, int y )
{
    input.keyboard(key, x, y);
}
void Game::keyup( unsigned char key, int x, int y )
{
    input.keyup(key, x, y);
}
void Game::specialInput(int key, int x, int y)
{
    input.specialInput(key, x, y);
}
void Game::mouseMovement(int x, int y){
    input.mouseMovement(x, y);
}
void Game::passiveMouseMovement(int x, int y){
    input.passiveMouseMovement(x, y);
}


void Game::addSceneObjects()
{
	float *bs = (float*) malloc(6*sizeof(float));
	float *bo = (float*) malloc(6*sizeof(float));
	float *ob = (float*) malloc(6*sizeof(float));
	float *base = (float*) malloc(6*sizeof(float));
	float *glass = (float*) malloc(6*sizeof(float));

	// *** floor *** -> large floor supports entire scene
	bs[0]= -5.0; bs[1] = 12.0; bs[2]= -18.0; bs[3]= 55.0; bs[4] = -1.0; bs[5]= 0.0;
	obList.push_back(GameObj(bs));

    // *** ceiling *** -> flat all the way through, no arches
    bs[0]= -5.0; bs[1] = 12.0; bs[2]= -18.0; bs[3]= 55.0; bs[4] = 5.4864; bs[5]= 7.0;
	obList.push_back(GameObj(bs));

    // *** walls ***
    // left wall
    bs[0]= -1.0; bs[1] = 0.2; bs[2]= -18.0; bs[3]= 55.0; bs[4] = 0.0; bs[5]= 5.4864;
	obList.push_back(GameObj(bs));

    // right wall
    bs[0]= 7.0; bs[1] = 8.0; bs[2]= -18.0; bs[3]= 55.0; bs[4] = 0.0; bs[5]= 5.4864;
	obList.push_back(GameObj(bs));

    // back wall
    bs[0]= -5.0; bs[1] = 12.0; bs[2]= -10.0; bs[3]= -9.0; bs[4] = 0.0; bs[5]= 5.4864;
    obList.push_back(GameObj(bs));

    // front wall
    bs[0]= -5.0; bs[1] = 12.0; bs[2]= 54.9; bs[3]= 55.9; bs[4] = 0.0; bs[5]= 5.4864;
    obList.push_back(GameObj(bs));

    // *** display cases **** -> base and glass box colliders
	bo[0] = 0.0; bo[1] = 1.5748; bo[2]= 0.0; bo[3]= 2.8702; bo[4] = 0.0; bo[5]= 0.4572;
	ob[0]= 0.127; ob[1] = 1.4478; ob[2]=  0.127; ob[3]= 2.7432; ob[4] = 0.4572; ob[5]= 2.5146;
	base[0] = 0.0; base[1] = 0.0; base[2]= 0.0; base[3]= 0.0; base[4] = 0.0; base[5]= 0.0;
	glass[0]= 0.0; glass[1] = 0.0; glass[2]=  0.0; glass[3]= 0.0; glass[4] = 0.0; glass[5]= 0.0;

	vect3 orig = vect3(0.0, 0.0, 0.0);
	vect3 trans = vect3(0.0, 0.0, 0.0);
	vect3 mod = vect3(0.0, 0.0, 0.0);

	// case 1
	mod = vect3(0.75,5.75,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	obList.push_back(GameObj(base));
	glass[0] = ob[0]+trans.x; glass[1] = ob[1]+trans.x; glass[2] = ob[2]+trans.y; glass[3] = ob[3]+trans.y; glass[4] = ob[4]+trans.z; glass[5] = ob[5]+trans.z;
	obList.push_back(GameObj(glass));

	// case 2
	mod = vect3(5.25,5.75,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	obList.push_back(GameObj(base));
	glass[0] = ob[0]+trans.x; glass[1] = ob[1]+trans.x; glass[2] = ob[2]+trans.y; glass[3] = ob[3]+trans.y; glass[4] = ob[4]+trans.z; glass[5] = ob[5]+trans.z;
	obList.push_back(GameObj(glass));

	// case 3
	mod = vect3(0.75,15.75,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	obList.push_back(GameObj(base));
	glass[0] = ob[0]+trans.x; glass[1] = ob[1]+trans.x; glass[2] = ob[2]+trans.y; glass[3] = ob[3]+trans.y; glass[4] = ob[4]+trans.z; glass[5] = ob[5]+trans.z;
	obList.push_back(GameObj(glass));

	// case 4
	mod = vect3(5.25,15.75,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	obList.push_back(GameObj(base));
	glass[0] = ob[0]+trans.x; glass[1] = ob[1]+trans.x; glass[2] = ob[2]+trans.y; glass[3] = ob[3]+trans.y; glass[4] = ob[4]+trans.z; glass[5] = ob[5]+trans.z;
	obList.push_back(GameObj(glass));

	// case 5
	mod = vect3(5.25,25.75,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	obList.push_back(GameObj(base));
	glass[0] = ob[0]+trans.x; glass[1] = ob[1]+trans.x; glass[2] = ob[2]+trans.y; glass[3] = ob[3]+trans.y; glass[4] = ob[4]+trans.z; glass[5] = ob[5]+trans.z;
	obList.push_back(GameObj(glass));

	// case 6
	mod = vect3(0.75,25.75,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	obList.push_back(GameObj(base));
	glass[0] = ob[0]+trans.x; glass[1] = ob[1]+trans.x; glass[2] = ob[2]+trans.y; glass[3] = ob[3]+trans.y; glass[4] = ob[4]+trans.z; glass[5] = ob[5]+trans.z;
	obList.push_back(GameObj(glass));

	// case 7
	mod = vect3(0.75,35.75,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	obList.push_back(GameObj(base));
	glass[0] = ob[0]+trans.x; glass[1] = ob[1]+trans.x; glass[2] = ob[2]+trans.y; glass[3] = ob[3]+trans.y; glass[4] = ob[4]+trans.z; glass[5] = ob[5]+trans.z;
	obList.push_back(GameObj(glass));

	// case 8
	mod = vect3(5.25,35.75,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	obList.push_back(GameObj(base));
	glass[0] = ob[0]+trans.x; glass[1] = ob[1]+trans.x; glass[2] = ob[2]+trans.y; glass[3] = ob[3]+trans.y; glass[4] = ob[4]+trans.z; glass[5] = ob[5]+trans.z;
	obList.push_back(GameObj(glass));

	// case 9
	mod = vect3(0.75,45.75,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	obList.push_back(GameObj(base));
	glass[0] = ob[0]+trans.x; glass[1] = ob[1]+trans.x; glass[2] = ob[2]+trans.y; glass[3] = ob[3]+trans.y; glass[4] = ob[4]+trans.z; glass[5] = ob[5]+trans.z;
	obList.push_back(GameObj(glass));

	// case 10
	mod = vect3(5.25,45.75,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	obList.push_back(GameObj(base));
	glass[0] = ob[0]+trans.x; glass[1] = ob[1]+trans.x; glass[2] = ob[2]+trans.y; glass[3] = ob[3]+trans.y; glass[4] = ob[4]+trans.z; glass[5] = ob[5]+trans.z;
	obList.push_back(GameObj(glass));

	free(bs);
	free(bo);
	free(ob);
	free(base);
	free(glass);
}
// Other function that is not part of game object
float randomize(float LO, float HI){
   float random =  (LO + (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * (HI-LO));
   return random;

}

#endif
