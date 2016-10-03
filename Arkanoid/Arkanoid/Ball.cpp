#include "Ball.h"
#include "Config.h"
#include <iostream>
#include "Random.h"

Ball::Ball(float x, float y) : Entity(x, y, Config::BALL_WIDTH, Config::BALL_WIDTH), _hasLaunched(false)
{
}

void Ball::checkBoundaries()
{
	if (_y < 0.0f) {
		_y = 0.0f;
		_vy *= -1;
	}
	else if (_y > Config::WIN_HEIGHT - _height) {
		_y = static_cast<float>(Config::WIN_HEIGHT - _height);
		_vy *= -1;
	}
	if (_x < 0.0f) {
		_x = 0.0f;
		_vx *= -1;
	}
	else if (_x > Config::WIN_WIDTH - _width) {
		_x = static_cast<float>(Config::WIN_WIDTH - _width);
		_vx *= -1;
	}
}

void Ball::onCollision(const Entity & that)
{
	int overlapX = 0;
	int overlapY = 0;
	if (!getOverlap(*this, that, overlapX, overlapY)) {
		return;
	}
	if (overlapX) {
		this->_x += overlapX;  //bara för att visa att det betyder samma sak
		_vx *= -1;
	}
	if (overlapY) {
		_y += overlapY;
		_vy *= -1;
	}
}

void Ball::launch()
{
	if (_hasLaunched) { return; }
	_hasLaunched = true;
	_vx = Random::getFloat(-6.0f, 6.0f);
	_vy = -8 + Random::getFloat(-8.0f, -2.0f);
}

void Ball::update()
{
	Entity::update();
	checkBoundaries();
}


Ball::~Ball()
{
}
