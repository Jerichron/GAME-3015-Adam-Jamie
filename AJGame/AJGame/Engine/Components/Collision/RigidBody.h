#pragma once
#include "../../Components.h"
#include <SFML/Graphics/Transform.hpp>

#include <map>

class RigidBody : public Components
{
public:
	RigidBody() {}
	~RigidBody() {}

	void Update();

	sf::IntRect GetBody();
	void SetBody(sf::IntRect size);

	bool GetGravityOn();
	void SetGravityOn(bool value);

private:

	sf::IntRect m_Body;
	bool m_GravityOn;

};
