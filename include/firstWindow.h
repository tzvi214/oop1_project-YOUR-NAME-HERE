#pragma once
#include "Windows.h"
#include "Button.h"
#include "ObjName.h"
#include <vector>
#include"SfmlManager.h"
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include "GameData.h"

class FirstWindow
{
public:
	FirstWindow(SfmlManager&);// =15 for default size of window
	void draw();
	void customerChoice();
	void playMusic();
	bool need2exit() const { return m_need2exit; }
	bool need2start() const { return m_need2start; }

private:
	//--- data members----
	const unsigned int m_pixelSize = 50;
	SfmlManager& m_sfmlManager;
	ObjName m_objName{};
	sf::Music m_menuSnd;
	std::vector<Button> m_buttons;
	bool m_need2exit = false;
	bool m_need2start = false;
	unsigned int m_height;
	unsigned int m_width;
	sf::RenderWindow m_window;

	//--- functions----
	sf::Text readHelpFromFile()const;
	void showHelp(sf::Text&);
	void wrapText(sf::Text& text, float maxWidth);


};