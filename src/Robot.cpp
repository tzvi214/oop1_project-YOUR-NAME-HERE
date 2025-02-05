#include "Robot.h"

Robot::Robot(sf::Vector2f location, SfmlManager& sfmlMan, Information& info)
	: MovingObject(location, sfmlMan, ObjName::E_Robot, info), m_firstLoc{ location.x * m_pixelSize, location.y * m_pixelSize }
	, m_sfmlManager{ sfmlMan }
{
}
void Robot::setDead(bool flag)
{
	if (flag)
	{
		Defeated();
	}
}
//-----------------------------------------------------------
void Robot::updateDirection()
{
	m_stopped  = m_need2restartPlace = false;

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
void Robot::FinishedLevel() const
{
	m_information.setLevelFinish(true);
	std::cout << "Robot hit a Door go to next level\n";
}
//---------------------------------------------------------
void Robot::draw(sf::RenderWindow& window)
{

	MovingObject::print(window, m_rowImage);
}
//---------------------------------------------------------
void Robot::move(float deltaTime)
{
	//for the first time or after robot deed
	m_information.setRobotLoc(m_location);

   if (m_stopped) // if the robot didnt move dont move
   	return;
   m_time += deltaTime;
   if (m_time > 0.2f)
   {
	   m_time = 0;
	   m_currentFrame = (m_currentFrame + 1) % 3;
   }

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
	other.handleCollision(*this); // swap
}
//------------------------------------------------------
void Robot::handleCollision(Gift1&)
{
	m_information.frozeGuard();
}
//------------------------------------------------------
void Robot::handleCollision(Gift2& gift2)
{
	m_information.addRobotLife();
}
//------------------------------------------------------
void Robot::handleCollision(Gift3& gift3)
{
	m_information.addTime();
}
//------------------------------------------------------
void Robot::handleCollision(Gift4& gift4)
{
	m_information.need2killedGuard();
}

//---------------------------------------------------------
void Robot::drawInformation(sf::RenderWindow& window)
{

}
