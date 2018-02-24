#include "SplashScreen.h"
#include "Engine/FluxEngine.h"



void SplashScreen::Show(sf::RenderWindow& renderWindow)
{
	sf::Texture image;
	if (image.loadFromFile("../Assets/SplashScreen.png") != true)
	{
		return;
	}

	sf::Sprite sprite(image);

	renderWindow.draw(sprite);
	renderWindow.display();

}