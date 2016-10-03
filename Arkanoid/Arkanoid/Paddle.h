#pragma once
#include "Entity.h"

class Paddle : public Entity
{
	void checkBoundaries();
	int _targetX;
public:
	Paddle(float x, float y);
	void update();
	void onMouseMove(int mousex, int mousey);
	~Paddle();
};

