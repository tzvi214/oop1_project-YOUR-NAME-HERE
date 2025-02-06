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
void MovingObject::print(sf::RenderWindow& window, int row)
{
    sf::IntRect textureRect;

  
    // ��� �� ������ (����� ������) ������ (����� ������)
    if (m_direction == sf::Vector2f{ 0, 1 }) // ����
        textureRect = sf::IntRect(m_currentFrame * 50, row, 50, 50); // ���� 0

    else if (m_direction == sf::Vector2f{ -1, 0 }) // �����
        textureRect = sf::IntRect(m_currentFrame * 50 + 3 * 50, row, 50, 50); // ���� 1

    else if (m_direction == sf::Vector2f{ 1, 0 }) // �����
        textureRect = sf::IntRect(m_currentFrame * 50 + 6 * 50, row, 50, 50); // ���� 2

    else if (m_direction == sf::Vector2f{ 0, -1 }) // �����
        textureRect = sf::IntRect(m_currentFrame * 50 + 9 * 50, row, 50, 50); // ���� 3

    else // ����� ����� (����� ������ ������ �� "����" ������)
        textureRect = sf::IntRect(0, row, 50, 50); // ����� ������ ����� 0

    // ���� �� ������� ���� �-Sprite
    m_image.setTextureRect(textureRect);


    GameObject::draw(window);



}


