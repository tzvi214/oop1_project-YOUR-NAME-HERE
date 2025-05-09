#include "GameController.h"

GameController::GameController()
	: m_information(m_SfmlManager)
{}
//--------------------------------------------------------
void GameController::run()
{
	FirstWindow firstWindow(m_SfmlManager);
	handleFirstWindow(firstWindow);
	if (firstWindow.need2exit())
		return;
	

	for (int i = 1; i <= m_numLevel ; i++)
	{
		m_information.setLevel(i);
		m_information.setLevelFinish(false);
		clearAllVec();
		std::string fileName = "level" + std::string(i < 10 ? "0" : "") + std::to_string(i) + ".txt";

		readAndAnalyze(fileName);

		m_information.setGameHeight((m_height - 1) * 50);
		m_information.setGameWidth((m_width - 1) * 50);


		int width = m_width * Data::pixelSize;
		int height = (m_height + 2) * Data::pixelSize;
		sf::RenderWindow window(sf::VideoMode(width, height), fileName);

		window.setFramerateLimit(60);
		m_gameClock.restart();// that in the first time the obj nat will jump
		mainLoop(window);
		if (m_information.getRobotKill()) {
			std::cout << "Robot end of life \nGame over \n";
			return;
		}
			

		if (m_information.getClock().isFinished()) {
			i--;
			continue;
		}

	}
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
	
	m_height--;

	file.close();
}
//--------------------------------------------------
void GameController::updateThisLine(std::string& line)
{
	char ch;
	if (isdigit(line[0]))
	{
		std::string str = line;
		int second = std::stoi(str); // Convert the string to an integer
		m_information.getClock().start(second);
		return;
	}
	for (int i = 0; i < line.size(); i++)
	{
		ch = line[i];
		analyzeObj(ch, i);
	}
	m_width = static_cast<unsigned int>(line.size());
	
}
//--------------------------------------------------
void GameController::analyzeObj(char& ch, int col)
{
	switch (ch)
	{
	case '/':
		m_movingObjVec.push_back(std::make_unique<Robot>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager, m_information));
		break;
	case '!':
		m_information.increaseGuardCount();
		//add stupid or smart guard
		if(col%3 == 1)// ranom guard
		m_movingObjVec.push_back(std::make_unique<SmartGuard>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager, m_information));
		else 
		m_movingObjVec.push_back(std::make_unique<StupidGuard>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager, m_information));

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
	case 'A':
		m_staticObjVec.push_back(std::make_unique<LifeGift>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
	case 'B':
		m_staticObjVec.push_back(std::make_unique<TimeGift>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
	case 'C':
		m_staticObjVec.push_back(std::make_unique<FrozeGift>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
	case 'F':
		m_staticObjVec.push_back(std::make_unique<KilledGift>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
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
//--------------------------------------------------
void GameController::restartObjPlace()
{
	m_information.playMusic();
	for (const auto& objMov : m_movingObjVec)
	{
		objMov->goToFirstLoc();
	}
	m_BombVec.clear();
	m_information.loseRobotLife();
}
//--------------------------------------------------
void GameController::mainLoop(sf::RenderWindow& window)
{
	m_gameClock.restart();// that in rhe first time the obj nat will jump
	playMusic();
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
		handleBombEvent();

		draw(window);
		if (m_information.getLevelFinish() || m_information.getRobotKill())
			break;

		if (m_information.getClock().isFinished()) {
			m_information.loseRobotLife();
			return;
		}
		
	}
}
//--------------------------------------------------
void GameController::draw(sf::RenderWindow& window)
{

	window.clear();
	drawTile(window);

	for (const auto& obj : m_movingObjVec) {
		obj->draw(window);
	}
	for (const auto& obj : m_staticObjVec) {
		obj->draw(window);
	}

	for (auto& bomb : m_BombVec) {
		bomb->draw(window); 

	}
	m_information.draw(window);

	window.display();
}
//--------------------------------------------------
void GameController::handleEvent()
{
	auto deltaTime = m_gameClock.restart().asSeconds();
	for (const auto& objMov : m_movingObjVec) 
	{
	   //if robot touch the guard i will se it in the next loop
	   if (objMov->need2restartPlace()) {
	   	restartObjPlace();
	   }

	   objMov->updateDirection();
	   handleCollisionController(*objMov); // call to function of this class.
	   objMov->move(deltaTime);
	}
	
	
	if (m_information.need2addGift()) {
		addGift();
	}
}
//--------------------------------------------------
void GameController::handleBombEvent() const
{

	

	for (auto& bomb : m_BombVec)
	{
		for (const auto& obj : m_staticObjVec)
		{
			{
				obj->handleCollision(*bomb);
			}
		}
	}

	for (auto& bomb : m_BombVec) {
		bomb->updateState();
	}
}
//--------------------------------------------------
void GameController::addBomb()
{
	// update loc on tile
	int newX = (m_information.getRobotLoc().x + 25) / 50;
	int newY = (m_information.getRobotLoc().y + 25) / 50;
	m_BombVec.push_back(std::make_unique<Bomb>(sf::Vector2f(newX, newY), m_SfmlManager, m_information));
}
void GameController::addGift()
{
	
	int random_number = rand() % (10 + m_numLevel *2 )+ 1;
	switch (random_number)
	{
	case 1:
		m_staticObjVec.push_back(std::make_unique<FrozeGift>(m_information.getNewGiftLoc(), m_SfmlManager));
		break;
	case 2:
		m_staticObjVec.push_back(std::make_unique<LifeGift>(m_information.getNewGiftLoc(), m_SfmlManager));
		break;
	case 3:
		m_staticObjVec.push_back(std::make_unique<TimeGift>(m_information.getNewGiftLoc(), m_SfmlManager));
		break;
	case 4:
		m_staticObjVec.push_back(std::make_unique<KilledGift>(m_information.getNewGiftLoc(), m_SfmlManager));
		break;
	default:
		break;
	}
}
//--------------------------------------------------
void GameController::deleteObjFromVec()
{
	std::erase_if(m_movingObjVec, [](const auto& obj) { return obj->IsDead(); });
	std::erase_if(m_BombVec, [](const auto& bomb) { return bomb->IsDead(); });
    std::erase_if(m_staticObjVec, [](const auto& obj) { return obj->IsDead(); });
}
//--------------------------------------------------
void GameController::clearAllVec()
{
	m_BombVec.clear();
	m_movingObjVec.clear();
	m_staticObjVec.clear();
}
//--------------------------------------------------
void GameController::gameOver() const
{
	std::cout << "GameOver\n";
}
//--------------------------------------------------
void GameController::playMusic()
{
	m_soundGame.openFromFile("gameSound.mp3");
	m_soundGame.setLoop(true);
	m_soundGame.play();
}
//--------------------------------------------------
void GameController::drawTile(sf::RenderWindow& window)
{
	sf::Sprite tile(m_SfmlManager.getTexture(ObjName::E_Tile));
	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			tile.setPosition(i * Data::pixelSize, j * Data::pixelSize);
			window.draw(tile);
		}
	}
}
