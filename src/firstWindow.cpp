#include "FirstWindow.h"
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

FirstWindow::FirstWindow(SfmlManager& sfmlManager)
	: Windows(15, 15), m_sfmlManager {sfmlManager }
{
	//analyze the buttons	
	sf::Sprite startSprite(m_sfmlManager.getTexture(ObjName::Start));
	m_buttons.push_back(Button(sf::Vector2f(0, 0), startSprite, ObjName::Start));

	sf::Sprite HelpSprite(m_sfmlManager.getTexture(ObjName::Help));
	m_buttons.push_back(Button(sf::Vector2f(5, 0), HelpSprite, ObjName::Help));

	sf::Sprite ExitSprite(m_sfmlManager.getTexture(ObjName::Exit));
	m_buttons.push_back(Button(sf::Vector2f(10, 0), ExitSprite, ObjName::Exit));


}
//-------------------------------------------------------------------
void FirstWindow::draw()
{
	for (auto& button : m_buttons)
	{
		button.draw(m_window);
	}
}
//-------------------------------------------------------------------
void FirstWindow::customerChoice()
{
	m_need2exit = false; // analyze aviary time
	m_need2exit = false; // analyze aviary time
	sf::Text text;


	while (m_window.isOpen())
	{
		sf::Event event;
		if (m_window.pollEvent(event))
		{


			if (event.type == sf::Event::Closed)
				m_window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2f location = { float(event.mouseButton.x), float(event.mouseButton.y) };
				for (int i = 0; i < m_buttons.size(); i++)
				{
					if (m_buttons[i].userPressOnTheButton(location))
					{
						switch (m_buttons[i].getObjType())
						{
						case ObjName::Start:
							std::cout << "Start button pressed \n";
							m_need2start = true;
							m_window.close();
							return;
						case ObjName::Help:
							std::cout << "Help button pressed \n";
							text = readHelpFromFile();
							m_window.clear();
							m_window.draw(text);
							m_window.display();
							std::this_thread::sleep_for(std::chrono::seconds(5));
							break;
						case ObjName::Exit:
							std::cout << "Exit button pressed \n";
							m_need2exit = true;
							m_window.close();
							return;
						}
					}

				}
			}
		}
		m_window.clear();
		draw();
		m_window.display();

	}
}
//------------------------------------------------------------------
sf::Text FirstWindow::readHelpFromFile() const
{
	//I want to read the contents of the file and print it to the SFML window,
	//	(Continue - if there are many characters I want the window to be scrollable.)

	std::cout << "reading from file ... \n";

	std::ifstream file("help.txt");
	if (!file)
	{
		std::cerr << "Failed to load help.txt\n";
	}

	std::ostringstream ss; // object to hold the content of the file
	ss << file.rdbuf(); // read the file
	std::string fileContent = ss.str(); // Convert file contents to a string 

	sf::Text text = m_sfmlManager.getText(ObjName::Font); // Returns a text object with a font defined inside it.
	text.setString(fileContent);
	text.setCharacterSize(24);
	const sf::Color gold(255, 215, 0); // color golg
	const sf::Color silver(192, 192, 192); // color silver
	text.setFillColor(gold);
	text.setOutlineColor(silver);
	text.setOutlineThickness(0.5);
	text.setPosition(2, 2);

	return text;
}
//-------------------------------------------------------------------