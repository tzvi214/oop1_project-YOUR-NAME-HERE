#pragma once
#include "MovingObject.h"
#include "GameObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Information.h"
#include "GameData.h"

class FrozeGift;
class LifeGift;
class TimeGift;
class KilledGift;



class Robot :public MovingObject
{
public:
	Robot(sf::Vector2f, SfmlManager&, Information&);
	~Robot() = default;
	sf::Vector2f getLocation() const { return m_location; }
	void dountMove();
	void FinishedLevel() const;
	void Defeated() { m_need2restartPlace = true ; }
	void goToFirstLoc() { m_location = m_firstLoc; }
	virtual void setDead(bool = true);
	virtual void updateDirection() override;
	virtual void draw(sf::RenderWindow&) override;
	virtual void move(float) override;

	// --- Double Dispatch ---
	virtual void handleCollision(GameObject& other) override;
	virtual void handleCollision(FrozeGift&);
	virtual void handleCollision(LifeGift&);
	virtual void handleCollision(TimeGift&);
	virtual void handleCollision(KilledGift&);

private:
	sf::Vector2f m_firstLoc;
	int m_life = 5;
	int m_seconds = 0;
	SfmlManager& m_sfmlManager;
	bool m_stopped = true;// when the program the object dident moved
	int m_robotSpeed = 2;
	int m_rowImage = 0;

	
	
};