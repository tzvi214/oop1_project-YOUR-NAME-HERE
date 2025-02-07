#pragma once
#include "GameObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Robot.h"
class Door :public GameObject
{
public:
	Door (sf::Vector2f, SfmlManager&);
	~Door() = default;
	virtual void  handleCollision(Robot&) override;
	virtual void draw(sf::RenderWindow&) override ;

private:

};