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

	if (!m_WallTex.loadFromFile("Wall.png"))

		std::cerr << "Failed to load Wall.png\n";
	if (!m_RobotTex.loadFromFile("Robot.png"))
		std::cerr << "Failed to load Robot.png\n";

	if (!m_RockTex.loadFromFile("Rock.png"))
		std::cerr << "Failed to load Rock.png\n";

	if (!m_Guard.loadFromFile("Guard.png"))
		std::cerr << "Failed to load Guard.png\n";

	if (!m_Door.loadFromFile("Door.png"))
		std::cerr << "Failed to load Door.png\n";

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
	case E_Robot:
		return m_RobotTex;
		break;
	case E_Wall:
		return m_WallTex;
		break;
	case E_Rock:
		return m_RockTex;
		break;
	case E_Guard:
		return m_Guard;
		break;
	case E_Door:
		return m_Door;
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
