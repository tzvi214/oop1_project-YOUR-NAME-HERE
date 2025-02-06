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
		setDirection(Place::Directions::Right);//sf::Vector2f{ 1, 0 }
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setDirection(Place::Directions::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setDirection(Place::Directions::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setDirection(Place::Directions::Down);
	}
	else
	{
		setDirection(Place::Directions::Center); // default nat moving
		m_stopped = true;
	}

}
//---------------------------------------------------------
void Robot::dountMove()
{
	
	m_location = Place::toPlace(m_location, Data::pixelSize);
	m_currentFrame = 1;
	
}
//---------------------------------------------------------
void Robot::FinishedLevel() const
{
	m_information.setLevelFinish(true);
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
   if (m_time > Data::timePerFrame)
   {
	   m_time = 0;
	   m_currentFrame = (m_currentFrame + 1) % Data::numFrame;
   }

   sf::Vector2f nextLoc = sf::Vector2f(m_location.x + m_direction.x * (m_robotSpeed * m_pixelSize * deltaTime),
	                                  m_location.y + m_direction.y * (m_robotSpeed * m_pixelSize * deltaTime));

   if (m_information.locInLevel(nextLoc))
   {
	   m_image.move(m_direction.x * (m_robotSpeed * m_pixelSize * deltaTime), m_direction.y * (m_robotSpeed * m_pixelSize * deltaTime));
	   m_location = nextLoc;
   }
   m_information.setRobotLoc(m_location);
}
//---------------------------------------------------------
void Robot::handleCollision(GameObject& other)
{
	other.handleCollision(*this); // swap
}
//------------------------------------------------------
void Robot::handleCollision(FrozeGift&)
{
	m_information.frozeGuard();
}
//------------------------------------------------------
void Robot::handleCollision(LifeGift& gift2)
{
	m_information.addRobotLife();
}
//------------------------------------------------------
void Robot::handleCollision(TimeGift& gift3)
{
	m_information.addTime();
}
//------------------------------------------------------
void Robot::handleCollision(KilledGift& gift4)
{
	m_information.need2killedGuard();
}


