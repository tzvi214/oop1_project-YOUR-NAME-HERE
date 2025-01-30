#include "MovingObject.h"
#include "iostream"

MovingObject::MovingObject(sf::Vector2f location, SfmlManager& sfmlManager, ObjName type, Information& info)
    :StaticObject(location, sf::Sprite{ sfmlManager.getTexture(type) }, type), m_information{info}

{ }

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

        if ((static_cast<int>(m_location.x) % m_pixelSize) > 5 || (static_cast<int>(m_location.y) % m_pixelSize) > 5)
        {
            return;
        }

        int newX = (m_location.x + 25) / m_pixelSize;
        int newY = (m_location.y + 25) / m_pixelSize;
        newX *= m_pixelSize;
        newY *= m_pixelSize;
        m_location = sf::Vector2f{ (float)newX, (float)newY };

       m_direction = newDirection;
    }

}


//-----------------------------------------------------------------
