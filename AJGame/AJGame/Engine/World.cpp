#include "World.h"


GameObjectManager World::_Manager;

void World::LoadLevel()
{
	GameObject* background = _Manager.CreateObject();

	background->transform->SetPosition(0.0f, 0.0f);
	background->mesh->setImage("../Assets/Night.jpg");
	background->mesh->Render = true;

	GameObject* sun = _Manager.CreateObject();
	sun->transform->SetPosition(sf::Vector2f(0.0f, 0.0f));

	EventSystem::Instance()->RegisterEvent("Up", background);

	sun->mesh->setImage("../Assets/NRedSun.png");
	sun->mesh->Render = true;
	background->AddChild(sun);
}

void World::UpdateWorld(float msec)
{
	_Manager.Update(msec);
	
	_Manager.LateUpdate(msec);
}

void World::DrawWorld(sf::RenderWindow& target)
{
	_Manager.draw(target);
}

void World::DestoryWorld()
{
}
