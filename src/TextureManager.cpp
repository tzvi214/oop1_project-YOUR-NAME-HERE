#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager()
{
	// load the picture from file --> into Texture.
	if (!m_ExitTex.loadFromFile("Exit.png"))
		std::cerr << "Failed to load Exit.png\n";
	if (!m_HelpTex.loadFromFile("Help.png"))
		std::cerr << "Failed to load Help.png\n";
	if (!m_StartTex.loadFromFile("Start.png"))
		std::cerr << "Failed to load Start.png\n";

	std::cout << " c-tor TextureManager: Textures loaded successfully\n";
}

sf::Texture& TextureManager::getTexture(ObjName objName)
{
	// return refernce of texture according the ObgName(Enum).
	switch (objName)
	{
	case Exit:
		return m_ExitTex;
		break;
	case Start:
		return m_StartTex;
		break;
	case Help:
		return m_HelpTex;
		break;

	default:
		std::cerr << "Error: ObjName not found\n";
		throw std::invalid_argument("Invalid ObjName");
		break;
	}
}