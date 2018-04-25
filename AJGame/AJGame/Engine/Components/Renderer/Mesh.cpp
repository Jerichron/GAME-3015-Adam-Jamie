#include "Mesh.h"



Mesh::~Mesh()
{
	image.~Texture();
}

void Mesh::setImage(std::string fileName)
{
	
	if (image.loadFromFile(fileName) != true)
	{
		return;
	}
	sf::Sprite sprite(image);
	m_sprite = sprite;
}


void Mesh::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
