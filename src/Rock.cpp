#include "Rock.h"

Rock::Rock(sf::Vector2f location, SfmlManager& sfmlManager)
	:GameObject(location, sf::Sprite{ sfmlManager.getTexture(ObjName::E_Rock) }, ObjName::E_Rock)
{ }
//-----------------------------------------------------------
void Rock::handleCollision(Robot& robot)
{
	if (this->collidesWith(robot))
	{
		robot.dountMove();
	}
}
//-----------------------------------------------------------
void Rock::handleCollision(Guard& guard)
{
	if (this->collidesWith(guard))
	{
		guard.dountMove();
	}
}

void Rock::handleCollision(GameObject& other)
{
	other.handleCollision(*this); // swap.
}
//------------------------------------------
void Rock::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);

}

