#include "firstWindow.h"
firstWindow::firstWindow(unsigned int height, unsigned int width)
	: Windows(height, width)
{
	//analyze the buttons	
	sf::Sprite startSprite(m_textureManager.getTexture(ObjName::Start));
	m_buttons.push_back(Button(sf::Vector2f(0, 5), sf::Vector2f(0, 0), startSprite));

	sf::Sprite HelpSprite(m_textureManager.getTexture(ObjName::Help));
	m_buttons.push_back(Button(sf::Vector2f(5, 5), sf::Vector2f(5, 5), HelpSprite));

	sf::Sprite ExitSprite(m_textureManager.getTexture(ObjName::Exit));
	m_buttons.push_back(Button(sf::Vector2f(10, 5), sf::Vector2f(5, 5), ExitSprite));
}
//-------------------------------------------------------------------
void firstWindow::draw()
{
	for (auto& button : m_buttons)
	{
		button.draw(m_window);
	}
}
//-------------------------------------------------------------------
void firstWindow::tempFunction()
{
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2f location = { float(event.mouseButton.x), float(event.mouseButton.y) };
				for (auto& button : m_buttons)
				{
					if (button.userPressOnTheButton(location))
					{
						std::cout << "Button pressed\n";
					}
				}
			}
		}
		m_window.clear();
		draw();
		m_window.display();
	}
}
//-------------------------------------------------------------------
//void firstWindow::readFromFile()
//{
//	std::cout << "reading from file .../n";
//}
