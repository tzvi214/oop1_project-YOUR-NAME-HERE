#include "Gift4.h"


Gift4::Gift4(sf::Vector2f location, SfmlManager& sf)
	:Gift(location, sf::Sprite{ sf.getTexture(ObjName::E_Gift4) })
{
}
//---------------------------------------
void Gift4::handleCollision(Robot& robot)
{
	if (this->collidesWith(robot))
	{
		robot.handleCollision(*this);
		setDead();
	}
}
