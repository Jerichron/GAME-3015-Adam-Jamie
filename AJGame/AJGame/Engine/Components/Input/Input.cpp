#include "Input.h"

void Input::Update()
{
	CheckInput();
}

void Input::CheckInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		EventSystem::Instance()->SendEvent("Up", 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		EventSystem::Instance()->SendEvent("Down", 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		EventSystem::Instance()->SendEvent("Left", 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		EventSystem::Instance()->SendEvent("Right", 0);
	}
}

void Input::SetVelocity(int velX, int velY)
{
	velocityX = velX;
	velocityY = velX;
}
