#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Manager.h"
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
	static void GameLoop();
	static void LoadLevel();

	static const sf::Time	TimePerFrame;
	static GameState _gameState;

	static Mesh	_Mesh;
	static GameObjectManager _Manager;
	static sf::RenderWindow _mainWindow;
	static sf::Event event;
};