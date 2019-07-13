#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState *pState)
{
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popStatePrivate()
{
	if(!m_gameStates.empty())
	{
		if(m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}

void GameStateMachine::changeStatePrivate(GameState* pState)
{
	if(!m_gameStates.empty())
	{
		if(m_gameStates.back()->getStateID() == pState->getStateID())
		{
			return; // do nothing
		}

		if(m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
		
		// We check if the State exists in the StateMachine, if it exists
		// we eliminate them to free memory and an unneeded State.  This
		// fix is only for book examples, in real FSM this is not a good
		// idea(or it is, beats me).
		for(auto it = m_gameStates.begin(); it != m_gameStates.end(); ++it)
		{
			if(((*it)->getStateID() == pState->getStateID()) && ((*it)->onExit()))
			{
				delete (*it);
				m_gameStates.erase(it);
				break;
			}
		}
	}
	
	// push back our new state
	m_gameStates.push_back(pState);
	
	// initialise it
	m_gameStates.back()->onEnter();
}

void GameStateMachine::update()
{
	if(!m_gameStates.empty())
	{
		m_gameStates.back()->update();
	}
	
	if(changeStateFlag)
	{
		changeStatePrivate(newState);
		changeStateFlag = false;
	}
	else if(popStateFlag)
	{
		popStatePrivate();
		popStateFlag = false;
	}
}

void GameStateMachine::render()
{
	if(!m_gameStates.empty())
	{
		m_gameStates.back()->render();
	}
}

void GameStateMachine::popState()
{
	popStateFlag = true;
}

void GameStateMachine::changeState(GameState* pState)
{
	changeStateFlag = true;
	newState = pState;
}
