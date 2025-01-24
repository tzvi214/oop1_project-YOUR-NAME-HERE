#include "Guard.h"

Guard::Guard(sf::Vector2f location, SfmlManager& SfmlMan) :
    MovingObject(location, SfmlMan, ObjName::E_Guard), m_firstLoc{ location.x * m_pixelSize, location.y * m_pixelSize }
{ }
//--------------------------------------------------------------
void Guard::updateDirection(sf::Vector2f robotLoc) {
    sf::Vector2f direction = { 0, 0 };

    if (std::abs(robotLoc.x - m_location.x) > (m_pixelSize /10)) // because its almost never will ba 0 i took exception of 10 parcent
    {
        // Move horizontally
        direction.x = (robotLoc.x > m_location.x) ? 1.f : -1.f;
    }
    else if (std::abs(robotLoc.y - m_location.y) > 0) {
        // Move vertically
        direction.y = (robotLoc.y > m_location.y) ? 1.f : -1.f;
    }

    setDirection(direction);
}
//--------------------------------------------------------------
void Guard::move(float deltaTime)
{
    m_image.move(m_direction.x * (m_pixelSize * deltaTime), m_direction.y * (m_pixelSize * deltaTime));
    m_location.x += m_direction.x * (m_pixelSize * deltaTime);
    m_location.y += m_direction.y * (m_pixelSize * deltaTime);
}
//--------------------------------------------------------------
void Guard::handleCollision(StaticObject& other)
{
    if (this->collidesWith(other))
    {
        std::cout << "Guard touch at StaticObgect \n";
        other.handleCollision(*this); // swap.
        // continue staticObject meet with Guard.
    }
}
//--------------------------------------------------------------
void Guard::handleCollision(Robot& robot)
{
    std::cout << "guard hit a robot. and life-- \n";
    robot.loseLife();
    goToFirstLoc();
    robot.goToFirstLoc();
}