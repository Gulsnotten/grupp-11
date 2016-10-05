/*
Team 11
Alexander Granell & Erik Säll
10/6/2016
*/

#include "Paddle.h"
#include "Config.h"


Paddle::Paddle(float x, float y) : Entity(x, y, Config::PADDLE_WIDTH, Config::BRICK_HEIGHT), _targetX(0)
{
	_color = Config::PADDLE_COLOR;
}

void Paddle::update() 
{
	if (_targetX == 0) {
		return;
	}
	float dx = _targetX - centerX();
	_x += (dx*Config::EASING);
	checkBoundaries();	
}

void Paddle::checkBoundaries()
{
	if (_x < 0.0f) {
		_x = 0.0f;
	}
	else if (_x > Config::WIN_WIDTH - _width) {
		_x = static_cast<float>(Config::WIN_WIDTH - _width);
	}
}

void Paddle::onMouseMove(int mousex, int mousey)
{
	_targetX = mousex;
}

Paddle::~Paddle()
{
}
