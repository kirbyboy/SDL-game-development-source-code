#ifndef __ObjectLayer__
#define __ObjectLayer__

#include <vector>

#include "GameObject.h"
#include "Layer.h"

class ObjectLayer : public Layer
{
public:
	virtual void update();
	virtual void render();
	
	std::vector<GameObject*>* getGameObjects()
	{
		return &m_gameObjects;
	}
	
private:
	std::vector<GameObject*> m_gameObjects;
};

#endif // __ObjectLayer__
