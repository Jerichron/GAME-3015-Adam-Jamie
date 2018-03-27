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
		worldTransform = m_Parent->worldTransform.combine(transform->getWorldTransform());
	}
	else
	{ //Root node, world transform is local transform!
		sf::Transform baseTransform;
		worldTransform = baseTransform.combine(transform->getWorldTransform());
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

void GameObject::AddComponent(Components* component)
{
	m_Components.push_back(component);
}


void GameObject::AddChild(GameObject* s)
{
	s->m_Parent = this;
	m_Children.push_back(s);
	
}

bool GameObject::SendMessage(Messages* msg)
{
	bool messageHandled = false;

	// Object has a switch for any messages it cares about
	switch (msg->GetMessageType())
	{
	case SetPosition:

		break;
	case GetPosition:

		break;
	default:
		return PassMessageToComponents(msg);
	}

	messageHandled |= PassMessageToComponents(msg);

	return messageHandled;
}

bool GameObject::PassMessageToComponents(Messages* msg)
{
	bool messageHandled = false;

	std::vector<Components*>::iterator compIt = m_Components.begin();
	for (compIt; compIt != m_Components.end(); ++compIt)
	{
		messageHandled |= (*compIt)->SendMessage(msg);
	}

	return messageHandled;
}

void GameObject::draw(sf::RenderTarget & target) const
{
	sf::RenderStates states;
	states.transform = transform->getWorldTransform();
	mesh->drawCurrent(target, states);
}


