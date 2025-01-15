#include "FirstWindow.h"

FirstWindow::FirstWindow(unsigned int height, unsigned int width)
	: Windows(height, width)
{
	//analyze the buttons	
	sf::Sprite startSprite(m_textureManager.getTexture(ObjName::Start));
	m_buttons.push_back(Button(sf::Vector2f(0, 0), startSprite, ObjName::Start));

	sf::Sprite HelpSprite(m_textureManager.getTexture(ObjName::Help));
	m_buttons.push_back(Button(sf::Vector2f(5, 0), HelpSprite, ObjName::Help));

	sf::Sprite ExitSprite(m_textureManager.getTexture(ObjName::Exit));
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
				for (int i =0; i< m_buttons.size(); i++)
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
							readFromFile();
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
void FirstWindow::readFromFile() const
{
	std::cout << "reading from file ... \n";
}
//-------------------------------------------------------------------

