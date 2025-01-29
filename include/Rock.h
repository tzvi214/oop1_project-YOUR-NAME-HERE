#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Guard.h"
#include "Robot.h"

class Rock : public StaticObject
{
public:
	Rock(sf::Vector2f, SfmlManager&);

	// --- Double Dispatch ---
	virtual void  handleCollision(Robot&) override;
	virtual void  handleCollision(Guard&) override;
	virtual void  handleCollision(StaticObject&) override;
private: 


};
