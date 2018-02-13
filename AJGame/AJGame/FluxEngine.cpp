#include "FluxEngine.h"
#include <Windows.h>
#include <iostream>
using namespace std;

FluxEngine::GameState FluxEngine::_gameState;
sf::RenderWindow FluxEngine::_mainWindow;

void FluxEngine::Start(void)
{
	if (_gameState != Uninitialized)
		return;
	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Flux");
	_gameState = FluxEngine::Playing;

	while (!IsExiting())
	{
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

}

