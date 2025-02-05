#include <iostream>
#include "Windows.h"
#include "GameController.h"
#include <SFML/Graphics.hpp>
#include "SfmlManager.h"
#include "ObjName.h"
//-------------------
#include <cstdlib>  
#include <ctime> 
int main()
{
	srand(time(0));

	GameController game;
	game.run();
	return EXIT_SUCCESS;
	return EXIT_SUCCESS;
}