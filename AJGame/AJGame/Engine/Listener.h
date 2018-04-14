#pragma once
#include "Event.h"

class Listener
{
public:
	Listener() {}
	~Listener() {}

	virtual void HandleEvent(Event* msg) {};
};