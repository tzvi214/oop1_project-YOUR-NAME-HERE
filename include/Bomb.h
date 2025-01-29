#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Robot.h"
#include "Guard.h"
#include "Rock.h"
//class Rock;


class Bomb :public StaticObject
{
public:
	Bomb(sf::Vector2f, SfmlManager&);
	void updateState();
	bool IsExploded();

	virtual void handleCollision(Guard&);
	virtual void handleCollision(Robot&);
	virtual void handleCollision(Rock&);
	virtual void draw(sf::RenderWindow&) override;
private:
	sf::Clock m_clock;
	sf::Sprite m_fireSpr;
	bool m_exploded = false;
};