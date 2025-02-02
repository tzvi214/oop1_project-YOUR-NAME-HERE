#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Gift.h"
#include "Robot.h"

class Gift2 :public Gift
{
public:
	Gift2(sf::Vector2f, SfmlManager&);
	virtual void  handleCollision(Robot&) override;
private:

};

