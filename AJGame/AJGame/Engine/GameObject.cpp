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


	if (m_Parent)
	{ //This node has a parent...
		worldTransform = m_Parent->worldTransform *transform->getWorldTransform();
	}
	else
	{ //Root node, world transform is local transform!
		worldTransform = transform->getWorldTransform();
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

void GameObject::HandleEvent(Event* msg)
{
	if(msg->GetEvent() == "Up")
		transform->SetPosition(0, -1);
	if (msg->GetEvent() == "Down")
		transform->SetPosition(0, 1);
	if (msg->GetEvent() == "Left")
		transform->SetRotation(-0.1);
	if (msg->GetEvent() == "Right")
		transform->SetRotation(0.1);
}

void GameObject::AddComponent(Components* component)
{
	m_Components.push_back(component);
}


void GameObject::AddChild(GameObject* s)
{
	s->m_Parent = this;
	m_Children.push_back(s);
	
}

void GameObject::draw(sf::RenderTarget & target) const
{
	sf::RenderStates states;
	states.transform = worldTransform;
	mesh->drawCurrent(target, states);
}


