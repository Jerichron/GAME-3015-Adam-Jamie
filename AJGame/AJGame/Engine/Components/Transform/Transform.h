#pragma once
#include <stdio.h>
#include "../../Components.h"


class Transform : public Components {

public:
	Transform() : m_Position(0.0f, 0.0f), m_Rotation(0.0f), m_Scale(1.0f, 1.0f) {}
	~Transform() {}
	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	void HandleMessage(Event* msg) {}

	void SetPosition(sf::Vector2f position);
	void SetPosition(float x, float y);
	void SetRotation(float rotation);
	void SetScale(sf::Vector2f scale);
	void SetScale(float x, float y);

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