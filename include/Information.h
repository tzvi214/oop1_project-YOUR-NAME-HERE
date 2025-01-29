#pragma once
#include "Robot.h"

class Information
{
public:
	bool finishedTheLevel();// for the controller

	void TouchTheDoor(Robot&); // for the door

private:

	bool m_FinishetCorrentLevel = false;
	bool m_robotIsAlive = true;
	int m_gameWidth;
	int m_gameHeight;
};