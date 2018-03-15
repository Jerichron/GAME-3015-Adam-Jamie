//
//Components.h
//
//Created by Adam Vandyke on 2018-02-20
//

#ifndef Components_h
#define Components_h

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Components/Messages.h"
#include <stdio.h>


class Components
{
public:
	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void LateUpdate() {}
	bool SendMessage(Messages* msg) { return false; }
};

#endif /* Components_h */