//
//Components.h
//
//Created by Adam Vandyke on 2018-02-20
//

#ifndef Components_h
#define Components_h

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Listener.h"
#include <stdio.h>


class Components : public Listener
{
public:
	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void LateUpdate() {}
	
	void HandleEvent(Event* msg) {}
};

#endif /* Components_h */