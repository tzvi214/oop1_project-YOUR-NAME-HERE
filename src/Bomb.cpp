#include "Bomb.h"

Bomb::Bomb(sf::Vector2f location, SfmlManager& sfmlManager, Information& info) :
	GameObject(location, sf::Sprite(sfmlManager.getTexture(ObjName::E_Bomb)), ObjName::E_Bomb), m_clock(),
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
		m_image.setTexture(*m_fireSpr.getTexture());
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
	if (m_exploded && !m_Dead){

	
		for (const auto& explosion : m_explosionZoneVec)
		{
			if (movObg.ApproxCollided(explosion.getLocation()))
			{
				movObg.setDead(true);
				return;
			}
		}

	}
}
//----------------------------------------
void Bomb::handleCollision(Rock& rock)
{
	if (m_exploded && !m_Dead) {
		for (const auto& explosion : m_explosionZoneVec) {
			if (rock.ApproxCollided(explosion.getLocation()))
			{
				rock.setDead(true);
				m_information.addRandomGift(m_location);
				return;
			}
		}
	}
}
//----------------------------------------
void Bomb::draw(sf::RenderWindow& window)
{

	GameObject::draw(window);

	if (m_exploded) {
		for ( auto expZone : m_explosionZoneVec) {
			expZone.draw(window);
		}

	}
	
	drawTime(window);

}
//----------------------------------------
void Bomb::initializationBombVec()
{

	std::vector<sf::Vector2f> directions = {
	{static_cast<float>(m_pixelSize), 0.f},
	{-static_cast<float>(m_pixelSize), 0.f},
	{0.f, static_cast<float>(m_pixelSize)},
	{0.f, -static_cast<float>(m_pixelSize)}
	};

	// 4 direction
	for (const auto& dir : directions)
	{
		sf::Vector2f newLoc = m_location + dir;

		if (m_information.locInLevel(newLoc))
		{
			m_explosionZoneVec.emplace_back(newLoc, m_fireSpr);
		}
	}

	//  adding this location
	m_explosionZoneVec.emplace_back(m_location, m_fireSpr);

}
//----------------------------------------
void Bomb::playExpl()
{
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
