#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


class FluxEngine
{
public:
	static void Start();
	static bool Initialize();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

private:
	static bool IsExiting();
	static void GameLoop();



	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static sf::Event event;

};