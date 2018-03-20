#include "Manager.h"

// Initialize our static unique objectID generator
int GameObjectManager::nextObjectID = 0;

void GameObjectManager::Awake() {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Awake();
	}
}

void GameObjectManager::Start() {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Start();
	}
}

void GameObjectManager::Update(float msec) {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Update(msec);
	}


}

void GameObjectManager::LateUpdate(float msec) {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->LateUpdate(msec);
	}
}

void GameObjectManager::draw(sf::RenderWindow& target)
{
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		i->second->mesh.drawCurrent(target);
	}
}

GameObject* GameObjectManager::CreateObject()
{
	GameObject* newObj = new GameObject(nextObjectID++);
	m_Objects[newObj->GetObjectID()] = newObj;

	return newObj;
}

bool GameObjectManager::SendMessage(Messages* msg)
{
	std::map<int, GameObject*>::iterator objIt = m_Objects.find(msg->GetDestinationID());
	if (objIt != m_Objects.end())
	{
		return objIt->second->SendMessage(msg);
	}

	return false;
}
