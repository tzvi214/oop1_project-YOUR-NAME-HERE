#pragma once 
#include <SFML/Graphics.hpp>
#include "ObjName.h"
#include "SfmlManager.h"
#include "MovingObject.h"
#include "Robot.h"
#include "Information.h"
#include "Guard.h"
#include <cstdlib>  
#include <ctime> 

class SmartGuard : public Guard
{
public:
	SmartGuard(sf::Vector2f, SfmlManager&, Information&);
	~SmartGuard() = default;
	virtual void updateDirection() ;// override
private:
	int m_status =0;

};