#pragma once
#include <SFML/Graphics.hpp>
#include "ObjName.h"
#include "SfmlManager.h"
#include "MovingObject.h"
#include "Robot.h"
#include "Information.h"
#include <cstdlib>  
#include <ctime> 

class Robot;

class Guard : public MovingObject
{
public:
	Guard(sf::Vector2f, SfmlManager&, Information&);
	~Guard() = default;
	void dountMove();
	virtual void updateDirection() {};
	virtual void move(float) override;
	virtual void setDead(bool = true);

	// --- Double Dispatch ---
	virtual void handleCollision(StaticObject& other) override;
	virtual void handleCollision(Robot& robot) override;
	virtual void goToFirstLoc()override { m_location = m_firstLoc; }
	//-------------------------------
	virtual void draw(sf::RenderWindow&) override;
protected:
	bool m_Collided = false;
	void trackRobotX();
	void trackRobotY();
	void goInRandom();
private:
	sf::Vector2f m_firstLoc;
	int m_track = 0;
	bool m_firstTime = true;// to get direction on the first time
	bool m_touchTheEnd = false;
	int m_rowImage = 150;
};