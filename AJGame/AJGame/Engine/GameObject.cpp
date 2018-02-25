#include "GameObject.h"

void GameObject::Awake()
{
	for (std::vector<Components*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i)
	{
		(*i)->Awake();
	}
}

void GameObject::Start()
{
	for (std::vector<Components*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i)
	{
		(*i)->Start();
	}
}

void GameObject::Update(float msec) 
{
	//Mesh
	//RigidBody
	//Audio
	//

	if (m_Parent) 
	{ //This node has a parent...
		worldTransform = m_Parent->worldTransform * transform.transformMatrix;
	}
	else 
	{ //Root node, world transform is local transform!
		sf::Transform baseTransform = sf::Transform::Identity;
		worldTransform = baseTransform * transform.transformMatrix;
	}
	for (std::vector<Components*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i)
	{
		(*i)->Update();
	}

}

void GameObject::LateUpdate(float msec)
{
	
	for (std::vector<Components*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->LateUpdate();
	}
}

void GameObject::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
}



void GameObject::AddComponent(Components* component)
{
	m_Components.push_back(component);
}

void GameObject::AddChild(GameObject* s)
{
	m_Children.push_back(s);
	
}
