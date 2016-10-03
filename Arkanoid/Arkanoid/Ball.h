#pragma once
#include "Entity.h"

class Ball : public Entity
{
	void checkBoundaries();
public:
	bool _hasLaunched;
	void onCollision(const Entity& that);
	Ball(float x, float y);
	void update();
	void launch();
	~Ball();
};

