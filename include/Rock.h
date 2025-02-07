#pragma once
#include "GameObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Guard.h"
#include "Robot.h"

class Rock : public GameObject
{
public:
	Rock(sf::Vector2f, SfmlManager&);
	~Rock() {};

	// --- Double Dispatch ---
	virtual void  handleCollision(Robot&) override;
	virtual void  handleCollision(Guard&) override;
	virtual void  handleCollision(GameObject&) override;
private: 


};
