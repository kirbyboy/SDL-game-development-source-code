#ifndef __Enemy__
#define __Enemy__

#include <string>

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Enemy : public SDLGameObject
{
public:

	Enemy();

	void draw();
	void update();
	void clean();
	virtual void load(const LoaderParams* pParams);
};

class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Enemy();
	}
};

#endif // __Enemy__
