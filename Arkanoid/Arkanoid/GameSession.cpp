#include "GameSession.h"



GameSession::GameSession()
{
	reset();
}


GameSession::~GameSession()
{
}


void GameSession::looseLife() {
	_lives--;
}
void GameSession::reset() {
	_lives = Config::LIVES;
	_score = 0;
}
void GameSession::addScore(const int points)
{
	_score += points;
}
bool GameSession::isGameOver() const {
	return _lives == 0;
}
int GameSession::getLives() const {
	return _lives;
}
int GameSession::getScore() const {
	return _score;
}