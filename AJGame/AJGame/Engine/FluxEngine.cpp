#include "FluxEngine.h"
#include "../SplashScreen.h"
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

const sf::Time FluxEngine::TimePerFrame = sf::seconds(1.f / 60.f);
sf::RenderWindow FluxEngine::_mainWindow;
FluxEngine::GameState FluxEngine::_gameState;
sf::Event FluxEngine::event;
GameObjectManager FluxEngine::_Manager;
//Mesh FluxEngine::_Mesh;


FluxEngine::FluxEngine()
{
	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Flux");
	SplashScreen::Show(_mainWindow);
}

FluxEngine::~FluxEngine()
{
}

void FluxEngine::Start(void)
{
	if (_gameState != Uninitialized)
		return;
	_gameState = FluxEngine::Playing;
	LoadLevel();
	while (_mainWindow.isOpen())
	{

		while (_mainWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				_mainWindow.close();
				break;
			}
		}
		
		GameLoop();
	}
	_mainWindow.close();
}
bool FluxEngine::Initialize(void)
{
	//Memory

	__int64 lpFreeBytesAvailable = 0;
	__int64 lpTotalNumberOfBytes = 0;
	__int64 lpTotalNumberOfFreeBytes = 0;


	int Space = GetDiskFreeSpaceEx(NULL, (PULARGE_INTEGER)&lpFreeBytesAvailable, (PULARGE_INTEGER)&lpTotalNumberOfBytes, (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes);
	cout << "Current space available is: " << lpFreeBytesAvailable / 1024 << endl;

	if (lpFreeBytesAvailable / 1024 >= 300) {
		cout << "There is enough free space." << endl;
	}

	//RAM & VM------------------------------------------------------------------------------------------------------------------------------------------------------------------- 

	MEMORYSTATUSEX status;
	GlobalMemoryStatusEx(&status);
	cout << "Current physical RAM: " << status.ullTotalPhys << endl;
	cout << "Current virtual memory: " << status.ullAvailVirtual << endl;

	//CPU Speed------------------------------------------------------------------------------------------------------------------------------------------------------------------

	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD dwARc = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;

	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS) {
		// query the key:
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&dwMHz, &BufSize);
		cout << "CPU speed: " << dwMHz << endl;
	}
	return true;
}

bool FluxEngine::IsExiting(void)
{
	return false;
}
void FluxEngine::GameLoop(void)
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	//while (timeSinceLastUpdate > TimePerFrame)
	//{
		timeSinceLastUpdate -= TimePerFrame;

		_mainWindow.clear(sf::Color::Black);
		_Manager.Update(TimePerFrame.asSeconds());
		_Manager.draw(_mainWindow);
		_Manager.LateUpdate(TimePerFrame.asSeconds());

		_mainWindow.display();
	//}
}

void FluxEngine::LoadLevel() 
{
	GameObject* background = _Manager.CreateObject();;
	GameObject* sun = _Manager.CreateObject();

	background->transform.SetPosition(sf::Vector2f(0.0f, 0.0f));
	background->AddChild(sun);

	sun->transform.SetPosition(sf::Vector2f(50.0f, 50.0f));
	sun->transform.SetScale(sf::Vector2f(1.0, 1.0));
	

	background->mesh.setImage("../Assets/Night.jpg");
	sun->mesh.setImage("../Assets/Sun.jpg");

}
