#include "SmartGuard.h"

SmartGuard::SmartGuard(sf::Vector2f loc, SfmlManager& sfMan, Information& Infor)
	:Guard(loc, sfMan, Infor)
{}
//------------------------------------------
void SmartGuard::updateDirection()
{
	m_status++;
	m_status %= Data::changedFunction *3;
	if (m_status < Data::changedFunction)
		Guard::goInRandom();
	else if (m_status <= Data::changedFunction *2)
		Guard::trackRobotX();
	else
		Guard::trackRobotY();

}
