#include "Bomb.h"

Bomb::Bomb(sf::Vector2f location, SfmlManager& sfmlManager, Information& info) :
	StaticObject(location, sf::Sprite(sfmlManager.getTexture(ObjName::E_Bomb)), ObjName::E_Bomb), m_clock(),
	m_fireSpr(sf::Sprite(sfmlManager.getTexture(ObjName::Fire))) , m_information{info}
{ }
//----------------------------------------
void Bomb::updateState()
{
	float elapsedTime = m_clock.getElapsedTime().asSeconds();

	if (elapsedTime > 4 && !m_exploded) {
		m_image.setTexture(*m_fireSpr.getTexture());// why *m_fireSpr and nat m_fireSpr
		m_exploded = true; 
		initializationBombVec();
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
	if (m_exploded && !m_Dead)
	{
		if (this->collidesWith(guard))
		{
			guard.setDead(true);
		}

		// 4 direction

		// right place
		m_location.x += m_pixelSize;
		setLocation();
		if (this->collidesWith(guard))
		{
			guard.setDead(true);
		}
		m_location.x -= m_pixelSize;


		//left place
		m_location.x -= m_pixelSize;
		setLocation();
		if (this->collidesWith(guard))
		{
			
			guard.setDead(true);
		}
		m_location.x += m_pixelSize;

		//down place
		m_location.y += m_pixelSize;
		setLocation();
		if (this->collidesWith(guard))
		{
			guard.setDead(true);

		}
		m_location.y -= m_pixelSize;


		//up place
		m_location.y -= m_pixelSize;
		setLocation();
		if (this->collidesWith(guard))
		{
			guard.setDead(true);
		}
		m_location.y += m_pixelSize;
		setLocation();
	}

}
//----------------------------------------
void Bomb::handleCollision(Robot& robot)
{
	if (m_exploded && !m_Dead)
	{

		if (this->collidesWith(robot)) 
		{
			robot.setDead();
			return;
		}
		// 4 direction

		// right place
		m_location.x += m_pixelSize;
		setLocation();
		if (this->collidesWith(robot))
		{
			
			robot.setDead();
			return;
		}
		m_location.x -= m_pixelSize;


		     //left place
	    m_location.x -= m_pixelSize;
	    setLocation();
		if (this->collidesWith(robot))
		{
			robot.setDead();

			return;
		}
		m_location.x += m_pixelSize;

		  //down place
		m_location.y += m_pixelSize;
		setLocation();
		if (this->collidesWith(robot))
		{
			
			robot.setDead();
			return;
		}
		m_location.y -= m_pixelSize;


		  //up place
		m_location.y -= m_pixelSize;
		setLocation();
		if (this->collidesWith(robot))
		{
			robot.setDead();
			return;
		}
		m_location.y += m_pixelSize;
		setLocation();
	}
}
//------------------------------------------------------
//void Bomb::handleCollision(StaticObject& other)
//{
//	if (m_exploded && !m_Dead)
//	{
//		if (this->collidesWith(other))
//		{
//			other.setDead(true);
//		}
//
//		// 4 direction
//
//		// right place
//		m_location.x += m_pixelSize;
//		setLocation();
//		if (this->collidesWith(other))
//		{
//			other.setDead(true);
//		}
//		m_location.x -= m_pixelSize;
//
//
//		//left place
//		m_location.x -= m_pixelSize;
//		setLocation();
//		if (this->collidesWith(other))
//		{
//
//			other.setDead(true);
//		}
//		m_location.x += m_pixelSize;
//
//		//down place
//		m_location.y += m_pixelSize;
//		setLocation();
//		if (this->collidesWith(other))
//		{
//			other.setDead(true);
//
//		}
//		m_location.y -= m_pixelSize;
//
//
//		//up place
//		m_location.y -= m_pixelSize;
//		setLocation();
//		if (this->collidesWith(other))
//		{
//			other.setDead(true);
//		}
//		m_location.y += m_pixelSize;
//		setLocation();
//	}
//}
//----------------------------------------
void Bomb::handleCollision(Rock& rock)
{
	if (m_exploded && !m_Dead)
	{
		if (this->collidesWith(rock))
		{
			rock.setDead(true);
		}

		// 4 direction

		// right place
		m_location.x += m_pixelSize;
		setLocation();
		if (this->collidesWith(rock))
		{
			rock.setDead(true);
		}
		m_location.x -= m_pixelSize;


		//left place
		m_location.x -= m_pixelSize;
		setLocation();
		if (this->collidesWith(rock))
		{

			rock.setDead(true);
		}
		m_location.x += m_pixelSize;

		//down place
		m_location.y += m_pixelSize;
		setLocation();
		if (this->collidesWith(rock))
		{
			rock.setDead(true);

		}
		m_location.y -= m_pixelSize;


		//up place
		m_location.y -= m_pixelSize;
		setLocation();
		if (this->collidesWith(rock))
		{
			rock.setDead(true);
		}
		m_location.y += m_pixelSize;
		setLocation();
	}


}
//----------------------------------------
void Bomb::draw(sf::RenderWindow& window)
{
	if(!m_exploded) StaticObject::draw(window);
	
	else
	{
		// print 4 image for itch direction
	    // and this place
		sf::Vector2f loc = m_location;
		for (const auto& bomb: m_explosionLocVec){
			m_location = bomb;
			StaticObject::draw(window);
		}
		m_location = loc;
		StaticObject::draw(window);
	}
}
//----------------------------------------
void Bomb::initializationBombVec()
{
	sf::Vector2f newLoc = sf::Vector2f{ 0,0 };// = sf::Vector2f{ 0,0 } for the compailer
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
		{
		   newLoc = (i == 0)? sf::Vector2f{ m_location.x + m_pixelSize, m_location.y }:
			                  sf::Vector2f{ m_location.x - m_pixelSize, m_location.y };
		}
		else
		{
			newLoc = (i == 2)? sf::Vector2f{ m_location.x , m_location.y + m_pixelSize }: 
				               sf::Vector2f{ m_location.x , m_location.y - m_pixelSize };
		}

		if (m_information.locInLevel(newLoc))
		{
			m_explosionLocVec.push_back(newLoc);

		}
	}
}
