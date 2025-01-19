#include "MovingObject.h"
#include "iostream"

MovingObject::MovingObject(sf::Vector2f location, SfmlManager& sfmlManager, ObjName type)
	:StaticObject(location, sf::Sprite{ sfmlManager.getTexture(type) }, type)

{}
//-----------------------------------------------------------------
void MovingObject::setDirection(sf::Vector2f newDirection)
{
    m_location.x += newDirection.x;
    m_location.y += newDirection.y;

    if (newDirection == m_direction)
    {
       // m_direction = newDirection; // to do double check
        return;
    }
    else // direction changed
    {
       /* int newX = static_cast<int>(m_location.x) / 50;
        int newY = static_cast<int>(m_location.y) / 50;
        newX *= 50;
        newY *= 50;*/
       // m_location = sf::Vector2f{ static_cast<float>(newX), static_cast<float>(newY) };
        m_direction = newDirection;
    }
}
//-----------------------------------------------------------------

void MovingObject::move(float deltaTime)
{
	m_image.move(m_direction.x * (3*m_pixelSize * deltaTime), m_direction.y * (3*m_pixelSize * deltaTime));
	std::cout << getLoc().x << " ," << getLoc().y << std::endl;
}
