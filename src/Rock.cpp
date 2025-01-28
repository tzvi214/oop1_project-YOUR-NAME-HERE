#include "Rock.h"

Rock::Rock(sf::Vector2f location, SfmlManager& sfmlManager)
	:StaticObject(location, sf::Sprite{ sfmlManager.getTexture(ObjName::E_Rock) }, ObjName::E_Rock)
{ }
//-----------------------------------------------------------
void Rock::handleCollision(Robot& robot)
{
	robot.dauntMove();
}
//-----------------------------------------------------------
void Rock::handleCollision(Guard& guard)
{
	guard.dauntMove();
}

