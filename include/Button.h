#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
public:
	Button(sf::Vector2f , sf::Vector2f, sf::Sprite&);
	bool userPressOnTheButton(sf::Vector2f&) const;
	void draw(sf::RenderWindow& window) const { window.draw(m_image); } //maybe it should nat be const
private:
	//  I need to add sign to each button
	sf::Vector2f VertexUp;
	sf::Vector2f VertexDown;
	sf::Sprite m_image;
};

