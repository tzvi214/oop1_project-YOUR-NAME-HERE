#include "Wall.h"

Wall::Wall(sf::Vector2f location, SfmlManager& sfmlManager)
	:StaticObject(location, sf::Sprite{ sfmlManager.getTexture(ObjName::E_Wall) }, ObjName::E_Wall) {
}

void Wall::handleCollision(Robot& robot)
{
	if (this->collidesWith(robot))
	{
		std::cout << "Robot hit a Wall , need to move reverse \n";
		robot.dauntMove();
	}
}


void Wall::handleCollision(Guard& guard)
{
	if (this->collidesWith(guard)) {
		//std::cout << "Guard hit a Wall , need to move reverse \n";
		guard.dauntMove();
	}
}