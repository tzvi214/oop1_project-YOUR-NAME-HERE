#include "Gift3.h"


TimeGift::TimeGift(sf::Vector2f location, SfmlManager& sf)
	:Gift(location, sf::Sprite{ sf.getTexture(ObjName::E_Gift3) })
{
}
//---------------------------------------
void TimeGift::handleCollision(Robot& robot)
{
	if (this->collidesWith(robot))
	{
		robot.handleCollision(*this);
		setDead();

	}
}
