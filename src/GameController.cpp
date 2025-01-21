#include "GameController.h"
GameController::GameController()
	:m_SfmlManager{}, m_height{1}, m_width{1}
{ }					 
//--------------------------------------------------------
void GameController::run()
{
	//--------------------------
	FirstWindow firstWindow(m_SfmlManager);
	handleFirstWindow(firstWindow);
	if (firstWindow.need2exit())
		return;
	//--------------------------
	std::string fileName = "level01.txt";
	readAndAnalyze(fileName);

	//--------------------------
	GameBoard gameBoard(m_width, m_height);
	auto& window = gameBoard.getWindow();
	//auto window

	//--------------------------

	sf::Vector2f loc{ 0,0 };
	Robot robot(loc, m_SfmlManager); 
	loc = { 8, 6 };
	Guard guard(loc, m_SfmlManager);
	//---------------------------

	while(window.isOpen())
	{
      sf::Event event;
		if (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		robot.updateDirection();

		guard.updateDirection(robot.getLocation());

		auto deltaTime = m_gameClock.restart().asSeconds();

		window.clear();

		for (int i = 0; i < m_movingObjVec.size(); i++)
			m_movingObjVec.at(i).get()->draw(window);

		for (int i = 0; i < m_StaticObjectVec.size(); i++)
			m_StaticObjectVec.at(i).get()->draw(window);

		robot.move(deltaTime);
		guard.move(deltaTime);
		guard.draw(window);
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
void GameController::readAndAnalyze(std::string& fileName)
{
	// analyze the row and col every time
	m_height = 0;
	m_width = 0;
	auto file = std::ifstream(fileName);
	if (!file.is_open())
	{
		std::cerr << "Error Cannot open file" << fileName;
		return;
	}

	std::string line;
	while (getline(file, line))
	{
		updateThisLine(line);
		m_height++;
	}
	m_width = static_cast<unsigned int > (line.size());
}
//--------------------------------------------------------
void GameController::updateThisLine(std::string& line)
{
	if(line.empty())
		return;
	char ch;
	for (int i = 0; i < line.size(); i++)
	{
		ch = line[i];
		AnalyzeObj(ch, i);
	}
}
//--------------------------------------------------------
void GameController::AnalyzeObj(char& ch, int col)
{
	switch (ch)
	{
	case '/':
        m_movingObjVec.push_back(std::make_unique<Robot>(sf::Vector2f{ (float)col, (float)m_height}, m_SfmlManager));
		break;
	case '!':
		m_movingObjVec.push_back(std::make_unique<Guard>(sf::Vector2f{ (float)col, (float)m_height }, m_SfmlManager));
		break;
	case '#':
		m_StaticObjectVec.push_back(std::make_unique<Wall>(sf::Vector2f{ (float)col, (float)m_height }, m_SfmlManager));
		break;
	case '@':
		m_StaticObjectVec.push_back(std::make_unique<Rock>(sf::Vector2f{ (float)col, (float)m_height }, m_SfmlManager));
		break;
	case 'D':
		m_StaticObjectVec.push_back(std::make_unique<Door>(sf::Vector2f{ (float)col, (float)m_height }, m_SfmlManager));
		break;
	}
	//default ch will ba tile
}
//--------------------------------------------------------
void GameController::updateWindow()
{

	
}


