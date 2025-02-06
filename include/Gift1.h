#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Gift.h"
#include "Robot.h"

class FrozeGift :public Gift
{
public:
	FrozeGift(sf::Vector2f, SfmlManager&);
	~FrozeGift() {};
	virtual void  handleCollision(Robot&) override;
private:

};

