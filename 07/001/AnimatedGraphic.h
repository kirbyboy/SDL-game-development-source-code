#ifndef __AnimatedGraphic__
#define __AnimatedGraphic__

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"

class AnimatedGraphic : public SDLGameObject
{
	public:
	
		AnimatedGraphic();
		
		virtual void draw();
		virtual void update();
		virtual void clean();
		virtual void load(const LoaderParams* pParams);
		
	private:
		int m_animSpeed;
};

class AnimatedGraphicCreator : public BaseCreator
{
public:
	GameObject* createGameObject() const
	{
		return new AnimatedGraphic();
	}
};

#endif /* defined(__AnimatedGraphic__) */
