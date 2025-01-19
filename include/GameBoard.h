#pragma once 
#include "Windows.h"
#include "ObjName.h"
#include"SfmlManager.h"
#include "GameBoard.h"

class GameBoard : public Windows
{
public:
	GameBoard(unsigned int, unsigned int);
	void create(unsigned int, unsigned int, int);

	sf::RenderWindow& getWindow();


};