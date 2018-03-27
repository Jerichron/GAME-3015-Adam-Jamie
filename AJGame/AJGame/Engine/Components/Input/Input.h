#pragma once
#include "../../Components.h"
#include <SFML/Window/Keyboard.hpp>

class Input : public Components
{
	Input() {}
	~Input() {}

	void Update();

	void CheckInput();

	void SetVelocity(int velX, int velY);

private:
	int velocityX;
	int velocityY;
};
