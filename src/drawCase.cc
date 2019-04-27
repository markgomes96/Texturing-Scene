#ifndef DRAWCASE
#define DRAWCASE

#include "includes.h"
#include "game.h"
#include "prototypes.h"

extern GLuint textureID[100];

void drawDisplayCase()
{
/*
the cases are based off origin and the translated by these values
     x     y          x     y   
dc1:0.75  5.75   dc2:5.25  5.75

dc3:0.75  15.75  dc4:5.25  15.75

dc6:0.75  25.75  dc5:5.25  25.75 //order wise these get drawn on oppisite sides to the normal pattern so 5 is on the right side of heritage hall and 6 is on the left

dc7:0.75  35.75  dc8:5.25  35.75

dc9:0.75  45.75  dc10:5.25  45.75
*/


glEnable(GL_DEPTH_TEST);
glEnable(GL_TEXTURE_2D);
glDisable(GL_TEXTURE_2D);

/*dc 1*/



	/*bottom 1*/
	glPushMatrix();
	glTranslated(0.75,5.75,0.0);
	glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
	glPopMatrix();
glEnable(GL_TEXTURE_2D);
	/*top base 1*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
	glPushMatrix();
    glTranslated(0.75,5.75,0.4572);
	glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
	glPopMatrix();

	/*left base 1*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
	glPushMatrix();
	glTranslated(0.75,5.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.4572);
    glEnd();
    glPopMatrix();

	/*right base 1*/
    glPushMatrix();
	glTranslated(0.75,5.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.4572);
    glEnd();
    glPopMatrix();

	/*back base 1*/
    	glBindTexture(GL_TEXTURE_2D, textureID[43]);
	glPushMatrix();
	glTranslated(0.75,5.75,0.0);
   	glColor3f(0.0,1.0,1.0); 
	glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glEnd();
    glPopMatrix();

	/*front base 1*/
	glPushMatrix();
	glTranslated(0.75,5.75,0.0);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,0.0,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,0.0,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    glPopMatrix();

	/*front glass 1*/
	glBindTexture(GL_TEXTURE_2D, textureID[7]);
	glPushMatrix();
	glTranslated(0.75,5.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

	/*back glass 1*/
	glBindTexture(GL_TEXTURE_2D, textureID[5]);
	glPushMatrix();
	glTranslated(0.75,5.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

	/*left glass 1*/
	glBindTexture(GL_TEXTURE_2D, textureID[6]);
	glPushMatrix();
	glTranslated(0.75,5.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

	/*right glass 1*/
   	glBindTexture(GL_TEXTURE_2D, textureID[4]);
	glPushMatrix();
	glTranslated(0.75,5.75,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

	/*top glass 1*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
	glPushMatrix();
	glTranslated(0.75,5.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glEnd();
    glPopMatrix();

glDisable(GL_TEXTURE_2D);


/*dc 2*/


    /*bottom 2*/
    glPushMatrix();
    glTranslated(5.25,5.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

glEnable(GL_TEXTURE_2D);
    /*top base 2*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,5.75,0.4572);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*left base 2*/
    glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,5.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*right base 2*/
    glPushMatrix();
    glTranslated(5.25,5.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*back base 2*/
    glBindTexture(GL_TEXTURE_2D, textureID[43]);
    glPushMatrix();
    glTranslated(5.25,5.75,0.0);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glEnd();
    glPopMatrix();

    /*front base 2*/
    glPushMatrix();
    glTranslated(5.25,5.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,0.0,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,0.0,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*front glass 2*/
    glBindTexture(GL_TEXTURE_2D, textureID[38]);
    glPushMatrix();
    glTranslated(5.25,5.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 2*/
    glBindTexture(GL_TEXTURE_2D, textureID[36]);
    glPushMatrix();
    glTranslated(5.25,5.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 2*/
    glBindTexture(GL_TEXTURE_2D, textureID[40]);
    glPushMatrix();
    glTranslated(5.25,5.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*right glass 2*/
    glBindTexture(GL_TEXTURE_2D, textureID[39]);
    glPushMatrix();
    glTranslated(5.25,5.75,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 2*/
    glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glTranslated(5.25,5.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glEnd();
    glPopMatrix();

glDisable(GL_TEXTURE_2D);


/*dc 3*/


    /*bottom 3*/
    glPushMatrix();
    glTranslated(0.75,15.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

glEnable(GL_TEXTURE_2D);
    /*top base 3*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(0.75,15.75,0.4572);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*left base 3*/
    glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(0.75,15.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*right base 3*/
    glPushMatrix();
    glTranslated(0.75,15.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*back base 3*/
    glBindTexture(GL_TEXTURE_2D, textureID[43]);
    glPushMatrix();
    glTranslated(0.75,15.75,0.0);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glEnd();
    glPopMatrix();

    /*front base 3*/
    glPushMatrix();
    glTranslated(0.75,15.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,0.0,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,0.0,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*front glass 3*/
    glBindTexture(GL_TEXTURE_2D, textureID[11]);
    glPushMatrix();
    glTranslated(0.75,15.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 3*/
    glBindTexture(GL_TEXTURE_2D, textureID[9]);
    glPushMatrix();
    glTranslated(0.75,15.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 3*/
    glBindTexture(GL_TEXTURE_2D, textureID[10]);
    glPushMatrix();
    glTranslated(0.75,15.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*right glass 3*/
    glBindTexture(GL_TEXTURE_2D, textureID[8]);
    glPushMatrix();
    glTranslated(0.75,15.75,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 3*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(0.75,15.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glEnd();
    glPopMatrix();
glDisable(GL_TEXTURE_2D);


/*dc 4*/
    /*bottom 4*/
    glPushMatrix();
    glTranslated(5.25,15.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

glEnable(GL_TEXTURE_2D);
    /*top base 4*/
    glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glTranslated(5.25,15.75,0.4572);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*left base 4*/
    glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,15.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*right base 4*/
    glPushMatrix();
    glTranslated(5.25,15.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*back base 4*/
    glBindTexture(GL_TEXTURE_2D, textureID[43]);
    glPushMatrix();
    glTranslated(5.25,15.75,0.0);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glEnd();
    glPopMatrix();

    /*front base 4*/
    glPushMatrix();
    glTranslated(5.25,15.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,0.0,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,0.0,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*front glass 4*/
    glBindTexture(GL_TEXTURE_2D, textureID[15]);
    glPushMatrix();
    glTranslated(5.25,15.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 4*/
    glBindTexture(GL_TEXTURE_2D, textureID[13]);
    glPushMatrix();
    glTranslated(5.25,15.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 4*/
    glBindTexture(GL_TEXTURE_2D, textureID[14]);
    glPushMatrix();
    glTranslated(5.25,15.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*right glass 4*/
    glBindTexture(GL_TEXTURE_2D, textureID[12]);
    glPushMatrix();
    glTranslated(5.25,15.75,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 4*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,15.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glEnd();
    glPopMatrix();

glDisable(GL_TEXTURE_2D);
/*dc 5*/
    /*bottom 5*/
    glPushMatrix();
    glTranslated(5.25,25.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

glEnable(GL_TEXTURE_2D);
    /*top base 5*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,25.75,0.4572);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*left base 5*/
    glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,25.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*right base 5*/
    glPushMatrix();
    glTranslated(5.25,25.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*back base 5*/
    glBindTexture(GL_TEXTURE_2D, textureID[43]);
    glPushMatrix();
    glTranslated(5.25,25.75,0.0);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glEnd();
    glPopMatrix();

    /*front base 5*/
    glPushMatrix();
    glTranslated(5.25,25.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,0.0,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,0.0,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*front glass 5*/
    glBindTexture(GL_TEXTURE_2D, textureID[19]);
    glPushMatrix();
    glTranslated(5.25,25.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 5*/
    glBindTexture(GL_TEXTURE_2D, textureID[17]);
    glPushMatrix();
    glTranslated(5.25,25.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 5*/
    glBindTexture(GL_TEXTURE_2D, textureID[18]);
    glPushMatrix();
    glTranslated(5.25,25.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*right glass 5*/
    glBindTexture(GL_TEXTURE_2D, textureID[16]);
    glPushMatrix();
    glTranslated(5.25,25.75,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 5*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,25.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glEnd();
    glPopMatrix();

glDisable(GL_TEXTURE_2D);
/*dc 6*/
    /*bottom 6*/
    glPushMatrix();
    glTranslated(0.75,25.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

glEnable(GL_TEXTURE_2D);
    /*top base 6*/
    glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glTranslated(0.75,25.75,0.4572);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*left base 6*/
    glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(0.75,25.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*right base 6*/
    glPushMatrix();
    glTranslated(0.75,25.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*back base 6*/
    glBindTexture(GL_TEXTURE_2D, textureID[43]);
    glPushMatrix();
    glTranslated(0.75,25.75,0.0);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glEnd();
    glPopMatrix();

    /*front base 6*/
    glPushMatrix();
    glTranslated(0.75,25.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,0.0,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,0.0,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*front glass 6*/
    glBindTexture(GL_TEXTURE_2D, textureID[23]);
    glPushMatrix();
    glTranslated(0.75,25.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 6*/
    glBindTexture(GL_TEXTURE_2D, textureID[21]);
    glPushMatrix();
    glTranslated(0.75,25.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 6*/
    glBindTexture(GL_TEXTURE_2D, textureID[22]);
    glPushMatrix();
    glTranslated(0.75,25.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*right glass 6*/
    glBindTexture(GL_TEXTURE_2D, textureID[20]);
    glPushMatrix();
    glTranslated(0.75,25.75,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 6*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(0.75,25.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glEnd();
    glPopMatrix();

glDisable(GL_TEXTURE_2D);
/*dc 7*/
    /*bottom 7*/
    glPushMatrix();
    glTranslated(0.75,35.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

glEnable(GL_TEXTURE_2D);
    /*top base 7*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(0.75,35.75,0.4572);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*left base 7*/
    glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(0.75,35.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*right base 7*/
    glPushMatrix();
    glTranslated(0.75,35.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*back base 7*/
    glBindTexture(GL_TEXTURE_2D, textureID[43]);
    glPushMatrix();
    glTranslated(0.75,35.75,0.0);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glEnd();
    glPopMatrix();

    /*front base 7*/
    glPushMatrix();
    glTranslated(0.75,35.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,0.0,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,0.0,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*front glass 7*/
    glBindTexture(GL_TEXTURE_2D, textureID[27]);
    glPushMatrix();
    glTranslated(0.75,35.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 7*/
    glBindTexture(GL_TEXTURE_2D, textureID[25]);
    glPushMatrix();
    glTranslated(0.75,35.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 7*/
    glBindTexture(GL_TEXTURE_2D, textureID[26]);
    glPushMatrix();
    glTranslated(0.75,35.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*right glass 7*/
    glBindTexture(GL_TEXTURE_2D, textureID[24]);
    glPushMatrix();
    glTranslated(0.75,35.75,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 7*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(0.75,35.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glEnd();
    glPopMatrix();

glDisable(GL_TEXTURE_2D);
/*dc 8*/
    /*bottom 8*/
    glPushMatrix();
    glTranslated(5.25,35.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

glEnable(GL_TEXTURE_2D);
    /*top base 8*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,35.75,0.4572);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*left base 8*/
    glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,35.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*right base 8*/
    glPushMatrix();
    glTranslated(5.25,35.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*back base 8*/
    glBindTexture(GL_TEXTURE_2D, textureID[43]);
    glPushMatrix();
    glTranslated(5.25,35.75,0.0);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glEnd();
    glPopMatrix();

    /*front base 8*/
    glPushMatrix();
    glTranslated(5.25,35.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,0.0,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,0.0,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*front glass 8*/
    glBindTexture(GL_TEXTURE_2D, textureID[31]);
    glPushMatrix();
    glTranslated(5.25,35.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 8*/
    glBindTexture(GL_TEXTURE_2D, textureID[29]);
    glPushMatrix();
    glTranslated(5.25,35.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 8*/
    glBindTexture(GL_TEXTURE_2D, textureID[30]);
    glPushMatrix();
    glTranslated(5.25,35.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*right glass 8*/
    glBindTexture(GL_TEXTURE_2D, textureID[28]);
    glPushMatrix();
    glTranslated(5.25,35.75,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 8*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,35.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glEnd();
    glPopMatrix();

glDisable(GL_TEXTURE_2D);
/*dc 9*/
    /*bottom 9*/
    glPushMatrix();
    glTranslated(0.75,45.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

glEnable(GL_TEXTURE_2D);
    /*top base 9*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(0.75,45.75,0.4572);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*left base 9*/
    glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(0.75,45.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*right base 9*/
    glPushMatrix();
    glTranslated(0.75,45.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*back base 9*/
    glBindTexture(GL_TEXTURE_2D, textureID[43]);
    glPushMatrix();
    glTranslated(0.75,45.75,0.0);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glEnd();
    glPopMatrix();

    /*front base 9*/
    glPushMatrix();
    glTranslated(0.75,45.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,0.0,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,0.0,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*front glass 9*/
    glBindTexture(GL_TEXTURE_2D, textureID[35]);
    glPushMatrix();
    glTranslated(0.75,45.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 9*/
    glBindTexture(GL_TEXTURE_2D, textureID[33]);
    glPushMatrix();
    glTranslated(0.75,45.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 9*/
    glBindTexture(GL_TEXTURE_2D, textureID[34]);
    glPushMatrix();
    glTranslated(0.75,45.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*right glass 9*/
    glBindTexture(GL_TEXTURE_2D, textureID[32]);
    glPushMatrix();
    glTranslated(0.75,45.75,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 9*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(0.75,45.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glEnd();
    glPopMatrix();

glDisable(GL_TEXTURE_2D);

/*dc 10*/
    /*bottom 10*/
    glPushMatrix();
    glTranslated(5.25,45.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

glEnable(GL_TEXTURE_2D);
    /*top base 10*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,45.75,0.4572);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*left base 10*/
    glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,45.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*right base 10*/
    glPushMatrix();
    glTranslated(5.25,45.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,2.8702,0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,0.0,0.4572);
    glEnd();
    glPopMatrix();

    /*back base 10*/
    glBindTexture(GL_TEXTURE_2D, textureID[43]);
    glPushMatrix();
    glTranslated(5.25,45.75,0.0);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.0,2.8702,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.0,2.8702,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.5748,2.8702,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.5748,2.8702,0.0);
    glEnd();
    glPopMatrix();

    /*front base 10*/
    glPushMatrix();
    glTranslated(5.25,45.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.5748,0.0,0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.5748,0.0,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.0,0.0,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    glPopMatrix();

    /*front glass 10*/
    glBindTexture(GL_TEXTURE_2D, textureID[3]);
    glPushMatrix();
    glTranslated(5.25,45.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 10*/
    glBindTexture(GL_TEXTURE_2D, textureID[1]);
    glPushMatrix();
    glTranslated(5.25,45.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 10*/
    glBindTexture(GL_TEXTURE_2D, textureID[2]);
    glPushMatrix();
    glTranslated(5.25,45.75,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*right glass 10*/
    glBindTexture(GL_TEXTURE_2D, textureID[0]);
    glPushMatrix();
    glTranslated(5.25,45.75,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 10*/
	glBindTexture(GL_TEXTURE_2D, textureID[44]);
    glPushMatrix();
    glTranslated(5.25,45.75,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glEnd();
    glPopMatrix();

	glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

#endif
