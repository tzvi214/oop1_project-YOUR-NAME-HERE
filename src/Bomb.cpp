#include "Bomb.h"

Bomb::Bomb(sf::Vector2f location, SfmlManager& sfmlManager, Information& info) :
	StaticObject(location, sf::Sprite(sfmlManager.getTexture(ObjName::E_Bomb)), ObjName::E_Bomb), m_clock(),
	m_fireSpr(sf::Sprite(sfmlManager.getTexture(ObjName::E_Fire))) , m_information{info},
	m_explSnd(), m_ticSnd(), m_bombTime{ sfmlManager.getText(ObjName::Font) }
		
{ 
	m_explSnd.setBuffer(sfmlManager.getSound(Snd::explosion));	
	m_ticSnd.setBuffer(sfmlManager.getSound(Snd::bombTic));
	
}
//----------------------------------------
void Bomb::updateState()
{
	
	m_time += m_clock.restart().asSeconds();
	if (m_time >= m_second + 1) {
		m_second++;
		playTic();
	}


	if (m_second > 4 && !m_exploded) {
		playExpl();
		m_image.setTexture(*m_fireSpr.getTexture());// why *m_fireSpr and nat m_fireSpr
		m_exploded = true; 
		initializationBombVec();
	}

	if (m_second > 6) {
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
	handleCollision(dynamic_cast<MovingObject&>(guard));
}
//----------------------------------------
void Bomb::handleCollision(Robot& robot)
{
	handleCollision(dynamic_cast<MovingObject&>(robot));
}
//----------------------------------------
void Bomb::handleCollision(MovingObject& movObg)
{
	if (m_exploded && !m_Dead)
	{
		sf::Vector2f originalLocation = m_location;
		for (const auto& offset : m_explosionLocVec)
		{
			
			m_location = offset;
			setLocation();

			if (this->ApproxCollided(movObg.getLocation())) 
			{
				movObg.setDead(true);
				return;
			}
		}

		m_location = originalLocation;

	}
}
//----------------------------------------
void Bomb::handleCollision(Rock& rock)
{
	if (m_exploded && !m_Dead)
	{
		if (this->collidesWith(rock))
		{
			rock.setDead(true);
			m_information.addRandomGift(m_location);
		}

		// 4 direction

		// right place
		m_location.x += m_pixelSize;
		setLocation();
		if (this->collidesWith(rock))
		{
			rock.setDead(true);
			m_information.addRandomGift(m_location);
		}
		m_location.x -= m_pixelSize;


		//left place
		m_location.x -= m_pixelSize;
		setLocation();
		if (this->collidesWith(rock))
		{
			rock.setDead(true);
			m_information.addRandomGift(m_location);
		}
		m_location.x += m_pixelSize;

		//down place
		m_location.y += m_pixelSize;
		setLocation();
		if (this->collidesWith(rock))
		{
			rock.setDead(true);
			m_information.addRandomGift(m_location);
		}
		m_location.y -= m_pixelSize;


		//up place
		m_location.y -= m_pixelSize;
		setLocation();
		if (this->collidesWith(rock))
		{
			rock.setDead(true);
			m_information.addRandomGift(m_location);
		}
		m_location.y += m_pixelSize;
		setLocation();
	}


}
//----------------------------------------
void Bomb::draw(sf::RenderWindow& window)
{

	StaticObject::draw(window);

	if (m_exploded) {
		for ( auto expZone : m_explosionZoneVec) {
			expZone.draw(window);
		}

	}
	//if(!m_exploded) StaticObject::draw(window);
	//
	//else
	//{
	//	// print 4 image for itch direction
	//    // and this place
	//	sf::Vector2f loc = m_location;
	//	for (const auto& bomb: m_explosionLocVec){
	//		m_location = bomb;
	//		StaticObject::draw(window);
	//	}
	//	m_location = loc;
	//	StaticObject::draw(window);
	//}
	drawTime(window);

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
		if (m_information.locInLevel(newLoc)){
			m_explosionLocVec.push_back(newLoc);
			m_explosionZoneVec.push_back(ExplosionZone(newLoc, m_fireSpr));
		}
	}
	m_explosionLocVec.push_back(m_location);
}
//----------------------------------------
void Bomb::playExpl()
{
	//m_explSnd.sfmlManager(sfmlManager.getSound(Snd::explosion));
	m_explSnd.setVolume(100);
	m_explSnd.play();
}
//----------------------------------------
void Bomb::playTic()
{
	if (5 - m_second > 0) {
		m_ticSnd.setVolume(70);
		m_ticSnd.play();
	}
}
//----------------------------------------
void Bomb::drawTime(sf::RenderWindow& window)
{
	if (5 - m_second > 0) {
		m_bombTime.setString(std::to_string(5 - m_second));
		m_bombTime.setCharacterSize(24);
		m_bombTime.setOrigin(12, 12); 
		m_bombTime.setPosition(m_location.x + m_pixelSize / 2, m_location.y + m_pixelSize / 2);
		m_bombTime.setFillColor(sf::Color::Red);
		window.draw(m_bombTime);
	}
}
