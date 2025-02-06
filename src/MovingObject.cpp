#include "MovingObject.h"
#include "iostream"

MovingObject::MovingObject(sf::Vector2f location, SfmlManager& sfmlManager, ObjName type, Information& info)
    :GameObject(location, sf::Sprite{ sfmlManager.getTexture(type) }, type), m_information{info}
    , m_texture{ sfmlManager.getTexture(ObjName::E_Temp) }
{ 
    m_image.setTexture(m_texture);

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

        if ((static_cast<int>(m_location.x) % m_pixelSize) > Data::throwable || 
               (static_cast<int>(m_location.y) % m_pixelSize) > Data::throwable)
        {
            return;
        }

        m_location = Place::toPlace(m_location, Data::pixelSize);

       m_direction = newDirection;
    }

}
//-----------------------------------------------------------------
void MovingObject::print(sf::RenderWindow& window, int row)
{
    sf::IntRect textureRect;

  
    if (m_direction == Place::Directions::Down) 
        textureRect = sf::IntRect(m_currentFrame * Data::pixelSize + Place::PicMatrix::Down,
                                                   row, Data::pixelSize, Data::pixelSize); 

    else if (m_direction == Place::Directions::Left) 
        textureRect = sf::IntRect(m_currentFrame * Data::pixelSize + Place::PicMatrix::Left * Data::pixelSize,
                                                                       row, Data::pixelSize, Data::pixelSize); 
    else if (m_direction == Place::Directions::Right) 
        textureRect = sf::IntRect(m_currentFrame * Data::pixelSize + Place::PicMatrix::Right * Data::pixelSize,
                                                                         row, Data::pixelSize, Data::pixelSize); 
    else if (m_direction == Place::Directions::Up) 
        textureRect = sf::IntRect(m_currentFrame * Data::pixelSize + Place::PicMatrix::Up * Data::pixelSize,
                                                                      row, Data::pixelSize, Data::pixelSize); 
    else 
        textureRect = sf::IntRect(Place::PicMatrix::Stand, row, Data::pixelSize, Data::pixelSize); 

    m_image.setTextureRect(textureRect);

    GameObject::draw(window);

}


