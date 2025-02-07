#pragma once
#include "GameObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Robot.h"
#include "Guard.h"

class Wall :public GameObject
{
public:
	Wall(sf::Vector2f, SfmlManager&);
	~Wall() {};

	// --- Double Dispatch ---
	virtual void  handleCollision(Robot&) override;
	virtual void  handleCollision(Guard&) override;

	virtual void draw(sf::RenderWindow&) override ;
private:

};