#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Gift.h"
#include "Robot.h"

class TimeGift :public Gift
{
public:
	TimeGift(sf::Vector2f, SfmlManager&);
	~TimeGift() {};
	virtual void  handleCollision(Robot&) override;
private:

};

