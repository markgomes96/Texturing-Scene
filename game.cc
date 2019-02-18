#ifndef GAME_CC
#define GAME_CC

#include "includes.h"
#include "game.h"
#include "globals.h"

Game::Game() 
{ }

void Game::init() 
{
	//initilize other objects
}

void Game::update() 
{
	//update gameobjects
}

void Game::render()
{
 buildHeritageHall();
}

//Input replay functions
void Game::mouse( int button, int state, int x, int y ) 
{
	input.mouse(button, state, x, y);
}
void Game::keyboard( unsigned char key, int x, int y ) 
{
	input.keyboard(key, x, y);
}
void Game::specialInput(int key, int x, int y) 
{
	input.specialInput(key, x, y);
}

#endif
