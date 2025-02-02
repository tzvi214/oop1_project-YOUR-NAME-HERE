#pragma once
#include <SFML/Graphics.hpp>
#include "ObjName.h"
#include <iostream>


class SfmlManager
{
public:
	static SfmlManager& getInstance()
	{
		static SfmlManager instance; // מופע יחיד
		return instance;
	}
	sf::Texture& getTexture(ObjName); // return reference of texture according the ObgName(Enum). 
    sf::Text getText(ObjName) const ; // 

	SfmlManager(const SfmlManager&) = delete;
	SfmlManager& operator=(const SfmlManager&) = delete;
	

	//int LoadFromFile();
private:
	SfmlManager(); // c-tor load file to sf objects.
	sf::Texture m_ExitTex;
	sf::Texture m_HelpTex;
	sf::Texture m_StartTex;
	sf::Font m_font;
	sf::Texture m_RobotTex;
	sf::Texture m_WallTex;
	sf::Texture m_RockTex;
	sf::Texture m_Guard;
	sf::Texture m_Door;
	sf::Texture m_Temp;
	sf::Texture m_Bomb;
	sf::Texture m_Fire;
	sf::Texture m_Gift1;

};