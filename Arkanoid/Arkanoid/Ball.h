/*
Team 11
Alexander Granell & Erik S�ll
10/6/2016
*/

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

