#pragma once
#include <SFML/Graphics.hpp>
#include "SfmlManager.h"
#include "ObjName.h"

class Robot;
class Guard;
class Bomb;
class Rock;
class Gift;
class FrozeGift;
class LifeGift;
class TimeGift;
class KilledGift;
class MovingObject;
class SmartGuard;



class GameObject
{
public:
	GameObject(sf::Vector2f, sf::Sprite, ObjName);
	virtual ~GameObject() = default;

	ObjName getType() const { return m_type; }
	bool touch(sf::Vector2f location) const;
	sf::Vector2f getLocation() const;
	bool collidesWith(GameObject&);
	bool checkCollision(GameObject&) const;
	virtual void setDead(bool = true);
	bool IsDead() const { return m_Dead; }
	//--- VIRTUAL ---
	virtual void draw(sf::RenderWindow&);

	// --- Double Dispatch ---
	virtual void handleCollision(GameObject&) {};
	virtual void handleCollision(Robot&) {};
	virtual void handleCollision(Guard&) {};
	virtual void handleCollision(Rock&) {};
	virtual void handleCollision(FrozeGift&) {};
	virtual void handleCollision(LifeGift&) {};
	virtual void handleCollision(TimeGift&) {};
	virtual void handleCollision(KilledGift&) {};
	//--------------------------------------
	virtual	bool ApproxCollided(sf::Vector2f) const;

protected:
	void setLocation() { m_image.setPosition(m_location); }
	const int m_pixelSize;
	sf::Sprite m_image;
	sf::Vector2f getLoc() const { return m_location; }
	sf::Vector2f m_location;
	bool m_Dead = false;
	sf::Vector2f calculateLocation(sf::Vector2f);
private:
	//--- data_member ---

	ObjName m_type;
	//---- function --------
	void setSpritLoc();
};