#pragma once
#include <stdio.h>
#include "../../Components.h"


class Transform : Components {
public:
	Transform() : m_Position(), m_Rotation(), m_Scale(1, 1) {}
	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	bool SendMessage(Messages* msg) { return false; }
	sf::Vector2f m_Position;
	float m_Rotation;
	sf::Vector2f m_Scale;

	sf::Transform transformMatrix;
	
};