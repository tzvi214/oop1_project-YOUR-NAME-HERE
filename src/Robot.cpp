#include "Robot.h"

Robot::Robot(sf::Vector2f location, SfmlManager& sfmlMan)
	: MovingObject(location, sfmlMan, ObjName::E_Robot), m_firstLoc{ location.x * m_pixelSize, location.y * m_pixelSize }
	, m_sfmlManager{ sfmlMan }
{
}
//-----------------------------------------------------------
void Robot::updateDirection(sf::Vector2f)
{
	m_stopped /*= m_cannotMove*/ = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setDirection(sf::Vector2f{ 1, 0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setDirection(sf::Vector2f{ -1, 0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setDirection(sf::Vector2f{ 0, -1 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setDirection(sf::Vector2f{ 0, 1 });
	}
	else
	{
		setDirection(sf::Vector2f{ 0, 0 }); // default nat moving
		m_stopped = true;
	}

}
//---------------------------------------------------------
void Robot::loseLife()
{
	if (m_life-- <= 0)
		m_robotKilled = true;
}
//---------------------------------------------------------
void Robot::draw(sf::RenderWindow& window)
{
	StaticObject::draw(window);
	drawInformation(window);
}
//---------------------------------------------------------
void Robot::move(float deltaTime)
{
   //---------- update time past -----
   if ((m_time += deltaTime) >= m_seconds + 1)
   {
   	m_seconds++;
   }
   //-----------------------------------
   
   if (m_stopped/* || m_cannotMove*/) // if the robot didnt move dont move
   	return;
   
   m_image.move(m_direction.x * (2 * m_pixelSize * deltaTime), m_direction.y * (2 * m_pixelSize * deltaTime));
   m_location.x += m_direction.x * (2 * m_pixelSize * deltaTime);
   m_location.y += m_direction.y * (2 * m_pixelSize * deltaTime);

}
//---------------------------------------------------------
void Robot::handleCollision(StaticObject& other)
{
	if (this->collidesWith(other))
	{
		std::cout << "Robot touch at StaticObject \n";
		other.handleCollision(*this); // swap
		// continue to wall->Robot OR guard->Robot
	}
}
//---------------------------------------------------------
void Robot::drawInformation(sf::RenderWindow& window)
{
	/*sf::Text*/ auto text = m_sfmlManager.getText(ObjName::Font);

	//2*50 ==> This is the extra space in the window for displaying the data. 
	//------life---------
	auto posy = window.getSize().y - (2 * 50);
	text.setPosition(0, posy);
	text.setString( "Life: \n " + std::to_string(m_life));
	text.setCharacterSize(24);
	const sf::Color lightBlue(173, 216, 230);
	text.setFillColor(lightBlue);
	window.draw(text);

	//------time---------
	text.setPosition(70, posy);
	text.setString("The Time is: \n     0"  + std::to_string(m_seconds / 60) + ":" + std::to_string(m_seconds % 60));
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	window.draw(text);
}
