#include "SmartGuard.h"

SmartGuard::SmartGuard(sf::Vector2f loc, SfmlManager& sfMan, Information& Infor)
	:Guard(loc, sfMan, Infor)
{}
//------------------------------------------
void SmartGuard::updateDirection()
{
	m_status++;
	m_status %= 330;
	if (m_status < 110)
		Guard::goInRandom();
	else if (m_status <= 220)
		Guard::trackRobotX();
	else
		Guard::trackRobotY();

}
