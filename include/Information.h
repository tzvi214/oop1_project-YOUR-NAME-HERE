#pragma once
#include <SFML/Graphics.hpp>
#include "SfmlManager.h"
#include "ObjName.h"
#include "CountdownTimer.h"


class Information
{
public:
	Information(SfmlManager&);
	//-------------- gift 1  ------------

	void addRobotLife() { m_lifeRobot++; }

	  //-------------- gift 2  ------------
	void need2killedGuard() { m_needToKillGuard = true; }
	bool isNeed2killed() const { return m_needToKillGuard ; }
	void killedGuard() { m_needToKillGuard = false; }

	//-------------- gift 3  ------------
	void addTime() { m_clock.addTime(); }
	//-------------- gift 4  ------------
	void frozeGuard();
	bool areFroze();

	 //-----------------------------------
	
	void setLevelFinish(const bool);
	void setScore(const int);
	void loseRobotLife();
	void increaseGuardCount();
	void setLevel(const int);
	//----------------------------------------
	bool need2addGift();
	void addRandomGift(sf::Vector2f loc);
	sf::Vector2f getNewGiftLoc() { return sf::Vector2f(m_newGiftLoc.x/50, m_newGiftLoc.y/50); }

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
	void playMusic();
private:
	sf::Sound m_hurtSnd;
	bool m_levelCompleted;
	bool m_robotKill;
	int m_score;
	int m_lifeRobot = 5;  // default
	int m_countGuard;
	bool m_needToKillGuard = false;
	int m_level;
	SfmlManager& m_SfmlManager;
	CountdownTimer m_clock{ 0 };
	//-----------------------------------
	int m_gameWidth =0;
	int m_gameHeight =0;
	sf::Vector2f m_roobotLoc{0,0};
	//---------------- gift 4---------
	sf::Clock m_frozeClock;
	bool m_froze = false;
	//----------------------------------
	bool m_need2addGift = false;
	sf::Vector2f m_newGiftLoc{0 ,0};
	
};