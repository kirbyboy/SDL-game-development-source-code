#include <string>
#include <iostream>

#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameObject.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "LoaderParams.h"
#include "StateParser.h"
#include "LevelParser.h"
#include "Level.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	pLevel->update();
}

void PlayState::render()
{
	pLevel->render();
}

bool PlayState::onEnter()
{
	LevelParser levelParser;
	pLevel = levelParser.parseLevel("map1.tmx");
	
	std::cout << "entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState" << std::endl;
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{	
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	
	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();
	
	// Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();
	
	// If any of the sides from A are outside of B
	if(bottomA <= topB) { return false; }
	if(topA >= bottomB) { return false; }
	if(rightA <= leftB) { return false; }
	if(leftA >= rightB) { return false; }
	
	return true;
}
