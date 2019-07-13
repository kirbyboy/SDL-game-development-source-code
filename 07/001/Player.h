#ifndef __Player__
#define __Player__

#include <string>

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Player : public SDLGameObject
{
public:

	Player();

	void draw();
	void update();
	void clean();
	void load(const LoaderParams* pParams);
	
private:
	void handleInput();
	
};

class PlayerCreator : public BaseCreator
{
public:	
	GameObject* createGameObject() const
	{
		return new Player();
	}
};

#endif // __Player__
