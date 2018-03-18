#include "Mesh.h"

void Mesh::SetImage(std::string fileName)
{
	sf::Texture image;
	if (image.loadFromFile(fileName) != true)
	{
		return;
	}

	sf::Sprite imageSprite(image);
	sprite = imageSprite;

}

void Mesh::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	// Apply transform of current node
	states.transform *= getTransform();

	// Draw node and children with changed transform
	drawCurrent(target, states);
}

void Mesh::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}



