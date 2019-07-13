#ifndef __PlayState__
#define __PlayState__

#include <vector>

#include "GameState.h"
#include "Level.h"

class GameObject;
class SDLGameObject;

class PlayState : public GameState
{
public:
	
	virtual void update();
	virtual void render();
	
	virtual bool onEnter();
	virtual bool onExit();
	
	virtual std::string getStateID() const { return s_playID; }
	
private:

	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
	Level* pLevel;
	
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
};

#endif // __PlayState__
