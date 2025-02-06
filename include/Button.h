#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ObjName.h"
#include "SfmlManager.h"

class Button
{
public:
	Button(sf::RectangleShape, ObjName, SfmlManager&);
	std::string textButton(ObjName);
	ObjName getObjType() const { return m_objType; }
	bool userPressOnTheButton(sf::Vector2f&) const;
	void draw(sf::RenderWindow& window) const;

private:
	ObjName m_objType;
	const int m_pixelSize = 50;
	sf::RectangleShape m_button;
	SfmlManager& m_sfmlManger;
	sf::Text m_text;
};