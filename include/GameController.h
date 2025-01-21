#pragma once
#include "FirstWindow.h"
#include <SfmlManager.h>
#include "StaticObject.h"
#include "GameBoard.h"
#include "Wall.h"
#include "Robot.h"
#include "Guard.h"
#include "Rock.h"
#include "Door.h"
#include "MovingObject.h" // Fixed include statement
#include <memory>
#include "vector"
#include "string"
#include <iostream>
#include <filesystem>
#include <fstream>
//

class GameController
{
public:
	GameController() ;

 void run();
private:
	SfmlManager m_SfmlManager;
	sf::Clock m_gameClock;
	
	std::vector<std::unique_ptr <MovingObject> > m_movingObjVec;
	std::vector<std::unique_ptr <StaticObject> > m_StaticObjectVec;

	unsigned int m_height ;//default
	unsigned int m_width; //default

	void handleFirstWindow(FirstWindow&) const;
	void readAndAnalyze(std::string&);
	void updateThisLine(std::string &);
	void AnalyzeObj(char&, int );
	void updateWindow();
};