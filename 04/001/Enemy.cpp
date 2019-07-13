#include <string>
#include "SDL.h"

#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_position.setX(m_position.getX() + 1);
	m_position.setY(m_position.getY() + 1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean() {}
