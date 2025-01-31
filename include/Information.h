#pragma once
#include <SFML/Graphics.hpp>
#include "SfmlManager.h"
#include "ObjName.h"
#include "CountdownTimer.h"


class Information
{
public:
	
	 //-----------------------------------
	Information(SfmlManager&);
	void setLevelFinish(const bool);
	void setScore(const int);
	void loseRobotLife();
	void increaseGuardCount();
	void setLevel(const int);
	void setRobotKill(const bool);


	int getLevel() const;
	int getGuardCount() const;
	int getRobotLife() const;
	bool getLevelFinish() const;
	bool getRobotKill() const;
	CountdownTimer& getClock();

	void draw(sf::RenderWindow&);

	 //-----------------------------------
	void setRobotLoc(sf::Vector2f& robotLoc) { m_roobotLoc = robotLoc; }
	void setGameWidth(int col) { m_gameWidth = col; }
	void setGameHeight(int row) { m_gameHeight = row ; }
	bool locInLevel(sf::Vector2f) const;
	sf::Vector2f getRobotLoc() const { return m_roobotLoc ; }

private:
	bool m_levelCompleted;
	bool m_robotKill;
	int m_score;
	int m_lifeRobot = 5;  // default
	int m_countGuard;
	int m_level;
	SfmlManager& m_SfmlManager;
	CountdownTimer m_clock{ 0 };
	//-----------------------------------
	int m_gameWidth =0;
	int m_gameHeight =0;
	sf::Vector2f m_roobotLoc{0,0};

};