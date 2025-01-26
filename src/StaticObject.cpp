#include "StaticObject.h"

StaticObject::StaticObject(sf::Vector2f location, sf::Sprite image, ObjName type)
	: m_pixelSize{ 50 }, m_location{ calculateLocation(location) }, m_image{ image }, m_type{ type }
{
	setSpritLoc();
}

bool StaticObject::touch(sf::Vector2f location) const
{
	return  m_image.getGlobalBounds().contains(location);
}
//---------------------------------------------------------------
bool StaticObject::collidesWith(const StaticObject& other) const
{
	return m_image.getGlobalBounds().intersects(other.m_image.getGlobalBounds());

}
//---------------------------------------------------------------
sf::Vector2f StaticObject::getLocation() const
{
	return m_location;
}
//---------------------------------------------------------------
void StaticObject::draw(sf::RenderWindow& window)
{
	//m_image.setOrigin(m_pixelSize, m_pixelSize);
	m_image.setPosition(m_location);
	window.draw(m_image);
}
//---------------------------------------------------------------
bool StaticObject::checkCollision(StaticObject& other) const
{
	if (&other == this) return false;
	return true;
}
//------------------------ private function ---------------------
void StaticObject::setSpritLoc()
{
	
	m_image.setScale(0.05f, 0.05f);
	m_image.setPosition(m_location);
}
//---------------------------------------------------------------
sf::Vector2f StaticObject::calculateLocation(sf::Vector2f location)
{
	return sf::Vector2f(location.x * m_pixelSize, location.y * m_pixelSize);
}
//---------------------------------------------------------------