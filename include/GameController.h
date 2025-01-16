#pragma once
#include "FirstWindow.h"
#include <SfmlManager.h>
#include "StaticObject.h"
class GameController
{
public:

 void run();
private:
	SfmlManager m_SfmlManager{};
	void handleFirstWindow(FirstWindow&) const;

};