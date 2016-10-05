/*
Team 11
Alexander Granell & Erik Säll
10/6/2016
*/

#include "Entity.h"
#include "Config.h"
#include <cmath>
#include "Random.h"

Entity::Entity(float x, float y, int width, int height) : _x{ x }, _y{ y }, _vx{ 0.0f }, _vy{ 0.0f }, _isDead(false),
                                                          _width{ width }, _height{ height }, _color(Config::FG_COLOR)
{
}

void Entity::update()
{
	_x += _vx;
	_y += _vy;
}

void Entity::onCollision(const Entity & that)
{
	
}

void Entity::getBounds(SDL_Rect & r) const
{
	r.x = static_cast<int>(_x);
	r.y = static_cast<int>(_y);
	r.w = static_cast<int>(_width);
	r.h = static_cast<int>(_height);
}

int Entity::getScore()
{
	return 0;
}

float Entity::centerX() const
{
	return _x+(_width/2);
}

float Entity::centerY() const
{
	return _y + (_height/2);
}

float Entity::left() const {
	return _x;
}
float Entity::right() const {
	return _x + _width;
}
float Entity::top() const {
	return _y;
}
float Entity::bottom() const {
	return _y + _height;
}
int Entity::halfWidth() const {
	return static_cast<int>(_width / 2);
}
int Entity::halfHeight() const {
	return static_cast<int>(_height / 2);
}

Entity::~Entity()
{
}

//AABB intersection test
bool isColliding(const Entity& lhs, const Entity& rhs) {
	SDL_assert(&lhs != &rhs);
	return !(lhs._x + lhs._width <= rhs._x ||
		rhs._x + rhs._width <= lhs._x ||
		lhs._y + lhs._height <= rhs._y ||
		rhs._y + rhs._height <= lhs._y);
}

//SAT intersection test. http://www.metanetsoftware.com/technique/tutorialA.html
//Many thanks to Jerry Jonsson and Tommi Lipponen at Uppsala University, GAME,
//for the original implementation of this function: http://pastebin.com/cbJWTfb9

bool getOverlap(const Entity& lhs, const Entity& rhs, int& overlapX, int& overlapY) {
	SDL_assert(&lhs != &rhs);
	overlapX = 0;
	overlapY = 0;
	int centerDeltaX = static_cast<int>(lhs.centerX() - rhs.centerX());
	int halfWidths = (lhs._width + rhs._width) / 2;

	if (std::abs(centerDeltaX) > halfWidths) return false; //no overlap on x == no collision

	int centerDeltaY = static_cast<int>(lhs.centerY() - rhs.centerY());
	int halfHeights = (lhs._height + rhs._height) / 2;

	if (std::abs(centerDeltaY) > halfHeights) return false; //no overlap on y == no collision

	int dx = halfWidths - std::abs(centerDeltaX); //overlap on x
	int dy = halfHeights - std::abs(centerDeltaY); //overlap on y      
	if (dy < dx) {
		overlapY = (centerDeltaY < 0) ? -dy : dy;
	}
	else if (dy > dx) {
		overlapX = (centerDeltaX < 0) ? -dx : dx;
	}
	else {
		overlapX = (centerDeltaX < 0) ? -dx : dx;
		overlapY = (centerDeltaY < 0) ? -dy : dy;
	}
	return true;
}
