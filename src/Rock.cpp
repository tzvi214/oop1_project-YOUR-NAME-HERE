#include "Rock.h"

Rock::Rock(sf::Vector2f location, SfmlManager& sfmlManager)
	:StaticObject(location, sf::Sprite{ sfmlManager.getTexture(ObjName::E_Rock) }, ObjName::E_Rock)
{ }

