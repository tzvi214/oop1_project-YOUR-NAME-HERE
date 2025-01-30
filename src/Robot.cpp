#include "Robot.h"

Robot::Robot(sf::Vector2f location, SfmlManager& sfmlMan, Information& info)
	: MovingObject(location, sfmlMan, ObjName::E_Robot, info), m_firstLoc{ location.x * m_pixelSize, location.y * m_pixelSize }
	, m_sfmlManager{ sfmlMan }, m_texture{sfmlMan.getTexture(ObjName::E_Temp)}
{
	//m_image.setTexture(m_texture);
		// sprite.setTexture(sfm.getTexture(ObjName::E_Temp));
}
void Robot::setDead(bool flag)
{
	if (flag)
	{
		loseLife();
		touchBomb();// need to restart place
	}
}
//-----------------------------------------------------------
void Robot::updateDirection()
{
	m_stopped  = m_need2restartPlace = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setDirection(sf::Vector2f{ 1, 0 });
		//m_image.setOrigin(m_location.x+ 25.f, m_location.y+ 25.f);
		//m_image.setScale(0.05f, 0.05f);	
		//m_image.setOrigin(m_location.x, m_location.y);
		//m_image.setOrigin(0.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setDirection(sf::Vector2f{ -1, 0 });
		//m_image.setOrigin(m_location.x + 25.f, m_location.y + 25.f);
		//m_image.setScale(-0.05f, 0.05f);
		//m_image.setOrigin(0.f, 0.f);
		//m_image.setOrigin(m_location.x, m_location.y);

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
void Robot::dountMove()
{
	
	int newX = (m_location.x + 25) / 50;
	int newY = (m_location.y + 25) / 50;
	newX *= 50;
	newY *= 50;
	m_location = sf::Vector2f{ (float)newX, (float)newY };
	//-----------------------------
	m_currentFrame = 1;
	
}
//---------------------------------------------------------
void Robot::draw(sf::RenderWindow& window)
{
	////  currentFrame = (currentFrame + 1) % 3;
	//// enum Direction { Up = 0, Left = 3, Down = 2, Right = 1 };
	////   sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, direction * frameHeight, frameWidth, frameHeight));
	////sprite.setScale(3.f, 3.f);
	////
	//m_currentFrame = (m_currentFrame + 1) % 3;
	//if (m_direction == sf::Vector2f{ 1,0 })//right
	//{
	//	//m_image.setTextureRect(sf::IntRect(m_currentFrame * (48/3), 72/4, (48 / 3), 72 / 4));
	//	//m_image.setScale(3.f, 3.f);
	//}
	//else if (m_direction == sf::Vector2f{ -1,0 })
	//{

	//}
	//else if (m_direction == sf::Vector2f{ 0,1 })
	//{

	//}
	//else if (m_direction == sf::Vector2f{ 0,-1 })//up
	//{
	//	
	//	//m_image.setTextureRect(sf::IntRect(m_currentFrame * (48 / 3), 0, (48 / 3), 72 / 4));
	//	//m_image.setScale(3.f, 3.f);
	//}
	//else if (m_direction == sf::Vector2f{ 0,0 })
	//{

	//}
	//m_image.setScale(3.f, 3.f);
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
   
   if (m_stopped) // if the robot didnt move dont move
   	return;

   sf::Vector2f nextLoc = sf::Vector2f(m_location.x + m_direction.x * (2 * m_pixelSize * deltaTime),
	                                  m_location.y + m_direction.y * (2 * m_pixelSize * deltaTime));

   if (m_information.locInLevel(nextLoc))
   {
	   m_image.move(m_direction.x * (2 * m_pixelSize * deltaTime), m_direction.y * (2 * m_pixelSize * deltaTime));
	   m_location = nextLoc;
   }
   m_information.setRobotLoc(m_location);
}
//---------------------------------------------------------
void Robot::handleCollision(StaticObject& other)
{
	/*if (this->collidesWith(other))
	{*/
	//	std::cout << "Robot touch at StaticObject \n";
		other.handleCollision(*this); // swap
		// continue to wall->Robot OR guard->Robot
	/*}*/
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
	text.setString("The Time is: \n     "  + std::to_string(m_seconds / 60) + ":" + std::to_string(m_seconds % 60));
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	window.draw(text);
}
