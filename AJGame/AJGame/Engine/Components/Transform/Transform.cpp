#include "Transform.h"

void Transform::Awake()
{
	sf::Transform Model;
	Model.translate(m_Position);
	Model.rotate(m_Rotation);
	Model.scale(m_Scale);
	transformMatrix = Model;
}

void Transform::Start()
{

}


void Transform::Update()
{
	sf::Transform Model;
	Model = transformMatrix;
	Model.translate(m_Position);
	Model.rotate(m_Rotation);
	Model.scale(m_Scale);
	transformMatrix = Model;
}

void Transform::LateUpdate()
{

}

void Transform::SetPosition(sf::Vector2f position)
{
	m_Position = position;
}

void Transform::SetRotation(float rotation)
{
	m_Rotation = rotation;
}

void Transform::SetScale(sf::Vector2f scale)
{
	m_Scale = scale;
}

sf::Vector2f Transform::GetPosition()
{
	return m_Position;
}

float Transform::GetRotation()
{
	return m_Rotation;
}

sf::Vector2f Transform::GetScale()
{
	return m_Scale;
}


sf::Transform Transform::getWorldTransform() const
{
	return transformMatrix;
}
