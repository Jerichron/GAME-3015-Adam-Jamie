#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class FluxEngine
{
public:
	static void Start();
	static bool Initialize();

private:
	static bool IsExiting();
	static void GameLoop();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
};