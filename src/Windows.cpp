#include "Windows.h"

Windows::Windows(unsigned int height, unsigned int width)
	: m_height(height), m_width(width), m_window(sf::VideoMode(m_width*pixelSize, m_height* pixelSize), "SFML")
{
	m_window.close();
}
//-------------------------------------------------------------------
Windows::Windows()// default
	:m_height{ 10 }, m_width{ 10 }, m_window(sf::VideoMode(m_width* pixelSize, m_height* pixelSize), "SFML")
{
	m_window.close();
}