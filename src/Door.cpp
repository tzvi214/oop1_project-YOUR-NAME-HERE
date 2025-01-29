#include "Door.h"

Door::Door(sf::Vector2f location, SfmlManager& sfmlManager)
	:StaticObject(location, sf::Sprite{ sfmlManager.getTexture(ObjName::E_Door) }, ObjName::E_Door)
{
}
//------------------------------------------
void Door::handleCollision(Robot& robot)
{
	if (this->collidesWith(robot))
	{
		robot.FinishedLevel();
	}
}

