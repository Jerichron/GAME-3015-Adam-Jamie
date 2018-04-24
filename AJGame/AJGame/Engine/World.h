#pragma once
#include "Manager.h"
#include "EventSystem.h"

class World
{
public:
	World() {}
	~World() {};

	void LoadLevel();
	void UpdateWorld(float msec);
	void DrawWorld(sf::RenderWindow& target);
	void DestoryWorld();

private:
	static GameObjectManager _Manager;
};