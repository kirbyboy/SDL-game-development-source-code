#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"

class Game
{
public:

	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit() { m_bRunning = false; }
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	static Game* Instance()
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
	}

	int getGameWidth() const
	{
		return m_gameWidth;
	}
	
	int getGameHeight() const
	{
		return m_gameHeight;
	}
	
private:

	Game() {};

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

	bool m_bRunning;
	int m_currentFrame;
	int m_gameWidth;
	int m_gameHeight;

	GameStateMachine* m_pGameStateMachine;

	static Game* s_pInstance;
};

typedef Game TheGame;
#endif // __Game__
