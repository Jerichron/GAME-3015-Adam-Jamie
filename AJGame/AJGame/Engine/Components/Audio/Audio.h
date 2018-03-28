#pragma once
#include "SFML/Audio.hpp"
#include <string>
#include "../../Components.h"

class Audio : public Components
{
public:
	void playMusic(); 
    void playSound();
    void setAudio(std::string);
	Audio();
	~Audio();
	//sf::SoundBuffer buffer;

private:
	//sf::Sound music;
};