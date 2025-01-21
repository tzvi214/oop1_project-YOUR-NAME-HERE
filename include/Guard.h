#pragma once
#include <SFML/Graphics.hpp>
#include "ObjName.h"
#include "SfmlManager.h"
#include "MovingObject.h"

class Guard : public MovingObject
{
public:
	Guard(sf::Vector2f, SfmlManager&);
	void updateDirection(sf::Vector2f);
	virtual void move(float) override;
	

private:

	int tempTest = 0;
};