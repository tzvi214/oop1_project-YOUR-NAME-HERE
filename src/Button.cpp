#include "Button.h"

Button::Button(sf::Vector2f vertexUp, sf::Sprite& image, ObjName type)
	: VertexUp{ vertexUp }, m_image{ image }, m_objType{ type }
{
	m_image.setPosition(VertexUp.x* m_pixelSize, VertexUp.y* m_pixelSize);
	m_image.setScale(0.2, 0.2);
}
//-------------------------------------------------------------------
bool Button::userPressOnTheButton(sf::Vector2f& location) const
{
	return m_image.getGlobalBounds().contains(location);
	
}
//-------------------------------------------------------------------