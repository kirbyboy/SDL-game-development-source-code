#include <string>
#include "SDL.h"

#include "Player.h"
#include "InputHandler.h"

Player::Player() : SDLGameObject() {}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	handleInput();
	
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	
	SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput()
{
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;
}

void Player::load(const LoaderParams *pParams)
{
	SDLGameObject::load(pParams);
}
