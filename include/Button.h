#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
public:
	Button(sf::Vector2f, sf::Vector2f);
	bool userPressOnTheButton() const;

private:
	//  I need to add sign to each button
	sf::Vector2f VertexUp;
	sf::Vector2f VertexDown;
};

