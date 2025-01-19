#include "Robot.h"

Robot::Robot(sf::Vector2f location, SfmlManager& sfmlMan)
	: MovingObject(location, sfmlMan, ObjName::E_Robot), m_firstLoc{location.x * m_pixelSize, location.y*m_pixelSize}//StaticObject(location, sf::Sprite{ sfmlManager.getTexture(type) }
{}
//-----------------------------------------------------------
void Robot::ChooseDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setDirection((sf::Vector2f{ 1, 0 }));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setDirection((sf::Vector2f{ -1, 0 }));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setDirection((sf::Vector2f{ 0, -1 }));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setDirection((sf::Vector2f{ 0, 1 }));
	}
	else
		setDirection((sf::Vector2f{ 0, 0 })); // defulte nat moving


	//setDirection();
}
