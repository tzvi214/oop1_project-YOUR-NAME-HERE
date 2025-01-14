#pragma once
#include <SFML/Graphics.hpp>
#include "ObjName.h"

class TextureManager
{
public:
	TextureManager(); // c-tor load the picture from file --> into Texture.
	sf::Texture& getTexture(ObjName); // return refernce of texture according the ObgName(Enum). 

private:
	sf::Texture m_ExitTex;
	sf::Texture m_HelpTex;
	sf::Texture m_StartTex;
};