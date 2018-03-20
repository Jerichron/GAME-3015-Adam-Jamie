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

	void SetPosition(sf::Vector2f position);
	void SetRotation(float rotation);
	void SetScale(sf::Vector2f scale);

	sf::Vector2f GetPosition();
	float GetRotation();
	sf::Vector2f GetScale();

	sf::Transform getWorldTransform() const;

private:

	sf::Vector2f m_Position;
	float m_Rotation;
	sf::Vector2f m_Scale;
	sf::Transform transformMatrix;
	
};