#pragma once
#include "Windows.h"
#include "Button.h"
#include "ObjName.h"
#include <vector>
#include"TextureManager.h"

class firstWindow : public Windows
{
public:
	firstWindow(unsigned int = 15, unsigned int = 15);// =15 for default size of window
	void draw();
	void tempFunction();
	
private:
	//--- data members----
	const int defaultSize = 15;//default size of window
	TextureManager m_textureManager{};
	ObjName m_objName{};
	std::vector<Button> m_buttons;
	//sf::Texture m_InstructionsTex;
	
	   //--- functions----
	sf::RenderWindow& getWindow() { return m_window; }
	
};

