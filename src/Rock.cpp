#include "Rock.h"

Rock::Rock(sf::Vector2f location, SfmlManager& sfmlManager)
	:StaticObject(location, sf::Sprite{ sfmlManager.getTexture(ObjName::Rock) }, ObjName::Rock)
{ }

