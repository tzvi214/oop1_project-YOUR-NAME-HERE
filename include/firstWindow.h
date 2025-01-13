#pragma once
#include "Windows.h"

class firstWindow : public Windows
{
public:
	firstWindow(unsigned int = 15, unsigned int = 15);
	bool need2playGame() const { return need2play; }
	bool need2exitGame() const { return need2exit; }
	bool need2readFromFile() const { return need2read; }
	void readFromFile();
	void customerChoice();

private:
	const int defaultSize = 15;//defualt size of window
	bool need2play = false;
	bool need2exit = false;
	bool need2read = false;
	
};

