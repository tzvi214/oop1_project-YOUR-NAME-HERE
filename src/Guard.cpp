#include "Guard.h"

Guard::Guard(sf::Vector2f location, SfmlManager& SfmlMan, Information& info) :
    MovingObject(location, SfmlMan, ObjName::E_Guard, info), m_firstLoc{ location.x * m_pixelSize, location.y * m_pixelSize }
{ 
  
}
//--------------------------------------------------------------
void Guard::dountMove()
{
    int newX = (m_location.x + 25) / 50;
    int newY = (m_location.y + 25) / 50;
    newX *= 50;
    newY *= 50;
    m_location = sf::Vector2f{ (float)newX, (float)newY };
    m_Collided = true;
}
//--------------------------------------------------------------
void Guard::updateDirection() 
{
 
}
//--------------------------------------------------------------
void Guard::move(float deltaTime)
{
    //------------ gift 2 ------------
    if (m_information.isNeed2killed()){
        setDead();
        m_information.killedGuard();
        return;
    }

    if (m_information.areFroze()){
        return;
    }


    sf::Vector2f nextLoc = sf::Vector2f(m_location.x + m_direction.x * (m_pixelSize * deltaTime),
        m_location.y + m_direction.y * (m_pixelSize * deltaTime));

    if (m_information.locInLevel(nextLoc))
    {
        m_image.move(m_direction.x * (m_pixelSize * deltaTime), m_direction.y * (m_pixelSize * deltaTime));
        m_location = nextLoc;
    }
    else
        m_touchTheEnd = true;
    
}
//--------------------------------------------------------------
void Guard::setDead(bool flag)
{
    if (flag)
    {
        m_Dead =true;
        m_information.setScore(3);// information need to do that collision with the 3 point
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
      //  robot.setDead();
      m_need2restartPlace = true;
       
    }
}
//--------------------------------------------------------------
void Guard::trackRobotX()
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

    if (std::abs(robotLocation.x - m_location.x) > (m_pixelSize / 10)) // because its almost never will ba 0 i took exception of 10 parcent
    {
        // Move horizontally
        direction.x = (robotLocation.x > m_location.x) ? 1.f : -1.f;
        setDirection(direction);
    }
    else /*if (std::abs(robotLoc.y - m_location.y) > 0)*/ {
        // Move vertically
        direction.y = (robotLocation.y > m_location.y) ? 1.f : -1.f;
        setDirection(direction);
    }

   
}
//--------------------------------------------------------------
void Guard::trackRobotY()
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

    if (std::abs(robotLocation.y - m_location.y) > (m_pixelSize / 10)) // because its almost never will ba 0 i took exception of 10 parcent
    {
        // Move horizontally
        direction.y = (robotLocation.y > m_location.y) ? 1.f : -1.f;
        setDirection(direction);
    }
    else {
        direction.x = (robotLocation.x > m_location.x) ? 1.f : -1.f;
        setDirection(direction);
    }

}
//--------------------------------------------------------------
void Guard::goInRandom()
{
    if (m_touchTheEnd){
        m_Collided = true;
        m_touchTheEnd = false;
    }

    if (m_Collided)
        m_track++;

    m_track %= 4;

    if (m_track == 2 || m_firstTime)
    {
        int randomNum = rand() % 4 + 1;
        switch (randomNum)
        {
        case 1:
            setDirection(sf::Vector2f(1, 0));
            break;
        case 2:
            setDirection(sf::Vector2f(-1, 0));
            break;
        case 3:
            setDirection(sf::Vector2f(0, 1));
            break;
        case 4:
            setDirection(sf::Vector2f(0, -1));
            break;
        default:
            break;
        }
    }

    m_firstTime = m_Collided = false;
}
