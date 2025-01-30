#pragma once
#include "MovingObject.h"
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Information.h"


class Robot :public MovingObject
{
public:
	Robot(sf::Vector2f, SfmlManager&, Information&);
	sf::Vector2f getLocation() const { return m_location; }
	void loseLife();
	bool robotAreDead() const { return m_robotKilled; }
	void dountMove();
	void FinishedLevel() const { std::cout << "You finished the level \n;"; }
	void touchBomb() { m_need2restartPlace = true ; }
	//-----------------------------------------------------
	void goToFirstLoc() { m_location = m_firstLoc; }
	virtual void setDead(bool = true);
	virtual void updateDirection() override;
	virtual void draw(sf::RenderWindow&) override;
	virtual void move(float) override;

	// --- Double Dispatch ---
	virtual void handleCollision(StaticObject& other) override;

private:
	sf::Vector2f m_firstLoc;
	int m_life = 5;
	float m_time = 0;// for new is default
	int m_seconds = 0;
	SfmlManager& m_sfmlManager;
	bool m_robotKilled = false;
	bool m_stopped = true;// when the program the object dident moved
	
	//------------------
	int m_currentFrame = 0;
	//--- function ---
	void drawInformation(sf::RenderWindow&);
	
	
	
	//----------------------
	sf::Texture& m_texture;
};