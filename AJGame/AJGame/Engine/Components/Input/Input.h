#pragma once
#include "../../Components.h"
#include "../../EventSystem.h"
#include <SFML/Window/Event.hpp>

class Input : public Components
{
	Input() {}
	~Input() {}

	void Update();
public:
	static void CheckInput();

	void SetVelocity(int velX, int velY);

private:
	int velocityX;
	int velocityY;
};
