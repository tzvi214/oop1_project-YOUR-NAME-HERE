#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
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
private:

};

