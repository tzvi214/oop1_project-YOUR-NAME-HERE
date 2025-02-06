#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Robot.h"
class Door :public StaticObject
{
public:
	Door (sf::Vector2f, SfmlManager&);
	~Door() = default;
	virtual void  handleCollision(Robot&) override;
private:

};