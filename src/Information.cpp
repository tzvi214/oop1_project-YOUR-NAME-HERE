#include "Information.h"
//--------------------------------------------------------------
Information::Information(SfmlManager& sfMan) :
	m_SfmlManager(sfMan), m_levelCompleted(false), m_score(0), m_countGuard(0), m_robotKill(false),
	m_hurtSnd{}
{
	m_hurtSnd.setBuffer(m_SfmlManager.getSound(Snd::hurt));
}
//--------------------------------------------------------------
void Information::frozeGuard()
{
	m_froze = true;
	m_frozeClock.restart();
}
//--------------------------------------------------------------

bool Information::areFroze()
{
	if (m_frozeClock.getElapsedTime().asSeconds() >= m_timeOfFroze) {
		m_froze = false;
	}
	return m_froze;
}
//--------------------------------------------------------------
bool Information::locInLevel(sf::Vector2f location) const
{
   
    return (location.x >= 0 && location.x <= (m_gameWidth +Data::throwable) &&
        location.y >= 0 && location.y < (m_gameHeight + Data::throwable));
}
//--------------------------------------------------------------
void Information::playMusic()
{
	m_hurtSnd.setVolume(100);
	m_hurtSnd.play();
}
//--------------------------------------------------------------
void Information::setLevelFinish(const bool flag)
{
	m_levelCompleted = flag;
	
	if (flag)
		m_score += (Score::Guard * m_countGuard) + Score::NextLevel;
	// nat to be froze in the next level
	m_froze = false;
}
//--------------------------------------------------------------
void Information::setScore(const int score)
{
	m_score += score;
}
//--------------------------------------------------------------
void Information::loseRobotLife()
{
	
	if (m_lifeRobot-- <= 0) {
		m_robotKill = true;
	}
}
//--------------------------------------------------------------
void Information::increaseGuardCount() {
	m_countGuard++;
}
//--------------------------------------------------------------
void Information::setLevel(const int num)
{
	m_level = num;
	m_countGuard = 0;
}
//--------------------------------------------------------------
bool Information::need2addGift()
{
	if (m_need2addGift) {
		m_need2addGift = false;
		return true;
	}
	
	return m_need2addGift;
}
//--------------------------------------------------------------
void Information::addRandomGift(sf::Vector2f loc)
{
	m_need2addGift = true;
	m_newGiftLoc = loc;
}
//--------------------------------------------------------------
bool Information::getRobotKill() const
{
	return m_robotKill;
}
//--------------------------------------------------------------
int Information::getLevel() const
{
	return m_level;
}
//--------------------------------------------------------------
int Information::getGuardCount() const {
	return m_countGuard;
}
//--------------------------------------------------------------
int Information::getRobotLife() const
{
	return m_lifeRobot;
}
//--------------------------------------------------------------
bool Information::getLevelFinish() const
{
	return m_levelCompleted;
}
//--------------------------------------------------------------
CountdownTimer& Information::getClock()
{
	return m_clock;
}
//--------------------------------------------------------------
void Information::draw(sf::RenderWindow& window)
{
	// Need to optimize
	auto Life = m_SfmlManager.getText(ObjName::Font);
	auto score = m_SfmlManager.getText(ObjName::Font);
	auto level = m_SfmlManager.getText(ObjName::Font);
	auto clock = m_SfmlManager.getText(ObjName::Font);
	m_clock.update();

	const sf::Color lightBlue(173, 216, 230);
	//2*50 ==> This is the extra space in the window for displaying the data. 
	//------life---------
	auto posy = window.getSize().y - (2 * 50);
	Life.setPosition(0, posy);
	score.setPosition(60, posy);
	level.setPosition(180, posy);
	clock.setPosition(260, posy);

	Life.setString("Life: \n " + std::to_string(m_lifeRobot));
	score.setString("Score: \n " + std::to_string(m_score));
	level.setString("Level: \n " + std::to_string(m_level));
	clock.setString("Clock: \n " + m_clock.getTimeString());

	Life.setCharacterSize(24);
	score.setCharacterSize(24);
	level.setCharacterSize(24);
	clock.setCharacterSize(24);

	Life.setFillColor(lightBlue);
	score.setFillColor(lightBlue);
	level.setFillColor(lightBlue);
	clock.setFillColor(lightBlue);


	window.draw(Life);
	window.draw(score);
	window.draw(level);
	window.draw(clock);

}
