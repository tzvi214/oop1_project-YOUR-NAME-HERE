#include "Information.h"

bool Information::locInLevel(sf::Vector2f location) const
{
   
    return (location.x >= 0 && location.x <= (m_gameWidth +5) &&
        location.y >= 0 && location.y < (m_gameHeight +5));
}
