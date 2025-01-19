#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"

class MovingObject :public StaticObject
{
public:
	MovingObject(sf::Vector2f, SfmlManager&, ObjName type);
	void setDirection(sf::Vector2f);
	void move(float);
private:
	sf::Vector2f m_direction{0, 0};// defult nat moving
	
};