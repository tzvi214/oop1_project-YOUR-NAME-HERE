#pragma once
#include <SFML/Graphics.hpp>
#include "ObjName.h"
#include "SfmlManager.h"
#include "MovingObject.h"
#include "Robot.h"

class Robot;

class Guard : public MovingObject
{
public:
	Guard(sf::Vector2f, SfmlManager&);
	void goToFirstLoc() { m_location = m_firstLoc; }
	void dountMove();
	virtual void updateDirection(sf::Vector2f) override;
	virtual void move(float) override;

	// --- Double Dispatch ---
	virtual void handleCollision(StaticObject& other) override;
	virtual void handleCollision(Robot& robot) override;


private:
	sf::Vector2f m_firstLoc;
};