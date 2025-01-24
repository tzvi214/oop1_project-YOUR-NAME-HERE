#include "Wall.h"

Wall::Wall(sf::Vector2f location, SfmlManager& sfmlManager)
	:StaticObject(location, sf::Sprite{ sfmlManager.getTexture(ObjName::E_Wall) }, ObjName::E_Wall) {
}

void Wall::handleCollision(Robot& robot)
{
	std::cout << "Robot hit a Wall , need to move reverse \n";
	robot.dountMove();
}


void Wall::handleCollision(Guard&)
{
	std::cout << "Guard hit a Wall , need to move reverse \n";
}