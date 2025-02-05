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

	

	if (!m_Bomb.loadFromFile("Bomb.png"))
		std::cerr << "Failed to load Bomb.png\n";

	if (!m_Fire.loadFromFile("Fire.png"))
		std::cerr << "Failed to load Fire.png\n";

	if (!m_Gift1.loadFromFile("Present1.png"))
		std::cerr << "Failed to load Present1.png\n";

	if (!m_Gift2.loadFromFile("Present2.png"))
		std::cerr << "Failed to load Present2.png\n";

	if (!m_Gift3.loadFromFile("Present3.png"))
		std::cerr << "Failed to load Present3.png\n";

	if (!m_Gift4.loadFromFile("Present4.png"))
		std::cerr << "Failed to load Present4.png\n";

	if (!m_hurtSnd.loadFromFile("hurt.wav"))
		std::cerr << "Failed to load hurt.wav\n";

	if (!m_explSnd.loadFromFile("expl.wav"))
		std::cerr << "Failed to load expl.wav\n";

	if (!m_bombTicSnd.loadFromFile("BombTic.ogg"))
		std::cerr << "Failed to load BombTic.ogg\n";

	if (!m_TouchGiftSnd.loadFromFile("touchGift.wav"))
		std::cerr << "Failed to load touchGift.wav\n";

	//-------------------------------------------------

	if (!m_Temp.loadFromFile("temp_5.png"))
		std::cerr << "Failed to load temp_5.png\n";


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
	case E_Temp:
		return m_Temp;
		break;
	case E_Bomb:
		return m_Bomb;
		break;
	case E_Fire:
		return m_Fire;
		break;
	case E_Gift1:
		return m_Gift1;
		break;
	case E_Gift2:
		return m_Gift2;
		break;
	case E_Gift3:
		return m_Gift3;
		break;
	case E_Gift4:
		return m_Gift4;
		break;



	default:
		std::cerr << "Error: ObjName not found\n";
		throw std::invalid_argument("Invalid ObjName");
		break;
	}
}

 sf::Text SfmlManager::getText(ObjName objName)const
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

 sf::SoundBuffer& SfmlManager::getSound(Snd snd)
 {
	 switch (snd)
	 {
	 case hurt:
		 return m_hurtSnd;
	 case explosion:
		 return m_explSnd;
	 case bombTic:
		 return m_bombTicSnd;
	 case touchGift:
		 return m_TouchGiftSnd;
	 }
 }
