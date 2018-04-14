#include "Input.h"

void Input::Update()
{
	CheckInput();
}

void Input::CheckInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		printf("Up\n");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		printf("Down\n");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		printf("Left\n");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		printf("Up\n");
	}
}

void Input::SetVelocity(int velX, int velY)
{
	velocityX = velX;
	velocityY = velX;
}
