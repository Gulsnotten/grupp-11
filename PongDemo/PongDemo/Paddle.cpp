/*
Team 11
Alexander Granell & Erik Säll
10/6/2016
*/

#include "Paddle.h"
#include "Playfield.h"


Paddle::Paddle()
{
	side = Side::left;
	rect = { 0, 0,
		WIDTH, HEIGHT };
}
Paddle::Paddle(Side side_) {
	rect = { 0, (Playfield::HEIGHT / 2) - (HEIGHT / 2),
		WIDTH, HEIGHT};
	
	side = side_;

	if (side == Side::left) {
		rect.x = Playfield::MARGIN;
	}
	else {
		rect.x = Playfield::WIDTH - WIDTH - Playfield::MARGIN;
	}

	pressingUp = false;
	pressingDown = false;
}

Paddle::~Paddle()
{
}


GameObject::Side Paddle::GetSide() {
	return side;
}

void Paddle::update() {
	if (pressingUp) {
		rect.y -= Paddle::SPEED;
	}
	if (pressingDown) {
		rect.y += Paddle::SPEED;
	}
}
void Paddle::checkBounds() {
	if (rect.y < Playfield::MARGIN) {
		rect.y = Playfield::MARGIN;
	}

	if (rect.y + rect.h > Playfield::HEIGHT - Playfield::MARGIN) {
		rect.y = Playfield::HEIGHT - Playfield::MARGIN - rect.h;
	}
}
void Paddle::pressUp(bool b) {
	pressingUp = b;
}
void Paddle::pressDown(bool b) {
	pressingDown = b;
}