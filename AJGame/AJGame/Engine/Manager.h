#pragma once
#include <stdio.h>
#include "GameObject.h"
#include "iostream"
#include <map>
#include <list>
#include <iterator>

class GameObjectManager
{
public:
	void HandleEvent(Event* msg) {}
	GameObject* CreateObject();

	

	void Update(float msec);
	void Awake();
	void Start();
	void LateUpdate(float msec);

	void CheckInput();
	void draw(sf::RenderWindow& target);

private:
	std::map<int, GameObject*> m_Objects;
	static int nextObjectID;
};