#include "Gift3.h"


Gift3::Gift3(sf::Vector2f location, SfmlManager& sf)
	:Gift(location, sf::Sprite{ sf.getTexture(ObjName::E_Gift1) })
{
}
//---------------------------------------
void Gift3::handleCollision(Robot& robot)
{
	if (this->collidesWith(robot))
	{
		robot.handleCollision(*this);
		setDead();
	}
}
