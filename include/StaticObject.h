#pragma once
#include <SFML/Graphics.hpp>
#include "SfmlManager.h"
#include "ObjName.h"

class StaticObject
{
public:
	 StaticObject(sf::Vector2f, sf::Sprite, ObjName);
	 virtual ~StaticObject() = default;
	 void draw(sf::RenderWindow&);
	 ObjName getType() const { return m_type; }
	 bool touch(sf::Vector2f& location) const { return m_image.getGlobalBounds().contains(location); }
protected:
	const int m_pixelSize;
	sf::Sprite m_image;
	sf::Vector2f getLoc() const { return m_location; }
	sf::Vector2f m_location;
	sf::Vector2f calculateLocation(sf::Vector2f);
private:
	//--- data_member ---
	
	ObjName m_type;
	
	 //---- function --------
	void setSpritLoc();
	

};
