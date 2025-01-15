#pragma once
#include "Windows.h"
#include "Button.h"
#include "ObjName.h"
#include <vector>
#include"TextureManager.h"

class FirstWindow : public Windows
{
public:
	FirstWindow(unsigned int = 15, unsigned int = 15);// =15 for default size of window
	void draw();
	void customerChoice();
	
	bool need2exit() const { return m_need2exit; }
	bool need2start() const { return m_need2start; }
private:
	//--- data members----
	TextureManager m_textureManager{};
	ObjName m_objName{};
	std::vector<Button> m_buttons;
	bool m_need2exit = false;
	bool m_need2start = false;
	
	   //--- functions----
	void readFromFile()const;
	
};

