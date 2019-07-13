#ifndef __MenuButton__
#define __MenuButton__

#include "LoaderParams.h"
#include "SDLGameObject.h"

class MenuButton : public SDLGameObject
{
public:

	MenuButton(const LoaderParams* pParams, void (*callback)());
	
	virtual void draw();
	virtual void update();
	virtual void clean();
	
private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	
	void(*m_callback)();
	bool m_bReleased;
};

#endif // __MenuButton__
