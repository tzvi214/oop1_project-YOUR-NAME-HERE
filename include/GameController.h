#pragma once
#include <string>
#include <memory>
#include <fstream>
#include <vector>
#include "FirstWindow.h"
#include "SfmlManager.h"
#include "StaticObject.h"
#include "GameBoard.h"
#include "MovingObject.h"
#include "Rock.h"
#include "Robot.h"
#include "Guard.h"
#include "Door.h"
#include "Wall.h"
#include "Bomb.h"


class GameController
{
public:
	GameController() = default;
	void run();

private:
	sf::Clock m_gameClock;
	sf::Vector2f m_robotLoc;
	std::vector <std::unique_ptr<StaticObject>> m_staticObjVec;
	std::vector <std::unique_ptr<MovingObject>> m_movingObjVec;
	std::vector <std::unique_ptr<Bomb>> m_BombVec;
	SfmlManager m_SfmlManager{};
	unsigned int m_height = 0;
	unsigned int m_width = 0;

	void handleCollisionController(MovingObject&);
	void readAndAnalyze(std::string&);
	void updateThisLine(std::string&);
	void analyzeObj(char&, int);
	void handleFirstWindow(FirstWindow&) const;
	sf::Vector2f getDirection();// to delte this function
	//-------------------------------------
	void restartObjPlace();
	void mainLoop(sf::RenderWindow&);
	void draw(sf::RenderWindow&);
	void handleEvent();
	//-------------------------------------
	void addBomb();
	void deleteObjFromVec();
};
