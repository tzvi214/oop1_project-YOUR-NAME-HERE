#include "StupidGuard.h"

StupidGuard::StupidGuard(sf::Vector2f loc, SfmlManager& sfMan, Information& Infor)
	:Guard(loc, sfMan, Infor)
{
}
//---------------------------------------
void StupidGuard::updateDirection()
{
	
	Guard::goInRandom();
}
