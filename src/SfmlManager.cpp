#include "SfmlManager.h"

SfmlManager::SfmlManager()
{

	// load the Font from file --> into sf::Font.
	if (!m_font.loadFromFile("CENSCBK.ttf"))
		std::cerr << "Failed to load CENCBK.ttf\n";

	// load the picture from file --> into Texture.
	if (!m_ExitTex.loadFromFile("Exit.png"))
		std::cerr << "Failed to load Exit.png\n";
	if (!m_HelpTex.loadFromFile("Help.png"))
		std::cerr << "Failed to load Help.png\n";
	if (!m_StartTex.loadFromFile("Start.png"))
		std::cerr << "Failed to load Start.png\n";


	std::cout << " c-tor SfmlMananger: SfmlMananger loaded successfully\n";
}

sf::Texture& SfmlManager::getTexture(ObjName objName)
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

sf::Text SfmlManager::getText(ObjName objName) const
{
	sf::Text textTemp;

	switch (objName)
	{
	case Font:
		textTemp.setFont(m_font);
		return textTemp;
		break;

	default:
		std::cerr << "Error: ObjName not found\n";
		throw std::invalid_argument("Invalid ObjName");
		break;
	}

}
