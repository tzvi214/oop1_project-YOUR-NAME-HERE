#include "MovingObject.h"
#include "iostream"

MovingObject::MovingObject(sf::Vector2f location, SfmlManager& sfmlManager, ObjName type)
    :StaticObject(location, sf::Sprite{ sfmlManager.getTexture(type) }, type)

{
}
void MovingObject::setDirection(sf::Vector2f newDirection)
{
    if (m_direction.x == newDirection.x && m_direction.y == newDirection.y)
    {
        return;
    }
    else   // direction changed but didnt stopt
    {
        //to move to the place nicely
        // its nat will look like jumping  
        if(newDirection.x || newDirection.y) // didnt stoppt
        {
            if (m_direction.x + newDirection.x == 0 || m_direction.y + newDirection.y == 0)// Reverse direction change immediately
            {
                m_direction = newDirection;
                return;
            }
        }

        if ((static_cast<int>(m_location.x) % 50) > 5 || (static_cast<int>(m_location.y) % 50) > 5)
        {
            return;
        }

        int newX = (m_location.x + 25) / 50;
        int newY = (m_location.y + 25) / 50;
        newX *= 50;
        newY *= 50;
        m_location = sf::Vector2f{ (float)newX, (float)newY };

       m_direction = newDirection;
    }

}


//-----------------------------------------------------------------
