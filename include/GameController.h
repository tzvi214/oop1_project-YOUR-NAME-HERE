#pragma once
#include "FirstWindow.h"
#include <SfmlManager.h>
#include "StaticObject.h"
#include "GameBoard.h"
#include "MovingObject.h" // Fixed include statement
#include "Robot.h"
class GameController
{
public:

 void run();
private:
	SfmlManager m_SfmlManager{};
	void handleFirstWindow(FirstWindow&) const;
	sf::Vector2f getDirection();
};