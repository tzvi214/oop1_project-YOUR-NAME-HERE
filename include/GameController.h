#pragma once
#include "FirstWindow.h"
#include <SfmlManager.h>
#include "StaticObject.h"
#include "GameBoard.h"
#include "MovingObject.h" // Fixed include statement
#include "Robot.h"
#include "Guard.h"
#include <memory>
//

#include <iostream>
#include <filesystem>
//

class GameController
{
public:
	GameController() ;

 void play();
private:
	SfmlManager m_SfmlManager{};
	sf::Clock m_gameClock;
	
	std::unique_ptr<MovingObject> m_movingObj;
	std::unique_ptr<StaticObject> m_StaticObject;
	int m_with =0;//default
	int m_wight =0;//default
	void handleFirstWindow(FirstWindow&) const;
	void readNanalyze();

};