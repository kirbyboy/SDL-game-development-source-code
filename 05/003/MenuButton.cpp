#include "MenuButton.h"
#include "Vector2D.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) : SDLGameObject(pParams), m_callback(callback)
{
	m_currentFrame = MOUSE_OUT; // start at frame 0
}

void MenuButton::draw()
{
	SDLGameObject::draw(); // use the base class drawing
}

void MenuButton::update()
{
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();
	
	if(pMousePos->getX() < (m_position.getX() + m_width)
	  && pMousePos->getX() > m_position.getX()
	  && pMousePos->getY() < (m_position.getY() + m_height)
	  && pMousePos->getY() > m_position.getY())
	{
		if(TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
		{
			m_currentFrame = CLICKED;
			m_callback(); // call our callback function
			m_bReleased = false;
		}
		else if(!TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}		
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}
