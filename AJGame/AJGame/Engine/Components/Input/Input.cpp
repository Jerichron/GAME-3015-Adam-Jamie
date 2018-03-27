#include "Input.h"

void Input::Update()
{
	CheckInput();
}

void Input::CheckInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{

	}
}

void Input::SetVelocity(int velX, int velY)
{
	velocityX = velX;
	velocityY = velX;
}
