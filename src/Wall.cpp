#include "Wall.h"

Wall::Wall(sf::Vector2f location, SfmlManager& sfmlManager)
	:StaticObject(location, sf::Sprite{ sfmlManager.getTexture(ObjName::E_Wall)}, ObjName::E_Wall)
{}
