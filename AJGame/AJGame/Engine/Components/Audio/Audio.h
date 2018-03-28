#pragma once
#include "SFML/Audio.hpp"
#include <string>
#include "../../Components.h"

class Audio : public Components
{
public :
	Audio() {}
	~Audio() {}
	void SetAudio(std::string fileName);

	sf::SoundBuffer buffer;
};