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

class FirstWindow : public Windows
{
public:
	FirstWindow(SfmlManager&);// =15 for default size of window
	void draw();
	void customerChoice();

	bool need2exit() const { return m_need2exit; }
	bool need2start() const { return m_need2start; }

private:
	//--- data members----
	SfmlManager& m_sfmlManager;
	ObjName m_objName{};
	std::vector<Button> m_buttons;
	bool m_need2exit = false;
	bool m_need2start = false;


	sf::Music m_menuSnd;
	//--- functions----
	sf::Text readHelpFromFile()const;
	void showHelp(sf::Text&);
	void wrapText(sf::Text& text, float maxWidth);
	void playMusic();

};