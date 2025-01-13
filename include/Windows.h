#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Windows
{
public:
	Windows(unsigned int , unsigned int );
	Windows();// default
	const int pixelSize = 50; // its nat need to be int
	bool isOpen() const { return m_window.isOpen(); }
	void openWindow() { m_window.create(sf::VideoMode(m_width * pixelSize, m_height * pixelSize), "SFML"); }
	void closeWindow() { m_window.close(); }
private:
	
	sf::RenderWindow m_window;
	unsigned int m_width;
	unsigned int m_height;
};

