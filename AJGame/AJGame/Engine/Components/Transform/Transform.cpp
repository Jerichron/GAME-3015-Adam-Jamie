#include "Transform.h"

void Transform::Awake()
{
	sf::Transform ModelPos;
	sf::Transform ModelRot;
	sf::Transform ModelSca;
	ModelPos.translate(m_Position);
	ModelRot.rotate(m_Rotation);
	ModelSca.scale(m_Scale);
	sf::Transform Model = ModelPos * ModelRot * ModelSca;
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
	SetPosition(0,0);
	Model.rotate(m_Rotation);
	SetRotation(0);
	Model.scale(m_Scale);
	SetScale(1,1);
	transformMatrix = Model;
}

void Transform::LateUpdate()
{

}

void Transform::SetPosition(sf::Vector2f position)
{
	m_Position = position;
}

void Transform::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Transform::SetRotation(float rotation)
{
	m_Rotation = rotation;
}

void Transform::SetScale(sf::Vector2f scale)
{
	m_Scale = scale;
}

void Transform::SetScale(float x, float y)
{
	m_Scale.x = x;
	m_Scale.y = y;
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
