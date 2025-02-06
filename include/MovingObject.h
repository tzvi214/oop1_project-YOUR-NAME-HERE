#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Information.h"

class MovingObject :public StaticObject
{
public:
	MovingObject(sf::Vector2f, SfmlManager&, ObjName, Information& infro);
	~MovingObject() {};
	void setDirection(sf::Vector2f);
	virtual void move(float) {};
	virtual void updateDirection() {};
	virtual bool need2restartPlace() const { return m_need2restartPlace; }
	virtual void goToFirstLoc() {};
protected:
	sf::Vector2f m_direction{ 0, 0 };// defult nat moving
	//sf::Vector2f m_dirBeforeStopped{ 0,0 };
	bool m_need2restartPlace = false;
	Information& m_information;
	float m_time = 0;// for new is default
	int m_currentFrame = 0;
	sf::Texture& m_texture;
	//-------------------------------------------
	virtual void print(sf::RenderWindow& window, int);

};