#ifndef __GameStateMachine__
#define __GameStateMachine__

#include <vector>

#include "GameState.h"

class GameStateMachine
{
public:

	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	
	void update();
	void render();
	
private:
	std::vector<GameState*> m_gameStates;
};

#endif // __GameStateMachine__
