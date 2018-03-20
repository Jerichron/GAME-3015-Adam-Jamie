#pragma once

#include "SFML/Graphics.hpp"
#include "../../Components/Transform/Transform.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>


class Mesh : public Components
{
public:
	sf::Transform transform;
	void setImage(std::string fileName);

	virtual void	drawCurrent(sf::RenderTarget& target) const;
	virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Texture image;
	sf::Sprite m_sprite;

};