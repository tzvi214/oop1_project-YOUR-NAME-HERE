#include "Guard.h"

Guard::Guard(sf::Vector2f location, SfmlManager& SfmlMan, Information& info) :
    MovingObject(location, SfmlMan, ObjName::E_Guard, info),
    m_firstLoc{ location.x * m_pixelSize, location.y * m_pixelSize }
{ 
  
}
//--------------------------------------------------------------
void Guard::dountMove()
{
   
    m_location = Place::toPlace(m_location, Data::pixelSize);
    m_Collided = true;
   
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

    m_time += deltaTime;
    if (m_time > Data::timePerFrame)
    {
        m_time = 0;
        m_currentFrame = (m_currentFrame + 1) % Data::numFrame;
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
        m_information.setScore(3);
    }
}
//--------------------------------------------------------------
void Guard::handleCollision(GameObject& other)
{
    if (m_touchTheEnd) {
        m_Collided = true;
    }
    m_touchTheEnd = false;

  other.handleCollision(*this); // swap.
}
//--------------------------------------------------------------
void Guard::handleCollision(Robot& robot)
{
    if (this->collidesWith(robot))
    {
      m_need2restartPlace = true;
       
    }
}
//--------------------------------------------------------------
void Guard::draw(sf::RenderWindow& window)
{
    MovingObject::print(window, m_rowImage);
}
//--------------------------------------------------------------
void Guard::trackRobotX()
{
    sf::Vector2f robotLocation = m_information.getRobotLoc();
    m_need2restartPlace = false;
    sf::Vector2f direction = { 0, 0 };

    robotLocation = Place::toPlace(m_information.getRobotLoc(), Data::pixelSize);


    if (std::abs(robotLocation.x - m_location.x) > (m_pixelSize / Data::throwable *2)) // because its almost never will ba 0 i took exception of 10 parcent
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

    robotLocation = Place::toPlace(m_information.getRobotLoc(), Data::pixelSize);
    
    if (std::abs(robotLocation.y - m_location.y) > (m_pixelSize / Data::throwable * 2)) // because its almost never will ba 0 i took exception of 10 parcent
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
   
    m_need2restartPlace = false;


    if (m_Collided)
        m_track++;

    m_track %= 4;

    if (m_track == 2 || m_firstTime)
    {
        int randomNum = rand() % 4 + 1;
        switch (randomNum)
        {
        case 1:
            setDirection(Place::Directions::Right);
            break;
        case 2:
            setDirection(Place::Directions::Left);
            break;
        case 3:
            setDirection(Place::Directions::Up);
            break;
        case 4:
            setDirection(Place::Directions::Down);
            break;
        default:
            break;
        }
    }

    m_firstTime = m_Collided = false;
}
