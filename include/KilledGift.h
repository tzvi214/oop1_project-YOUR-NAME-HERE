#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Gift.h"
#include "Robot.h"

class KilledGift :public Gift
{
public:
	KilledGift(sf::Vector2f, SfmlManager&);
	~KilledGift() {};
	virtual void  handleCollision(Robot&) override;
	virtual void draw(sf::RenderWindow&) override ;

private:

};

