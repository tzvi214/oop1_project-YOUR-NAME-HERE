#include "GameData.h"

sf::Vector2f Place::toPlace(const sf::Vector2f& position, float pixelSize)
{
    int newX = static_cast<int>(position.x + Data::halfPixelSize) / static_cast<int>(pixelSize);
    int newY = static_cast<int>(position.y + Data::halfPixelSize) / static_cast<int>(pixelSize);
    newX *= static_cast<int>(pixelSize);
    newY *= static_cast<int>(pixelSize);
    return { static_cast<float>(newX), static_cast<float>(newY) };

}
