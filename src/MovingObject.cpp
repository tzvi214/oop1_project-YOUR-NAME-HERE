#include "MovingObject.h"
#include "iostream"

MovingObject::MovingObject(sf::Vector2f location, SfmlManager& sfmlManager, ObjName type)
	:StaticObject(location, sf::Sprite{ sfmlManager.getTexture(type) }, type)

{}
//-----------------------------------------------------------------
void MovingObject::setDirection(sf::Vector2f newDirection)
{
   
    if (m_direction.x == newDirection.x && m_direction.y == newDirection.y)
    {
      //  m_direction = newDirection;
        return;
    }
    else // direction changed
    {
      /*  std::cout << "Direction changed \n";*/
        int newX = (m_location.x +25) / 50;
        int newY = (m_location.y +25) / 50;
        newX *= 50;
        newY *= 50;
        m_location = sf::Vector2f{ (float)newX, (float) newY };

       
        m_direction = newDirection;
    }
}
//-----------------------------------------------------------------
void MovingObject::move(float deltaTime)
{
   
}
