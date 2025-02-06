#pragma once
#include <SFML/Graphics.hpp>
namespace Place
{
    sf::Vector2f toPlace(const sf::Vector2f& position, float pixelSize);


    namespace Directions
    {
        const sf::Vector2f Center{ 0.0f,  0.0f };
        const sf::Vector2f Right{ 1.0f,  0.0f }; 
        const sf::Vector2f Left{ -1.0f,  0.0f }; 
        const sf::Vector2f Up{ 0.0f, -1.0f };  
        const sf::Vector2f Down{ 0.0f,  1.0f }; 

    }
}

namespace Score
{
    const int Guard{ 3 };
    const int NextLevel{ 25 };
}

namespace Data
{
    const unsigned int  pixelSize = 50;
    const unsigned int halfPixelSize = 25;
    const int lifeRobot = 5;
    const int throwable = 5;
}