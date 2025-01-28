#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"

class MovingObject :public StaticObject
{
public:
	MovingObject(sf::Vector2f, SfmlManager&, ObjName);
	void setDirection(sf::Vector2f);
	virtual void move(float) {};
	virtual void updateDirection(sf::Vector2f) {};
	virtual ~MovingObject() = default;
	virtual bool need2restartPlace() const { return m_need2restartPlace; }
	virtual void goToFirstLoc() {};
protected:
	sf::Vector2f m_direction{ 0, 0 };// defult nat moving
	//sf::Vector2f m_dirBeforeStopped{ 0,0 };
	bool m_need2restartPlace = false;
};