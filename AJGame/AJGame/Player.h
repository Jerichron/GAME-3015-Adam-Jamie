#pragma once
#include "Engine\GameObject.h"


class Player : public GameObject
{
public:
	Player() {}
	Player(int uniqueID) : m_UniqueID(uniqueID), m_Parent(NULL) { }
	~Player() {}
	virtual void HandleEvent(Event* msg);

	virtual void			draw(sf::RenderTarget& target) const;

private:
	int m_UniqueID;
	std::vector<Components*> m_Components;
	GameObject* m_Parent;
	sf::Transform worldTransform;
	std::vector<GameObject*> m_Children;
};