#include "Brick.h"
#include "Config.h"

void Brick::setColor()
{
	_color = Config::BRICK_COLORS[_hitPoints - 1];
}

void Brick::onCollision(const Entity & that)
{
	Entity::onCollision(that);
	_hitPoints--;
	if (_hitPoints == 0)
		_isDead = true;
	else
		setColor();
}

int Brick::getHitPoints() const
{
	return _hitPoints;
}

int Brick::getScore() {
	return _scoreValue;
}

Brick::Brick(float x, float y) : Entity(x, y, Config::BRICK_WIDTH, Config::BRICK_HEIGHT), _hitPoints{ 1 }, _scoreValue{Config::BRICK_SCORE[0]}
{
	setColor();
}
Brick::Brick(float x, float y, int hitPoints) : Entity(x, y, Config::BRICK_WIDTH, Config::BRICK_HEIGHT), _hitPoints{hitPoints}, _scoreValue{ Config::BRICK_SCORE[hitPoints - 1] }
{
	setColor();
}


Brick::~Brick()
{
}
