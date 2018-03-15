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

bool GameObject::SendMessage(Messages* msg)
{
	bool messageHandled = false;

	// Object has a switch for any messages it cares about
	switch (msg->GetMessageType())
	{
		//            case SetPosition:
		//            {
		//                MsgSetPosition* msgSetPos = static_cast<MsgSetPosition*>(msg);
		//                m_Position.x = msgSetPos->x;
		//                m_Position.y = msgSetPos->y;
		//                m_Position.z = msgSetPos->z;
		//
		//                messageHandled = true;
		//                cout << "Object handled SetPosition\n";
		//            }
		//                break;
		//            case GetPosition:
		//            {
		//                MsgGetPosition* msgSetPos = static_cast<MsgGetPosition*>(msg);
		//                msgSetPos->x = m_Position.x;
		//                msgSetPos->y = m_Position.y;
		//                msgSetPos->z = m_Position.z;
		//
		//                messageHandled = true;
		//                cout << "Object handling GetPosition\n";
		//            }
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