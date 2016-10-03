#include "Brick.h"
#include "Config.h"

void Brick::onCollision(const Entity & that)
{
	Entity::onCollision(that);
	_isDead = true;
}

Brick::Brick(float x, float y) : Entity(x, y, Config::BRICK_WIDTH, Config::BRICK_HEIGHT)
{
}


Brick::~Brick()
{
}
