#include "Gift1.h"


Gift1::Gift1(sf::Vector2f location, SfmlManager& sf)
	:Gift(location, sf::Sprite{ sf.getTexture(ObjName::E_Gift1) })
{
}
//---------------------------------------
void Gift1::handleCollision(Robot& robot)
{
	if (this->collidesWith(robot))
	{
		robot.handleCollision(*this);
		setDead();
	}
}
