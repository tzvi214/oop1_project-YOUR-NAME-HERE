#include "Button.h"

Button::Button(sf::Vector2f vertexUp, sf::Vector2f vertexDown, sf::Sprite& image)
	: VertexUp{ vertexUp }, VertexDown{ vertexDown }, m_image{ image }
{
	m_image.setPosition(VertexUp.x*50, VertexUp.y*50);
	m_image.setScale(0.2, 0.2);
}
//-------------------------------------------------------------------
bool Button::userPressOnTheButton(sf::Vector2f& location) const
{
	return m_image.getGlobalBounds().contains(location);
	
}
//-------------------------------------------------------------------