#include "Bomb.h"

Bomb::Bomb(sf::Vector2f location, SfmlManager& sfmlManager) :
	StaticObject(location, sf::Sprite(sfmlManager.getTexture(ObjName::E_Bomb)), ObjName::E_Bomb), m_clock(),
	m_fireSpr(sf::Sprite(sfmlManager.getTexture(ObjName::Fire))) {
}
//----------------------------------------
void Bomb::updateState()
{
	float elapsedTime = m_clock.getElapsedTime().asSeconds();

	if (elapsedTime > 4 && !m_exploded) {
		m_image.setTexture(*m_fireSpr.getTexture());// why *m_fireSpr and nat m_fireSpr
		//m_image = m_fireSpr;
		m_exploded = true; 
	}

	if (elapsedTime > 6) {
		m_Dead = true;
	}
}
//----------------------------------------
bool Bomb::IsExploded()
{
	return m_exploded;
}
//----------------------------------------
void Bomb::handleCollision(Guard& guard)
{
	if (m_exploded) {
		guard.setDead(true);
	}
}
//----------------------------------------
void Bomb::handleCollision(Robot& robot)
{
	if (m_exploded) {
		robot.loseLife();
		// need to: go to next level. 
		robot.setDead(true);
	}
}
//----------------------------------------
void Bomb::draw(sf::RenderWindow& window)
{
	if(!m_exploded) StaticObject::draw(window);
	
	else
	{
		// print 4 image for itch direction
		   //this place
		StaticObject::draw(window); 

		     // right place
		m_location.x += m_pixelSize;
		StaticObject::draw(window);
		m_location.x -= m_pixelSize;
		    // left place
		m_location.x -= m_pixelSize;
		StaticObject::draw(window);
		m_location.x += m_pixelSize;

		    // down place
		m_location.y += m_pixelSize;
		StaticObject::draw(window);
		m_location.y -= m_pixelSize;
		    // up place
		m_location.y -= m_pixelSize;
		StaticObject::draw(window);
		m_location.y += m_pixelSize;

	}
}
