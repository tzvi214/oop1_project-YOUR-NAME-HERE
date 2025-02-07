#pragma once
#include "GameObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Robot.h"
#include "Guard.h"


class Gift :public GameObject
{
public:
	Gift(sf::Vector2f, sf::Sprite);
	~Gift() = default;
protected:

private:
};
