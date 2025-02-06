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
#include "ExplosionZone.h"
#include "GameData.h"




class Bomb :public GameObject
{
public:
	Bomb(sf::Vector2f, SfmlManager&, Information&);
	~Bomb() {};
	void updateState();
	bool IsExploded();

	virtual void handleCollision(Guard&);
	virtual void handleCollision(Robot&); 
	virtual void handleCollision(Rock&);
	virtual void draw(sf::RenderWindow&) override;
	
private:
	std::vector <ExplosionZone> m_explosionZoneVec;

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
	void handleCollision(MovingObject&);
	void initializationBombVec();
	void playExpl();
	void playTic();
	void drawTime(sf::RenderWindow&);
};