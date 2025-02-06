#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ObjName.h"
class Button
{
public:
	Button(sf::Vector2f , sf::Sprite&, ObjName);
	~Button() = default;
	bool userPressOnTheButton(sf::Vector2f&) const;
	void draw(sf::RenderWindow& window) const { window.draw(m_image); } //maybe it should nat be const
	ObjName getObjType() const { return m_objType; }
private:
	
	sf::Vector2f VertexUp;
	sf::Sprite m_image;
	ObjName m_objType;
	const int m_pixelSize = 50;
};

