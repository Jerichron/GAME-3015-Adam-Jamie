#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Manager.h"
#include "World.h"
#include "Components\Renderer\Mesh.h"




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

	static const sf::Time	TimePerFrame;
	static GameState _gameState;


	static World m_World;
	static sf::RenderWindow _mainWindow;
	static sf::Event event;
};