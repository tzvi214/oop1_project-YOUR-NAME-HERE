#pragma once
#include <SFML/Graphics.hpp>
#include "ObjName.h"
#include <iostream>


class SfmlManager
{
public:
	SfmlManager(); // c-tor load file to sf objects.
	sf::Texture& getTexture(ObjName); // return reference of texture according the ObgName(Enum). 
	sf::Text getText(ObjName) const; // return reference of font.

private:
	sf::Texture m_ExitTex;
	sf::Texture m_HelpTex;
	sf::Texture m_StartTex;
	sf::Font m_font;
	sf::Texture m_RobotTex;
	sf::Texture m_WallTex;
	sf::Texture m_RockTex;
	sf::Texture m_Guard;
};