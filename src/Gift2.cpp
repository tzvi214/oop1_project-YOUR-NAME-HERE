#include "Gift2.h"
#include "Gift2.h"

LifeGift::LifeGift(sf::Vector2f location, SfmlManager& sf)
	:Gift(location, sf::Sprite{ sf.getTexture(ObjName::E_Gift2) })
{}
//---------------------------------------
void LifeGift::handleCollision(Robot& robot)
{
	if (this->collidesWith(robot))
	{
		robot.handleCollision(*this);
		setDead();

	}
}
