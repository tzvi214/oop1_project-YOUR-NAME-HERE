#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Robot.h"
#include "Guard.h"


class Gift :public StaticObject
{
public:
	Gift(sf::Vector2f, sf::Sprite);
	~Gift() = default;
protected:

private:
};
