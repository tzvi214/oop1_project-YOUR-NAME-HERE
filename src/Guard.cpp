#include "Guard.h"

Guard::Guard(sf::Vector2f location, SfmlManager& SfmlMan, Information& info) :
    MovingObject(location, SfmlMan, ObjName::E_Guard, info), m_firstLoc{ location.x * m_pixelSize, location.y * m_pixelSize }
{ }
//--------------------------------------------------------------
void Guard::dountMove()
{
    int newX = (m_location.x + 25) / 50;
    int newY = (m_location.y + 25) / 50;
    newX *= 50;
    newY *= 50;
    m_location = sf::Vector2f{ (float)newX, (float)newY };
}
//--------------------------------------------------------------
void Guard::updateDirection() 
{
    sf::Vector2f robotLocation = m_information.getRobotLoc();
    m_need2restartPlace = false;
    sf::Vector2f direction = { 0, 0 };

    //
    int newX = (robotLocation.x + 25) / m_pixelSize;
    int newY = (robotLocation.y + 25) / m_pixelSize;
    newX *= m_pixelSize;
    newY *= m_pixelSize;
    robotLocation = sf::Vector2f{ (float)newX, (float)newY };
   //

    if (std::abs(robotLocation.x - m_location.x) >  ( m_pixelSize /10)) // because its almost never will ba 0 i took exception of 10 parcent
    {
        // Move horizontally
        direction.x = (robotLocation.x > m_location.x) ? 1.f : -1.f;
    }
    else /*if (std::abs(robotLoc.y - m_location.y) > 0)*/ {
        // Move vertically
        direction.y = (robotLocation.y > m_location.y) ? 1.f : -1.f;
    }

    setDirection(direction);
}
//--------------------------------------------------------------
void Guard::move(float deltaTime)
{
    sf::Vector2f nextLoc = sf::Vector2f(m_location.x + m_direction.x * (m_pixelSize * deltaTime),
        m_location.y + m_direction.y * (m_pixelSize * deltaTime));

    if (m_information.locInLevel(nextLoc))
    {
        m_image.move(m_direction.x * (m_pixelSize * deltaTime), m_direction.y * (m_pixelSize * deltaTime));
        m_location = nextLoc;
    }
}
//--------------------------------------------------------------
void Guard::handleCollision(StaticObject& other)
{

  other.handleCollision(*this); // swap.
}
//--------------------------------------------------------------
void Guard::handleCollision(Robot& robot)
{
    if (this->collidesWith(robot))
    {
        std::cout << "guard hit a robot. and life-- \n";
        robot.loseLife();
        m_need2restartPlace = true;
       
    }
}