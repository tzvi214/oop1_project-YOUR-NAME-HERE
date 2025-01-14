#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Windows
{
public:
	Windows(unsigned int , unsigned int );	
protected:
	const unsigned int m_pixelSize; // size of each pixel is 50
	unsigned int m_height;
	unsigned int m_width;
	sf::RenderWindow m_window;

};

