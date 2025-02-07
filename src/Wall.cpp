#include "Wall.h"

Wall::Wall(sf::Vector2f location, SfmlManager& sfmlManager)
	:GameObject(location, sf::Sprite{ sfmlManager.getTexture(ObjName::E_Wall) }, ObjName::E_Wall) {
}

void Wall::handleCollision(Robot& robot)
{
	if (this->collidesWith(robot))
	{
		robot.dountMove();
	}
}


void Wall::handleCollision(Guard& guard)
{
	if (this->collidesWith(guard)) {
		guard.dountMove();
	}
}
//------------------------------------------
void Wall::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);

}
