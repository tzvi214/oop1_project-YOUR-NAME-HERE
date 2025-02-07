#include "FrozeGift.h"


FrozeGift::FrozeGift(sf::Vector2f location, SfmlManager& sf)
	:Gift(location, sf::Sprite{ sf.getTexture(ObjName::E_Gift1) })
{
}
//---------------------------------------
void FrozeGift::handleCollision(Robot& robot)
{
	if (this->collidesWith(robot))
	{
		robot.handleCollision(*this);
		setDead();
	}
}
