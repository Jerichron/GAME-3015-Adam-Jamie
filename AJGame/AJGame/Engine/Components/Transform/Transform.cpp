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