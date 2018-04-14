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

void GameObjectManager::CheckInput()
{
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		//if (i->second->mesh)
		//	i->second->draw();
	}
}

void GameObjectManager::draw(sf::RenderWindow& target)
{
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		if(i->second->mesh->Render)
		i->second->draw(target);
	}
}

GameObject* GameObjectManager::CreateObject()
{
	GameObject* newObj = new GameObject(nextObjectID++);
	m_Objects[newObj->GetObjectID()] = newObj;
	Transform* newTransform = new Transform();
	newObj->AddComponent(newTransform);
	newObj->transform = newTransform;
	Mesh* newMesh = new Mesh();
	newObj->AddComponent(newMesh);
	newObj->mesh = newMesh;
	return newObj;
}


