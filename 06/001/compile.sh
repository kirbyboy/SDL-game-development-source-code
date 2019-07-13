g++ -O0 -g -std=c++11 main.cpp Game.cpp TextureManager.cpp Player.cpp Enemy.cpp SDLGameObject.cpp InputHandler.cpp PlayState.cpp GameStateMachine.cpp MenuButton.cpp PauseState.cpp AnimatedGraphic.cpp GameOverState.cpp GameObjectFactory.cpp StateParser.cpp MainMenuState.cpp tinystr.cpp tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp -o main `sdl2-config --cflags --libs` -lSDL2_image
