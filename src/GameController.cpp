#include "GameController.h"

//--------------------------------------------------------
void GameController::run()
{
	// ------ need do write this FirstWindow in private. ------
	FirstWindow firstWindow(m_SfmlManager);
	handleFirstWindow(firstWindow);
	if (firstWindow.need2exit())
		return;
	//---------------------------------------------------

	std::string fileName = "level01.txt";
	readAndAnalyze(fileName);

	GameBoard gameBoard(m_width, m_height + 2);
	auto& window = gameBoard.getWindow();

	window.setFramerateLimit(60);
	mainLoop(window);

}
//--------------------------------------------------
void GameController::handleCollisionController(MovingObject& movingObject)
{
	// call to function of StaticObject class
	for (const auto& obj : m_movingObjVec) // A moving object meets a moving object
	{
		if (movingObject.checkCollision(*obj)) // if (movingObject == obj) return false. else true
		{
			movingObject.handleCollision(*obj); // call to function of StaticObject class
			/*
			Function is correct both if a robot gets stuck in a guard and if the guard gets stuck in the robot
			*/
		}
	}

	for (const auto& obj : m_staticObjVec)  // A moving object meets a stationary object
	{
		if (movingObject.checkCollision(*obj)) //
		{
			movingObject.handleCollision(*obj);
		}
	}

	for (const auto& obj : m_BombVec)
	{
		movingObject.handleCollision(*obj);
	}
}
//--------------------------------------------------
void GameController::readAndAnalyze(std::string& fileName)
{
	auto file = std::ifstream(fileName);
	if (!file.is_open())
	{
		std::cerr << "Error: Cannot open file " << fileName << std::endl;
		return;
	}

	// Reset the rows and columns for each step.
	m_height = m_width = 0;

	// go to all line in file and update the vec.
	std::string line;
	while (getline(file, line))
	{
		updateThisLine(line);
		m_height++;
	}
	m_width = static_cast<unsigned int>(line.size());
}
//--------------------------------------------------
void GameController::updateThisLine(std::string& line)
{
	char ch;
	for (int i = 0; i < line.size(); i++)
	{
		ch = line[i];
		analyzeObj(ch, i);
	}
}
//--------------------------------------------------
void GameController::analyzeObj(char& ch, int col)
{
	switch (ch)
	{
	case '/':
		m_movingObjVec.push_back(std::make_unique<Robot>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
	case '!':
		m_movingObjVec.push_back(std::make_unique<Guard>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
	case '#':
		m_staticObjVec.push_back(std::make_unique<Wall>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
	case '@':
		m_staticObjVec.push_back(std::make_unique<Rock>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
	case 'D':
		m_staticObjVec.push_back(std::make_unique<Door>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
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
sf::Vector2f GameController::getDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		return (sf::Vector2f{ 1, 0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		return (sf::Vector2f{ -1, 0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		return (sf::Vector2f{ 0, -1 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		return (sf::Vector2f{ 0, 1 });
	}
	else
		return (sf::Vector2f{ 0, 0 });


}
//--------------------------------------------------
void GameController::restartObjPlace()
{
	for (const auto& objMov : m_movingObjVec)
	{
		objMov->goToFirstLoc();
	}
	m_BombVec.clear();
}
//--------------------------------------------------
void GameController::mainLoop(sf::RenderWindow& window)
{
	m_gameClock.restart();// that in rhe first time the obj nat will jump
	while (window.isOpen())
	{
		sf::Event event;
		if (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B)
				addBomb();
		}
		deleteObjFromVec();
		handleEvent();
		//----------- Bomb Event ---------------
		for (auto& bomb : m_BombVec) 
		{
			for (const auto& obj : m_staticObjVec)  
			{
				{
					obj->handleCollision(*bomb);
				}
			}
		}

		draw(window);

	}
}
//--------------------------------------------------
void GameController::draw(sf::RenderWindow& window)
{
	window.clear();

	for (const auto& obj : m_movingObjVec) {
		obj->draw(window);
	}
	for (const auto& obj : m_staticObjVec) {
		obj->draw(window);
	}

	for (auto& bomb : m_BombVec) {
		bomb->draw(window); // Replace sprite to fire 

	}
	window.display();
}
//--------------------------------------------------
void GameController::handleEvent()
{
	// that vary nat good i need to move the robot from the vector of moving object
	for (const auto& objMov : m_movingObjVec) // to find location for robot
	{
		//if (auto* robot = dynamic_cast<Robot*>(objMov.get()))
		if (objMov.get()->getType() == ObjName::E_Robot)
		{
			//	m_robotLoc = robot->getLocation();
			m_robotLoc = objMov.get()->getLocation();
			break;
		}
	}

	//****
	auto deltaTime = m_gameClock.restart().asSeconds();
	for (const auto& objMov : m_movingObjVec) 
	{
	   //if robot touch the guard i will se it in the next loop
	   if (objMov->need2restartPlace()) {
	   	restartObjPlace();
	   }

	   objMov->updateDirection(m_robotLoc);// false
	   handleCollisionController(*objMov); // call to function of this class.
	   objMov->move(deltaTime);
	}
	
	for (auto& bomb : m_BombVec) {
		bomb->updateState(); // Replace sprite to fire 
	}
}
//--------------------------------------------------
void GameController::addBomb()
{
	// update loc on tile
	int newX = (m_robotLoc.x + 25) / 50;
	int newY = (m_robotLoc.y + 25) / 50;

	//Bomb bomb(sf::Vector2f(newX, newY), m_SfmlManager);
	m_BombVec.push_back(std::make_unique<Bomb>(sf::Vector2f(newX, newY), m_SfmlManager));
}
//--------------------------------------------------
void GameController::deleteObjFromVec()
{
	std::erase_if(m_movingObjVec, [](const auto& obj) { return obj->IsDead(); });
	std::erase_if(m_BombVec, [](const auto& bomb) { return bomb->IsDead(); });
    std::erase_if(m_staticObjVec, [](const auto& obj) { return obj->IsDead(); });


}
