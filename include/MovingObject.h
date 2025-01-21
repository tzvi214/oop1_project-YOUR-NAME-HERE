#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"

class MovingObject :public StaticObject
{
public:
	MovingObject(sf::Vector2f, SfmlManager&, ObjName type);
	void setDirection(sf::Vector2f);
	virtual void move(float); // i will change it to abc 
protected:
	sf::Vector2f m_direction{ 0, 0 };// defult nat moving
private:

	
};