#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Gift.h"
#include "Robot.h"

class Gift1 :public Gift
{
public:
	Gift1(sf::Vector2f, SfmlManager&);
	~Gift1() {};
	virtual void  handleCollision(Robot&) override;
private:

};

