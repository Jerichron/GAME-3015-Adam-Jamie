#include "SFML/Graphics.hpp"
#include "FluxEngine.h"

int main()
{
	FluxEngine::Initialize();
	FluxEngine::Start();

	return 0;
}

//int main() {
//	sf::RenderWindow window(sf::VideoMode(1080, 768), "new class who dis?");
//	sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Green);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		window.clear();
//		window.draw(shape);
//		window.display();
//	}
//
//
//	return 0;
//}