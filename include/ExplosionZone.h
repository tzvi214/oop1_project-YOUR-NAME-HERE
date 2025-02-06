#pragma once
#include <SFML/Graphics.hpp>


class ExplosionZone
{
public:
	ExplosionZone(sf::Vector2f&, sf::Sprite&);
	void draw(sf::RenderWindow&);
	sf::Vector2f getLocation() const { return m_location ; }
private:
	sf::Vector2f m_location;
	sf::Sprite m_sprite;
};