#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Gift.h"
#include "Robot.h"

class Gift3 :public Gift
{
public:
	Gift3(sf::Vector2f, SfmlManager&);
	virtual void  handleCollision(Robot&) override;
private:

};

