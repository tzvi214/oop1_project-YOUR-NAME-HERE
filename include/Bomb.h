#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "MovingObject.h"
#include "Robot.h"
#include "Guard.h"
#include "Rock.h"
#include "Information.h"
#include <vector>


class Bomb :public StaticObject
{
public:
	Bomb(sf::Vector2f, SfmlManager&, Information&);
	void updateState();
	bool IsExploded();

	virtual void handleCollision(Guard&);
	virtual void handleCollision(Robot&); 
	//virtual void handleCollision(MovingObject&);
	virtual void handleCollision(Rock&);

	virtual void draw(sf::RenderWindow&) override;
	
private:
	int m_second = 0;
	float m_time = 0;
	sf::Sound m_explSnd;
	sf::Sound m_ticSnd;
	sf::Clock m_clock;
	sf::Sprite m_fireSpr;
	bool m_exploded = false;
	std::vector <sf::Vector2f> m_explosionLocVec;
	Information& m_information;
	sf::Text m_bombTime;
	//--------------------------------------
	void initializationBombVec();
	void playExpl();
	void playTic();
	void drawTime(sf::RenderWindow&);
};