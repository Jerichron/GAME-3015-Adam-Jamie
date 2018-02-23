#pragma once
#include <stdio.h>
#include "../Components.h"
#include "SFML/Graphics/Glsl.hpp"


#define X_AXIS sf::Vector3f(1,0,0)
#define Y_AXiS sf::Vector3f(0,1,0)
#define Z_AXIS sf::Vector3f(0,0,1)


class Transform : Components {

	Transform() : m_Position(), m_Rotation(), m_Scale(1, 1, 1) {}
	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	sf::Vector3f m_Position;
	sf::Vector3f m_Rotation;
	sf::Vector3f m_Scale;
	sf::Transform worldTransform;
	
};