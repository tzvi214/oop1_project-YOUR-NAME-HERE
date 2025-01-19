#include "StaticObject.h"

StaticObject::StaticObject(sf::Vector2f location, sf::Sprite image, ObjName type)
	: m_pixelSize {50}, m_location{ calculateLocation(location)}, m_image{image}, m_type{type}
{ 
	setSpritLoc();
}
//---------------------------------------------------------------
void StaticObject::draw(sf::RenderWindow& window)
{
	m_image.setPosition(m_location);
	window.draw(m_image);
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
	return sf::Vector2f(location.x* m_pixelSize, location.y*m_pixelSize);
}
//---------------------------------------------------------------
