//
//Components.h
//
//Created by Adam Vandyke on 2018-02-20
//

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <stdio.h>

class Components
{
public:
	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void LateUpdate() {}

};