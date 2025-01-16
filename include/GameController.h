#pragma once
#include "FirstWindow.h"
#include <SfmlManager.h>

class GameController
{
public:

 void run();
private:
	SfmlManager m_textureManager{};
	void handleFirstWindow(FirstWindow&) const;

};