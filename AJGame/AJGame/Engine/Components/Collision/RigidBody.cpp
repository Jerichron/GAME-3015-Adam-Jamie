#include "RigidBody.h"

void RigidBody::Update()
{
}


sf::IntRect RigidBody::GetBody()
{
	return m_Body;
}

void RigidBody::SetBody(sf::IntRect size)
{
	m_Body = size;
}

bool RigidBody::GetGravityOn()
{
	return m_GravityOn;
}

void RigidBody::SetGravityOn(bool value)
{
	m_GravityOn = value;
}
