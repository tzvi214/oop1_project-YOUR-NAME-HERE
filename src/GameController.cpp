#include "GameController.h"
//--------------------------------------------------------
void GameController::run()
{
	FirstWindow window(m_textureManager);
	handleFirstWindow(window);
	

}
//--------------------------------------------------------
void GameController::handleFirstWindow(FirstWindow& window) const
{
	window.customerChoice();

	if (window.need2exit())
	{
		std::cout << "Exiting For The Game \n";
	}
	else if (window.need2start())
	{
		std::cout << "Starting The Game\n";
	}
}
