#pragma once
#include <SFML/Graphics.hpp>
#include "ObjName.h"
#include "SfmlManager.h"
#include "MovingObject.h"
#include "Robot.h"
#include "Information.h"


class Robot;

class Guard : public MovingObject
{
public:
	Guard(sf::Vector2f, SfmlManager&, Information&);
	void dountMove();
	virtual void updateDirection() override;
	virtual void move(float) override;
	virtual void setDead(bool = true);

	// --- Double Dispatch ---
	virtual void handleCollision(StaticObject& other) override;
	virtual void handleCollision(Robot& robot) override;
	virtual void goToFirstLoc()override { m_location = m_firstLoc; }


private:
	sf::Vector2f m_firstLoc;
};