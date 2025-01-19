#include "GameBoard.h"

GameBoard::GameBoard(unsigned int width, unsigned int heigth) : Windows(width, heigth) {}

void GameBoard::create(unsigned int  width, unsigned int heigth, int numberLevel)
{
	// update m_width and m_height. 
	m_width = width * m_pixelSize;
	m_height = heigth * m_pixelSize;
	std::string StrnumLev = std::to_string(numberLevel);

	// create new window. 
	m_window.create(sf::VideoMode(m_width, m_height), "Bomberman: Level: " + StrnumLev);

}

sf::RenderWindow& GameBoard::getWindow()
{
	return m_window;
}