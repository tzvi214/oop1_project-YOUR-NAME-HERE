#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Gift.h"
#include "Robot.h"

class LifeGift :public Gift
{
public:
	LifeGift(sf::Vector2f, SfmlManager&);
	~LifeGift() {};
	virtual void  handleCollision(Robot&) override;
	virtual void draw(sf::RenderWindow&) override ;

private:

};

