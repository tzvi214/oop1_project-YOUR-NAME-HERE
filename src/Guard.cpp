#include "Guard.h"

Guard::Guard(sf::Vector2f location, SfmlManager& SfmlMan) :
    MovingObject(location, SfmlMan, ObjName::E_Guard)
{
}

//void Guard::updateDirection(sf::Vector2f robotLoc)
//{
//    auto& guardLoc = m_location;
//    sf::Vector2f direction{0, 0};
//
//    
//    float deltaX = robotLoc.x - guardLoc.x;
//    float deltaY = robotLoc.y - guardLoc.y;
//
//
//    if (std::abs(deltaX) > std::abs(deltaY))
//    {
//        if (robotLoc.x > guardLoc.x)
//        {
//            direction = { 1,0 }; // Move right
//        }
//        else if (robotLoc.x < guardLoc.x)
//        {
//            direction ={-1,0}; // Move left
//        }
//    }
//
//    else
//    {
//        if (robotLoc.y > guardLoc.y)
//        {
//            direction = {0,1}; // Move down
//        }
//        else if (robotLoc.y < guardLoc.y)
//        {
//            direction = {0, -1}; // Move up
//        }
//    }
//
//    int x = robotLoc.x - guardLoc.x;
//    int y = robotLoc.y - guardLoc.y;
//    x = (x +25) / 50;
//    y = (y +25) / 50;
//    x *= 50;
//    y *= 50;
//
//  
//    if (x-y != 0)// לא ללכת באלכסון
//    {
//        setDirection(direction);
//        std::cout << "nat in the slant \n";
//    }
//    else
//    {
//        std::cout << tempTest++ << " : " << x << " ," << y <<  " The Direction Is: " 
//                             << m_direction.x << ", " << m_direction.y  << std::endl;
//        setDirection(m_direction);//old direction
//    }
//
//
//  
//}
void Guard::updateDirection(sf::Vector2f robotLoc) {

    sf::Vector2f direction = { 0, 0 };

   
        if (std::abs(robotLoc.x - m_location.x) == 0 ) 
        { // בדיקה אם יש תנועה
            direction.x = (robotLoc.x > m_location.x) ? 1.f : -1.f;
        }
        else {
            direction.y = (robotLoc.y > m_location.y) ? 1.f : -1.f;
        }
    
    // הגדרת הכיוון החדש
    setDirection(direction);
}



//----------------------------------------------------------------------------
void Guard::move(float deltaTime)
{

    m_image.move(m_direction.x * ( m_pixelSize * deltaTime), m_direction.y * ( m_pixelSize * deltaTime));
    m_location.x += m_direction.x * ( m_pixelSize * deltaTime);
    m_location.y += m_direction.y * ( m_pixelSize * deltaTime);

}