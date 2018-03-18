#pragma once

#include "SFML/Graphics.hpp"
#include "../../Components/Transform/Transform.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>


class Mesh : Components, public sf::Transformable, public sf::Drawable
{
	Mesh() { }
	~Mesh() {}

public:
	//Sets the sprite for mesh
	void SetImage(std::string fileName);

	virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	//Transform for the mesh
	Transform transform;

private:
	
	//holds the sprite of mesh 
	sf::Sprite sprite;
	
};