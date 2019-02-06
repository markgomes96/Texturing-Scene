#ifndef GAME_CC
#define GAME_CC

#include "includes.h"

Game::Game() 
{ }

void Game::init(int window_width, int window_height) 
{
	//initilize other objects
}

void Game::update() 
{
	//update gameobjects
}

void Game::render() 
{
	//draw objects to screen
}

//Input replay functions
void mouse( int button, int state, int x, int y ) 
{
	input.mouse(button, state, x, y);
}
void keyboard( unsigned char key, int x, int y ) 
{
	input.keyboard(key, x, y);
}
void specialInput(int key, int x, int y) 
{
	input.specialInput(key, x, y);
}

#endif
