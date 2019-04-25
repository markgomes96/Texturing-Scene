#ifndef GAME_CC
#define GAME_CC

#include "includes.h"
#include "game.h"
#include "prototypes.h"

extern void buildDisplay();
extern void buildCameraScene();
extern void buildHeritageHall();
extern double directX,directY, directZ, scaleAccX, scaleAccY, scaleAccZ, power;
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

    /*
    // ***Test objects for phyiscs***
    floor = GameObj(vertex(0.0, 0.0, -3.0, 1.0), vect3(5.0, 5.0, 1.0), true);		// (position, scale, isStatic)

    senerio one - collision in z-axis
    cube = GameObj(vertex(1.0, 2.0, 5.0, 1.0), vect3(1.0, 1.0, 1.0), false);
    cube2 = GameObj(vertex(0.0, 1.0, 10.0, 1.0), vect3(1.0, 1.0, 1.0), false);


    // senerio two - collision in x-axis
    cube = GameObj(vertex(4.0, 0.0, 7.0, 1.0), vect3(1.0, 1.0, 1.0), false);
    cube2 = GameObj(vertex(-4.0, 0.0, 7.0, 1.0), vect3(0.5, 0.5, 0.5), false);
    cube.velocity = vect3(-3.0, 0.0, 0.0);
    cube2.velocity = vect3(3.0, 0.0, 0.0);

    golist.push_back(floor);
    golist.push_back(cube);

    loadTextures();
    cout << "init" << endl;

    golist.push_back(cube2);
    floor = GameObj(vertex(0.0, 0.0, 0.0, 1.0), vect3(5.0, 5.0, 1.0), true);		// (position, scale, isStatic)
    cube = GameObj(vertex(0.0, 0.0, 6.0, 1.0), vect3(1.0, 3.0, 1.0), false);
    //	golist.push_back(floor);
    //	golist.push_back(cube);*/

}

// Create throwing object
void Game::createProjectile(double a1, double a2, double a3, double a4, double b1, double b2, double b3){
    GameObj projectile = GameObj(vertex(a1,a2,a3,a4), vect3(b1,b2,b3), false, true);
    directX =  ((double)cameraTarget.x - (double)cameraPos.x) * power;
    directY =  ((double)cameraTarget.y - (double)cameraPos.y) * power;
    directZ =  ((double)cameraTarget.z - (double)cameraPos.z) * power;
    projectile.updateVelo(directX, directY, directZ);
    projectile.updateAcc(addAcc[0], addAcc[1], addAcc[2]);
    golist.push_back(projectile);
}

// Create an object where the eye is
void Game::createEye(double a1, double a2, double a3, double a4, double b1, double b2, double b3){
    GameObj projectile = GameObj(vertex(a1,a2,a3,a4), vect3(b1,b2,b3), false);
    golist.push_back(projectile);
}

void Game::update()
{
    // Update each phyisc object
    physEng.updateObjects(golist);

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

		// draw game objects
    for(int i = 0; i < golist.size(); i++)
    {
        drawObject(golist[i]);

        /*
		if(golist[i].isScene)
		{
				drawBounds(&golist[i].bounds[0]);
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

    /*
    if(go.drawBounds)
        drawBounds(&go.bounds[0]);
    */
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
	float *go = (float*) malloc(6*sizeof(float));
	float *base = (float*) malloc(6*sizeof(float));
	float *glass = (float*) malloc(6*sizeof(float));

	// *** floor *** -> large floor supports entire scene
	bs[0]= -5.0; bs[1] = 12.0; bs[2]= -18.0; bs[3]= 55.0; bs[4] = -1.0; bs[5]= 0.0;
	golist.push_back(GameObj(bs));

    // *** ceiling *** -> flat all the way through, no arches
    bs[0]= -5.0; bs[1] = 12.0; bs[2]= -18.0; bs[3]= 55.0; bs[4] = 5.4864; bs[5]= 7.0;
	golist.push_back(GameObj(bs));

    // *** walls ***
    // left wall
    bs[0]= -1.0; bs[1] = 0.2; bs[2]= -18.0; bs[3]= 55.0; bs[4] = 0.0; bs[5]= 5.4864;
	golist.push_back(GameObj(bs));

    // right wall
    bs[0]= 7.0; bs[1] = 8.0; bs[2]= -18.0; bs[3]= 55.0; bs[4] = 0.0; bs[5]= 5.4864;
	golist.push_back(GameObj(bs));

    // back wall
    bs[0]= -5.0; bs[1] = 12.0; bs[2]= -7.6; bs[3]= -6.6; bs[4] = 0.0; bs[5]= 5.4864;
    golist.push_back(GameObj(bs));

    // front wall
    bs[0]= -5.0; bs[1] = 12.0; bs[2]= 54.9; bs[3]= 55.9; bs[4] = 0.0; bs[5]= 5.4864;
    golist.push_back(GameObj(bs));

    // *** display cases **** -> base and glass box colliders
	bo[0] = 0.0; bo[1] = 1.5748; bo[2]= 0.0; bo[3]= 2.8702; bo[4] = 0.0; bo[5]= 0.4572;
	go[0]= 0.127; go[1] = 1.4478; go[2]=  0.127; go[3]= 2.7432; go[4] = 0.4572; go[5]= 2.5146;
	base[0] = 0.0; base[1] = 0.0; base[2]= 0.0; base[3]= 0.0; base[4] = 0.0; base[5]= 0.0;
	glass[0]= 0.0; glass[1] = 0.0; glass[2]=  0.0; glass[3]= 0.0; glass[4] = 0.0; glass[5]= 0.0;

	vect3 orig = vect3(0.0,5.75,0.0);
	vect3 trans = vect3(0.0,0.0,0.0);
	vect3 mod = vect3(0.0,0.0,0.0);

	// case 1
	mod = vect3(0.5,0.25,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	golist.push_back(GameObj(base));
	glass[0] = go[0]+trans.x; glass[1] = go[1]+trans.x; glass[2] = go[2]+trans.y; glass[3] = go[3]+trans.y; glass[4] = go[4]+trans.z; glass[5] = go[5]+trans.z;
	golist.push_back(GameObj(glass));

	// case 2
	mod = vect3(5.5,0.25,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	golist.push_back(GameObj(base));
	glass[0] = go[0]+trans.x; glass[1] = go[1]+trans.x; glass[2] = go[2]+trans.y; glass[3] = go[3]+trans.y; glass[4] = go[4]+trans.z; glass[5] = go[5]+trans.z;
	golist.push_back(GameObj(glass));

	// case 3
	mod = vect3(0.5,8.6875,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	golist.push_back(GameObj(base));
	glass[0] = go[0]+trans.x; glass[1] = go[1]+trans.x; glass[2] = go[2]+trans.y; glass[3] = go[3]+trans.y; glass[4] = go[4]+trans.z; glass[5] = go[5]+trans.z;
	golist.push_back(GameObj(glass));

	// case 4
	mod = vect3(5.5,8.6875,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	golist.push_back(GameObj(base));
	glass[0] = go[0]+trans.x; glass[1] = go[1]+trans.x; glass[2] = go[2]+trans.y; glass[3] = go[3]+trans.y; glass[4] = go[4]+trans.z; glass[5] = go[5]+trans.z;
	golist.push_back(GameObj(glass));

	// case 5
	mod = vect3(5.5,17.375,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	golist.push_back(GameObj(base));
	glass[0] = go[0]+trans.x; glass[1] = go[1]+trans.x; glass[2] = go[2]+trans.y; glass[3] = go[3]+trans.y; glass[4] = go[4]+trans.z; glass[5] = go[5]+trans.z;
	golist.push_back(GameObj(glass));

	// case 6
	mod = vect3(0.5,17.375,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	golist.push_back(GameObj(base));
	glass[0] = go[0]+trans.x; glass[1] = go[1]+trans.x; glass[2] = go[2]+trans.y; glass[3] = go[3]+trans.y; glass[4] = go[4]+trans.z; glass[5] = go[5]+trans.z;
	golist.push_back(GameObj(glass));

	// case 7
	mod = vect3(0.5,26.0625,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	golist.push_back(GameObj(base));
	glass[0] = go[0]+trans.x; glass[1] = go[1]+trans.x; glass[2] = go[2]+trans.y; glass[3] = go[3]+trans.y; glass[4] = go[4]+trans.z; glass[5] = go[5]+trans.z;
	golist.push_back(GameObj(glass));

	// case 8
	mod = vect3(5.5,26.0625,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	golist.push_back(GameObj(base));
	glass[0] = go[0]+trans.x; glass[1] = go[1]+trans.x; glass[2] = go[2]+trans.y; glass[3] = go[3]+trans.y; glass[4] = go[4]+trans.z; glass[5] = go[5]+trans.z;
	golist.push_back(GameObj(glass));

	// case 9
	mod = vect3(0.5,35.0,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	golist.push_back(GameObj(base));
	glass[0] = go[0]+trans.x; glass[1] = go[1]+trans.x; glass[2] = go[2]+trans.y; glass[3] = go[3]+trans.y; glass[4] = go[4]+trans.z; glass[5] = go[5]+trans.z;
	golist.push_back(GameObj(glass));

	// case 10
	mod = vect3(5.5,35.0,0.0);
	trans = vect3( (orig.x+mod.x), (orig.y+mod.y), (orig.z+mod.z) );
	base[0] = bo[0]+trans.x; base[1] = bo[1]+trans.x; base[2] = bo[2]+trans.y; base[3] = bo[3]+trans.y; base[4] = bo[4]+trans.z; base[5] = bo[5]+trans.z;
	golist.push_back(GameObj(base));
	glass[0] = go[0]+trans.x; glass[1] = go[1]+trans.x; glass[2] = go[2]+trans.y; glass[3] = go[3]+trans.y; glass[4] = go[4]+trans.z; glass[5] = go[5]+trans.z;
	golist.push_back(GameObj(glass));

	free(bs);
	free(bo);
	free(go);
	free(base);
	free(glass);
}

#endif
