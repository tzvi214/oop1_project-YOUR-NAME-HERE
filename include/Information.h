#pragma once
#include <SFML/Graphics.hpp>


class Information
{
public:
	void setRobotLoc(sf::Vector2f& robotLoc) { m_roobotLoc = robotLoc; }
	void setGameWidth(int col) { m_gameWidth = col; }
	void setGameHeight(int row) { m_gameHeight = row ; }
	bool locInLevel(sf::Vector2f) const;
	sf::Vector2f getRobotLoc() const { return m_roobotLoc ; }

private:
	int m_gameWidth =0;
	int m_gameHeight =0;
	sf::Vector2f m_roobotLoc{0,0};

};