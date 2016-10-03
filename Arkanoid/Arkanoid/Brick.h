#pragma once
#include "Entity.h"

class Brick : public Entity
{
public:
	void onCollision(const Entity& that);
	Brick(float x, float y);
	~Brick();
};

