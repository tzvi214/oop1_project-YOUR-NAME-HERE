#include "GameController.h"
//--------------------------------------------------------
void GameController::run()
{

	FirstWindow firstWindow(m_SfmlManager);
	handleFirstWindow(firstWindow);
	if (firstWindow.need2exit())
		return;

	sf::Clock gameClock;
	sf::Vector2f loc{ 0,0 };
	//MovingObject tempObj(loc, m_SfmlManager, ObjName::E_Robot);
	Robot robot(loc, m_SfmlManager); 

	GameBoard gameBoard(15, 15);

    auto& window = gameBoard.getWindow();
	sf::Vector2f direction{ 0,0 };

	while(window.isOpen())
	{
	 sf::Event event;
		if (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			robot.ChooseDirection();
		}
		
		auto deltaTime = gameClock.restart().asSeconds();
	//	tempObj.setDirection(direction);
		window.clear();
		robot.move(deltaTime);
		robot.draw(window);
		window.display();
	}
}
//--------------------------------------------------------
void GameController::handleFirstWindow(FirstWindow& window) const
{
	window.customerChoice();

	if (window.need2exit())
	{
		std::cout << "Exiting For The Game \n";
	}
	else if (window.need2start())
	{
		std::cout << "Starting The Game\n";
	}
}
//--------------------------------------------------------

