#include "Gift2.h"
#include "Gift2.h"

Gift2::Gift2(sf::Vector2f location, SfmlManager& sf)
	:Gift(location, sf::Sprite{ sf.getTexture(ObjName::E_Gift2) })
{}
//---------------------------------------
void Gift2::handleCollision(Robot& robot)
{
	if (this->collidesWith(robot))
	{
		robot.handleCollision(*this);
		setDead();

	}
}
