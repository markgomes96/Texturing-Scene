#ifndef MENU
#define MENU
#include "includes.h"
#include <string.h>
#include <stdio.h>

extern const int WINDOW_MAX_X, WINDOW_MAX_Y;
extern int score;
extern int startT, startP, pauseT;
void makeString(float x, float y, void *font, const char* string)
{
        const char *c;
        glRasterPos2f(x,y);
        for(c=string; *c!='\0'; c++)
        {
                glutBitmapCharacter(font, *c);
        }
}

void textToScreen(const char* message, float x, float y)
{
        char *charString = (char*) malloc(12*sizeof(char));
        sprintf(charString, message);
        glColor3ub(0,0,0);
        makeString(x, y, GLUT_BITMAP_TIMES_ROMAN_24, charString);
        free(charString);
}

void drawTitle(int x, int y, int z, char title [])
{
	int strnglngth;
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(x, y, z);
        glScalef(1.5f, 1.5f, z);
        strnglngth = (int) strlen(title);
        for(int i = 0; i < strnglngth; i++)
        {
                glutStrokeCharacter(GLUT_STROKE_ROMAN, title[i]);
        }

        glPopMatrix();

}

void drawBoundaries()
{
	glColor3ub(255, 140, 0);
        glBegin(GL_POLYGON);
                glVertex2i(WINDOW_MAX_X-100, WINDOW_MAX_Y-100);
                glVertex2i(WINDOW_MAX_X-100, (WINDOW_MAX_Y/WINDOW_MAX_Y)*100);
                glVertex2i((WINDOW_MAX_X/WINDOW_MAX_X)*100, (WINDOW_MAX_Y/WINDOW_MAX_Y)*100);
                glVertex2i((WINDOW_MAX_X/WINDOW_MAX_X)*100, WINDOW_MAX_Y -100);
        glEnd();

	glColor3ub(0, 0, 0);

        glPushMatrix();

        glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.39), WINDOW_MAX_Y*(0.57));
                glVertex2i(WINDOW_MAX_X*(0.39), WINDOW_MAX_Y*(0.47));
        glEnd();

        glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.39), WINDOW_MAX_Y*(0.47));
                glVertex2i(WINDOW_MAX_X*(0.59), WINDOW_MAX_Y*(0.47));
 glEnd();

        glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.59), WINDOW_MAX_Y*(0.47));
                glVertex2i(WINDOW_MAX_X*(0.59), WINDOW_MAX_Y*(0.57));
        glEnd();

	glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.59), WINDOW_MAX_Y*(0.57));
                glVertex2i(WINDOW_MAX_X*(0.39), WINDOW_MAX_Y*(0.57));
        glEnd();


	 glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.39), WINDOW_MAX_Y*(0.46));
                glVertex2i(WINDOW_MAX_X*(0.39), WINDOW_MAX_Y*(0.36));
        glEnd();

        glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.39), WINDOW_MAX_Y*(0.36));
                glVertex2i(WINDOW_MAX_X*(0.59), WINDOW_MAX_Y*(0.36));
        glEnd();

        glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.59), WINDOW_MAX_Y*(0.36));
                glVertex2i(WINDOW_MAX_X*(0.59), WINDOW_MAX_Y*(0.46));
        glEnd();

        glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.59), WINDOW_MAX_Y*(0.46));
                glVertex2i(WINDOW_MAX_X*(0.39), WINDOW_MAX_Y*(0.46));
        glEnd();


	  glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.39), WINDOW_MAX_Y*(0.35));
                glVertex2i(WINDOW_MAX_X*(0.39), WINDOW_MAX_Y*(0.25));
        glEnd();

        glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.39), WINDOW_MAX_Y*(0.25));
                glVertex2i(WINDOW_MAX_X*(0.59), WINDOW_MAX_Y*(0.25));
        glEnd();

        glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.59), WINDOW_MAX_Y*(0.25));
                glVertex2i(WINDOW_MAX_X*(0.59), WINDOW_MAX_Y*(0.35));
        glEnd();

        glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.59), WINDOW_MAX_Y*(0.35));
                glVertex2i(WINDOW_MAX_X*(0.39), WINDOW_MAX_Y*(0.35));
        glEnd();

        glPopMatrix();
}


void drawInstructBounds()
{
        glColor3ub(255, 140, 0);
        glBegin(GL_POLYGON);
                glVertex2i(WINDOW_MAX_X-100, WINDOW_MAX_Y-100);
                glVertex2i(WINDOW_MAX_X-100, (WINDOW_MAX_Y/WINDOW_MAX_Y)*100);
                glVertex2i((WINDOW_MAX_X/WINDOW_MAX_X)*100, (WINDOW_MAX_Y/WINDOW_MAX_Y)*100);
                glVertex2i((WINDOW_MAX_X/WINDOW_MAX_X)*100, WINDOW_MAX_Y -100);
        glEnd();

        glColor3ub(0, 0, 0);
	 glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.45), WINDOW_MAX_Y*(0.25));
                glVertex2i(WINDOW_MAX_X*(0.45), WINDOW_MAX_Y*(0.15));
        glEnd();

        glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.45), WINDOW_MAX_Y*(0.15));
                glVertex2i(WINDOW_MAX_X*(0.55), WINDOW_MAX_Y*(0.15));
        glEnd();

        glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.55), WINDOW_MAX_Y*(0.15));
                glVertex2i(WINDOW_MAX_X*(0.55), WINDOW_MAX_Y*(0.25));
        glEnd();

        glBegin(GL_LINES);
                glVertex2i(WINDOW_MAX_X*(0.55), WINDOW_MAX_Y*(0.25));
                glVertex2i(WINDOW_MAX_X*(0.45), WINDOW_MAX_Y*(0.25));
        glEnd();

}

void startDisplay()
{
        char name [] = "BFO";
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, WINDOW_MAX_X, 0, WINDOW_MAX_Y);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        drawBoundaries();
        drawTitle(WINDOW_MAX_X*(0.40), WINDOW_MAX_Y*(0.6), 1.0f, name);
        textToScreen("Start Game" , WINDOW_MAX_X*(0.46), WINDOW_MAX_Y*(0.51));
        textToScreen("Instructions", WINDOW_MAX_X*(0.46), WINDOW_MAX_Y*(0.4));
        textToScreen("Leave Game", WINDOW_MAX_X*(0.46), WINDOW_MAX_Y*(0.29));
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
}

void instructScreenText()
{
        textToScreen("See how many ta", WINDOW_MAX_X*(0.417), WINDOW_MAX_Y*(0.54));
        textToScreen("rgets you can hit!", WINDOW_MAX_X*(0.505), WINDOW_MAX_Y*(0.54));
        textToScreen("W = move ahead", WINDOW_MAX_X*(0.25), WINDOW_MAX_Y*(0.46));
        textToScreen("S = move back", WINDOW_MAX_X*(0.40), WINDOW_MAX_Y*(0.46));
        textToScreen("A = move left", WINDOW_MAX_X*(0.55), WINDOW_MAX_Y*(0.46));
        textToScreen("D = move right", WINDOW_MAX_X*(0.70), WINDOW_MAX_Y*(0.46));
        textToScreen("Click = throw", WINDOW_MAX_X*(0.25), WINDOW_MAX_Y*(0.38));
        textToScreen("Z = make smaller", WINDOW_MAX_X*(0.40), WINDOW_MAX_Y*(0.38));
        textToScreen("X = make bigger", WINDOW_MAX_X*(0.55), WINDOW_MAX_Y*(0.38));
        textToScreen("R = reverse", WINDOW_MAX_X*(0.70), WINDOW_MAX_Y*(0.38));
        textToScreen("P = pause game", WINDOW_MAX_X*(0.40), WINDOW_MAX_Y*(0.30));
        textToScreen("Q = quit game", WINDOW_MAX_X*(0.55), WINDOW_MAX_Y*(0.30));
        textToScreen("BACK", WINDOW_MAX_X*(0.485), WINDOW_MAX_Y*(0.19));
}

void instructDisplay()
{
        char name []= "Controls";
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, WINDOW_MAX_X, 0, WINDOW_MAX_Y);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        drawInstructBounds();
        instructScreenText();
        drawTitle(WINDOW_MAX_X*(0.30), WINDOW_MAX_Y*(0.6), 1.0f, name);

        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);

}

void pauseDisplay()
{
        char name []= "BFO";
	char *timeLeft = (char*) malloc(12*sizeof(char));
	int time = 120000 -  ((glutGet(GLUT_ELAPSED_TIME)- startT) -pauseT - (glutGet(GLUT_ELAPSED_TIME) -startP));
	sprintf(timeLeft, "Time Left: %d seconds", time/1000);
	cout << pauseT << endl;
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, WINDOW_MAX_X, 0, WINDOW_MAX_Y);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        drawTitle(WINDOW_MAX_X*(0.40), WINDOW_MAX_Y*(0.6), 1.0, name);
 	textToScreen("Resume Game" , WINDOW_MAX_X*(0.46), WINDOW_MAX_Y*(0.51));
        textToScreen(timeLeft, WINDOW_MAX_X*(0.46), WINDOW_MAX_Y*(0.4));
        textToScreen("Leave Game", WINDOW_MAX_X*(0.46), WINDOW_MAX_Y*(0.29));
        drawBoundaries();
 glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
}

void overDisplay()
{
        char name [] = "GAME OVER";
        char *scoreTex = (char*) malloc(12*sizeof(char));
        sprintf(scoreTex, "Your score: %d", score);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, WINDOW_MAX_X, 0, WINDOW_MAX_Y);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
textToScreen(scoreTex, WINDOW_MAX_X*(0.46), WINDOW_MAX_Y*(0.51));
        textToScreen("Play Again", WINDOW_MAX_X*(0.46), WINDOW_MAX_Y*(0.4));
        textToScreen("Leave Game", WINDOW_MAX_X*(0.46), WINDOW_MAX_Y*(0.29));
        drawBoundaries();
        drawTitle(WINDOW_MAX_X*(0.20), WINDOW_MAX_Y*(0.6), 1.0, name);
 glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);


}
#endif
