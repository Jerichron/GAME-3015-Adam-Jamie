#include "World.h"
#include "../Player.h"


GameObjectManager World::_Manager;

void World::LoadLevel()
{
	GameObject* background = _Manager.CreateObject();

	background->transform->SetPosition(500.0f, 350.0f);
	background->mesh->setImage("../Assets/Night.jpg");
	background->mesh->Render = true;

	GameObject* Player = _Manager.CreateObject();
	background->AddChild(Player);
	Player->transform->SetPosition(0, 0);
	Player->transform->SetScale(0.2, 0.2);
	Player->mesh->setImage("../Assets/SpaceShip.png");
	Player->mesh->Render = true;

	GameObject* sun = _Manager.CreateObject();
	sun->transform->SetPosition(sf::Vector2f(350.0f, -270.0f));
	sun->transform->SetScale(0.6, 0.6);

	sun->mesh->setImage("../Assets/NRedSun.png");
	sun->mesh->Render = true;
	background->AddChild(sun);

	GameObject* UI = _Manager.CreateObject();
	background->AddChild(UI);
	UI->transform->SetPosition(0, 0);

	GameObject* Live1 = _Manager.CreateObject();
	UI->AddChild(Live1);
	Live1->transform->SetPosition(-450, -300);
	Live1->transform->SetScale(0.1, 0.1);
	Live1->mesh->setImage("../Assets/SpaceShip.png");
	Live1->mesh->Render = true;

	GameObject* Live2 = _Manager.CreateObject();
	UI->AddChild(Live2);
	Live2->transform->SetPosition(-400, -300);
	Live2->transform->SetScale(0.1, 0.1);
	Live2->mesh->setImage("../Assets/SpaceShip.png");
	Live2->mesh->Render = true;

	EventSystem::Instance()->RegisterEvent("Up", Player);
	EventSystem::Instance()->RegisterEvent("Down", Player);
	EventSystem::Instance()->RegisterEvent("Left", Player);
	EventSystem::Instance()->RegisterEvent("Right", Player);
	
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
