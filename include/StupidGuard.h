#pragma once 
#include <SFML/Graphics.hpp>
#include "ObjName.h"
#include "SfmlManager.h"
#include "MovingObject.h"
#include "Robot.h"
#include "Information.h"
#include "Guard.h"


class StupidGuard : public Guard
{
public:
	StupidGuard(sf::Vector2f, SfmlManager&, Information&);

	virtual void updateDirection();

private:
	
	
};