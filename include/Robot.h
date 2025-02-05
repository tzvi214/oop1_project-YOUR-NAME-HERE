#pragma once
#include "MovingObject.h"
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Information.h"
class Gift1;
class Gift2;
class Gift3;
class Gift4;



class Robot :public MovingObject
{
public:
	Robot(sf::Vector2f, SfmlManager&, Information&);
	sf::Vector2f getLocation() const { return m_location; }
	void loseLife();
	bool robotAreDead() const { return m_robotKilled; }
	void dountMove();
	void FinishedLevel() const;
	void Defeated() { m_need2restartPlace = true ; }
	//-----------------------------------------------------
	void goToFirstLoc() { m_location = m_firstLoc; }
	virtual void setDead(bool = true);
	virtual void updateDirection() override;
	virtual void draw(sf::RenderWindow&) override;
	virtual void move(float) override;

	// --- Double Dispatch ---
	virtual void handleCollision(StaticObject& other) override;
	virtual void handleCollision(Gift1&);
	virtual void handleCollision(Gift2&);
	virtual void handleCollision(Gift3&);
	virtual void handleCollision(Gift4&);

private:
	sf::Vector2f m_firstLoc;
	int m_life = 5;
	int m_seconds = 0;
	SfmlManager& m_sfmlManager;
	bool m_robotKilled = false;
	bool m_stopped = true;// when the program the object dident moved
	
	//------------------
	int m_rowImage = 0;
	//--- function ---
	void drawInformation(sf::RenderWindow&);

	//----------------------
	
};