#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Manager.h"
#include "Components\Audio\Audio.h"
#include "Components\Renderer\Mesh.h"
#include <SFML\Audio.hpp>
#include <SFML\Audio\Music.hpp>

class FluxEngine
{
public:
	FluxEngine();
	~FluxEngine();

	static void Start();
	static bool Initialize();

	enum GameState {
		Uninitialized, ShowingSplash,
		Paused, ShowingMenu, Playing, Exiting
	};


private:
	static bool IsExiting();
	static void GameLoop(sf::Time time, sf::Clock clock);
	static void LoadLevel();

	static const sf::Time	TimePerFrame;
	static GameState _gameState;


	static GameObjectManager _Manager;
	static sf::RenderWindow _mainWindow;
	static sf::Event event;
};