#ifndef DRAWCASE
#define DRAWCASE

#include "includes.h"
#include "game.h"
#include "prototypes.h"

extern GLuint textureID[50];

void drawDisplayCase()
{
glEnable(GL_DEPTH_TEST);
glEnable(GL_TEXTURE_2D);
/*dc 1*/
glDisable(GL_TEXTURE_2D);
	/*bottom 1*/
	glPushMatrix();
	glTranslated(0.5,0.25,0.0);
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

	/*top base 1*/
	glPushMatrix();
    glTranslated(0.5,0.25,0.4572);
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
	//glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(0.5,0.25,0.0);
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
    //glEnable(GL_TEXTURE_2D);
 
	/*right base 1*/	
    //glDisable(GL_TEXTURE_2D);	
    glPushMatrix();
	glTranslated(0.5,0.25,0.0);
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
    //glEnable(GL_TEXTURE_2D);

	/*back base 1*/
    //glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(0.5,0.25,0.0);
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
    //glEnable(GL_TEXTURE_2D);

	/*front base 1*/
	glPushMatrix();
	glTranslated(0.5,0.25,0.0);
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
	glPushMatrix();
	glTranslated(0.5,0.25,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();
	
	/*back glass 1*/
	glPushMatrix();
	glTranslated(0.5,0.25,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

	/*left glass 1*/
	glPushMatrix();
	glTranslated(0.5,0.25,0.0);
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
	
	/*right glass 1*/
    //glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(0.5,0.25,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();
    //glEnable(GL_TEXTURE_2D);

	/*top glass 1*/
	glPushMatrix();
	glTranslated(0.5,0.25,0.0);
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

/*dc 2*/
    /*bottom 2*/
    glPushMatrix();
    glTranslated(5.5,0.25,0.0);
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

    /*top base 2*/
    glPushMatrix();
    glTranslated(5.5,0.25,0.4572);
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
    glPushMatrix();
    glTranslated(5.5,0.25,0.0);
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
    glTranslated(5.5,0.25,0.0);
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
    glPushMatrix();
    glTranslated(5.5,0.25,0.0);
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
    glTranslated(5.5,0.25,0.0);
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
    glPushMatrix();
    glTranslated(5.5,0.25,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();
    
	/*back glass 2*/
    glPushMatrix();
    glTranslated(5.5,0.25,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 2*/
    glPushMatrix();
    glTranslated(5.5,0.25,0.0);
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

    /*right glass 2*/
    glPushMatrix();
    glTranslated(5.5,0.25,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 2*/
    glPushMatrix();
    glTranslated(5.5,0.25,0.0);
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

/*dc 3*/
    /*bottom 3*/
    glPushMatrix();
    glTranslated(0.5,8.6875,0.0);
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

    /*top base 3*/
    glPushMatrix();
    glTranslated(0.5,8.6875,0.4572);
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
    glPushMatrix();
    glTranslated(0.5,8.6875,0.0);
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
    glTranslated(0.5,8.6875,0.0);
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
    glPushMatrix();
    glTranslated(0.5,8.6875,0.0);
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
    glTranslated(0.5,8.6875,0.0);
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
    glPushMatrix();
    glTranslated(0.5,8.6875,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 3*/
    glPushMatrix();
    glTranslated(0.5,8.6875,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();
    
    /*left glass 3*/
    glPushMatrix();
    glTranslated(0.5,8.6875,0.0);
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

    /*right glass 3*/
    glPushMatrix();
    glTranslated(0.5,8.6875,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 3*/
    glPushMatrix();
    glTranslated(0.5,8.6875,0.0);
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

/*dc 4*/
    /*bottom 4*/
    glPushMatrix();
    glTranslated(5.5,8.6875,0.0);
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

    /*top base 4*/
    glPushMatrix();
    glTranslated(5.5,8.6875,0.4572);
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
    glPushMatrix();
    glTranslated(5.5,8.6875,0.0);
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
    glTranslated(5.5,8.6875,0.0);
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
    glPushMatrix();
    glTranslated(5.5,8.6875,0.0);
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
    glTranslated(5.5,8.6875,0.0);
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
    glPushMatrix();
    glTranslated(5.5,8.6875,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 4*/
    glPushMatrix();
    glTranslated(5.5,8.6875,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 4*/
    glPushMatrix();
    glTranslated(5.5,8.6875,0.0);
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

    /*right glass 4*/
    glPushMatrix();
    glTranslated(5.5,8.6875,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 4*/
    glPushMatrix();
    glTranslated(5.5,8.6875,0.0);
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

/*dc 5*/
    /*bottom 5*/
    glPushMatrix();
    glTranslated(5.5,17.375,0.0);
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

    /*top base 5*/
    glPushMatrix();
    glTranslated(5.5,17.375,0.4572);
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
    glPushMatrix();
    glTranslated(5.5,17.375,0.0);
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
    glTranslated(5.5,17.375,0.0);
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
    glPushMatrix();
    glTranslated(5.5,17.375,0.0);
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
    glTranslated(5.5,17.375,0.0);
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
    glPushMatrix();
    glTranslated(5.5,17.375,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 5*/
    glPushMatrix();
    glTranslated(5.5,17.375,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 5*/
    glPushMatrix();
    glTranslated(5.5,17.375,0.0);
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

    /*right glass 5*/
    glPushMatrix();
    glTranslated(5.5,17.375,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 5*/
    glPushMatrix();
    glTranslated(5.5,17.375,0.0);
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

/*dc 6*/
    /*bottom 6*/
    glPushMatrix();
    glTranslated(0.5,17.375,0.0);
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

    /*top base 6*/
    glPushMatrix();
    glTranslated(0.5,17.375,0.4572);
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
    glPushMatrix();
    glTranslated(0.5,17.375,0.0);
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
    glTranslated(0.5,17.375,0.0);
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
    glPushMatrix();
    glTranslated(0.5,17.375,0.0);
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
    glTranslated(0.5,17.375,0.0);
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
    glPushMatrix();
    glTranslated(0.5,17.375,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 6*/
    glPushMatrix();
    glTranslated(0.5,17.375,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 6*/
    glPushMatrix();
    glTranslated(0.5,17.375,0.0);
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

    /*right glass 6*/
    glPushMatrix();
    glTranslated(0.5,17.375,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 6*/
    glPushMatrix();
    glTranslated(0.5,17.375,0.0);
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

/*dc 7*/
    /*bottom 7*/
    glPushMatrix();
    glTranslated(0.5,26.0625,0.0);
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

    /*top base 7*/
    glPushMatrix();
    glTranslated(0.5,26.0625,0.4572);
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
    glPushMatrix();
    glTranslated(0.5,26.0625,0.0);
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
    glTranslated(0.5,26.0625,0.0);
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
    glPushMatrix();
    glTranslated(0.5,26.0625,0.0);
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
    glTranslated(0.5,26.0625,0.0);
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
    glPushMatrix();
    glTranslated(0.5,26.0625,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 7*/
    glPushMatrix();
    glTranslated(0.5,26.0625,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 7*/
    glPushMatrix();
    glTranslated(0.5,26.0625,0.0);
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

    /*right glass 7*/
    glPushMatrix();
    glTranslated(0.5,26.0625,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 7*/
    glPushMatrix();
    glTranslated(0.5,26.0625,0.0);
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

/*dc 8*/
    /*bottom 8*/
    glPushMatrix();
    glTranslated(5.5,26.0625,0.0);
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

    /*top base 8*/
    glPushMatrix();
    glTranslated(5.5,26.0625,0.4572);
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
    glPushMatrix();
    glTranslated(5.5,26.0625,0.0);
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
    glTranslated(5.5,26.0625,0.0);
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
    glPushMatrix();
    glTranslated(5.5,26.0625,0.0);
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
    glTranslated(5.5,26.0625,0.0);
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
    glPushMatrix();
    glTranslated(5.5,26.0625,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 8*/
    glPushMatrix();
    glTranslated(5.5,26.0625,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 8*/
    glPushMatrix();
    glTranslated(5.5,26.0625,0.0);
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

    /*right glass 8*/
    glPushMatrix();
    glTranslated(5.5,26.0625,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 8*/
    glPushMatrix();
    glTranslated(5.5,26.0625,0.0);
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

/*dc 9*/
    /*bottom 9*/
    glPushMatrix();
    glTranslated(0.5,35.0,0.0);
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

    /*top base 9*/
    glPushMatrix();
    glTranslated(0.5,35.0,0.4572);
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
    glPushMatrix();
    glTranslated(0.5,35.0,0.0);
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
    glTranslated(0.5,35.0,0.0);
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
    glPushMatrix();
    glTranslated(0.5,35.0,0.0);
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
    glTranslated(0.5,35.0,0.0);
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
    glPushMatrix();
    glTranslated(0.5,35.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,0.127,0.4572);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,2.5146);
    glEnd();
    glPopMatrix();

    /*back glass 9*/
    glPushMatrix();
    glTranslated(0.5,35.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*left glass 9*/
    glPushMatrix();
    glTranslated(0.5,35.0,0.0);
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
    glPushMatrix();
    glTranslated(0.5,35.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.4478,0.127,2.5146);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.4478,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.4478,2.7432,0.4572);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.4478,0.127,0.4572);
    glEnd();
    glPopMatrix();

    /*top glass 9*/
    glPushMatrix();
    glTranslated(0.5,35.0,0.0);
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

/*dc 10*/
    /*bottom 10*/
    glPushMatrix();
    glTranslated(5.5,35.0,0.0);
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

    /*top base 10*/
    glPushMatrix();
    glTranslated(5.5,35.0,0.4572);
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
    glPushMatrix();
    glTranslated(5.5,35.0,0.0);
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
    glTranslated(5.5,35.0,0.0);
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
    glPushMatrix();
    glTranslated(5.5,35.0,0.0);
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
    glTranslated(5.5,35.0,0.0);
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

	glEnable(GL_TEXTURE_2D);

    /*front glass 10*/
    glBindTexture(GL_TEXTURE_2D, textureID[3]);
    glPushMatrix();
    glTranslated(5.5,35.0,0.0);
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
    glTranslated(5.5,35.0,0.0);
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
    glTranslated(5.5,35.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(0.127,2.7432,2.5146);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(0.127,0.127,2.5146);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(0.127,0.127,0.4572);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(0.127,2.7432,0.4572);
    glEnd();
    glPopMatrix();

    /*right glass 10*/
    glBindTexture(GL_TEXTURE_2D, textureID[0]);
    glPushMatrix();
    glTranslated(5.5,35.0,0.0);
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

    glDisable(GL_TEXTURE_2D);

    /*top glass 10*/
    glPushMatrix();
    glTranslated(5.5,35.0,0.0);
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
}

#endif 