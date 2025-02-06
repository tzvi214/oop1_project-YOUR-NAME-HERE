#include "StaticObject.h"

GameObject::GameObject(sf::Vector2f location, sf::Sprite image, ObjName type)
	: m_pixelSize{ 50 }, m_location{ calculateLocation(location) }, m_image{ image }, m_type{ type }
{
	setSpritLoc();
}

bool GameObject::touch(sf::Vector2f location) const
{
	return  m_image.getGlobalBounds().contains(location);
}
//---------------------------------------------------------------
bool GameObject::collidesWith( GameObject& other) 
{
	return m_image.getGlobalBounds().intersects(other.m_image.getGlobalBounds());
	
}
//---------------------------------------------------------------
sf::Vector2f GameObject::getLocation() const
{
	return m_location;
}
//---------------------------------------------------------------
void GameObject::draw(sf::RenderWindow& window)
{
	m_image.setPosition(m_location);
	window.draw(m_image);
}
//---------------------------------------------------------------
bool GameObject::checkCollision(GameObject& other) const
{
	if (&other == this) return false;
	return true;
}
//------------------------ private function ---------------------
void GameObject::setSpritLoc()
{
	m_image.setPosition(m_location);
}
//---------------------------------------------------------------
sf::Vector2f GameObject::calculateLocation(sf::Vector2f location)
{
	return sf::Vector2f(location.x * m_pixelSize, location.y * m_pixelSize);
}
//---------------------------------------------------------------
bool GameObject::ApproxCollided(sf::Vector2f otherLoc) const
{
	int hit = 0;
	for (int i = (int) otherLoc.x; i < (int) otherLoc.x + m_pixelSize; i++)
	{
		for (int j = (int) otherLoc.y; j < (int) otherLoc.y + m_pixelSize; j++)
		{
			if (touch(sf::Vector2f((float) i, (float) j)))
				hit++;
		}
	}

	// return if object touch more then 95 percent
	return hit > (5 *m_pixelSize);
}
//---------------------------------------------------------------
void GameObject::setDead(bool flag)
{
	m_Dead = flag;
}
//---------------------------------------------------------------
