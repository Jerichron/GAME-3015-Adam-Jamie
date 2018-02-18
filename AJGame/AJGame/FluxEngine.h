#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameObject.h"


class FluxEngine
{
public:
	static void Start();
	static bool Initialize();
	static void GameLoop();


private:
	static bool IsExiting();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static GameObject mSceneGraph;

};