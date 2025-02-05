#include "ExplosionZone.h"

ExplosionZone::ExplosionZone(sf::Vector2f& loc, sf::Sprite& sprite)
	:m_location{loc}, m_sprite{sprite}
{}
//----------------------------------------------
void ExplosionZone::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

