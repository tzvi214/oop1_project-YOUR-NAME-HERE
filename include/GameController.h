#pragma once
#include <string>
#include <memory>
#include <fstream>
#include <vector>
#include "FirstWindow.h"
#include "SfmlManager.h"
#include "GameObject.h"
#include "MovingObject.h"
#include "Rock.h"
#include "Robot.h"
#include "Guard.h"
#include "Door.h"
#include "Wall.h"
#include "Bomb.h"
#include "Information.h"
#include "CountdownTimer.h"
#include "Gift.h"
#include "FrozeGift.h"
#include "LifeGift.h"
#include "TimeGift.h"
#include "KilledGift.h"
#include <cstdlib>  
#include <ctime> 
#include <SFML/Audio.hpp>
#include "SmartGuard.h"
#include "StupidGuard.h"



class GameController
{
public:
	GameController();
	void run();

private:
	sf::Clock m_gameClock;
	sf::Music m_soundGame;
	std::vector <std::unique_ptr<GameObject>> m_staticObjVec;
	std::vector <std::unique_ptr<MovingObject>> m_movingObjVec;
	std::vector <std::unique_ptr<Bomb>> m_BombVec;
	SfmlManager& m_SfmlManager = SfmlManager::getInstance();
	Information m_information;
	unsigned int m_height = 0;
	unsigned int m_width = 0;
	unsigned int m_numLevel = 3;

	void handleCollisionController(MovingObject&);
	void readAndAnalyze(std::string&);
	void updateThisLine(std::string&);
	void analyzeObj(char&, int);
	void handleFirstWindow(FirstWindow&) const;
	void restartObjPlace();
	void mainLoop(sf::RenderWindow&);
	void draw(sf::RenderWindow&);
	void handleEvent();
	void handleBombEvent() const;
	
	void addBomb();
	void addGift();

	void deleteObjFromVec();
	
	void clearAllVec();
	void gameOver() const;
	
	void playMusic();
	void drawTile(sf::RenderWindow&);
};
