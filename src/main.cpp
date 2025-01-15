#include <iostream>
#include "Windows.h"
#include "FirstWindow.h"
int main()
{
	FirstWindow window;

	window.customerChoice();

	if (window.need2exit())
	{
		std::cout << "Exiting For The Game \n";
	}
	else if (window.need2start())
	{
		std::cout << "Starting The Game\n";
	}
	

	return EXIT_SUCCESS;
}