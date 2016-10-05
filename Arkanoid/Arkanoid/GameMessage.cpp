/*
Team 11
Alexander Granell & Erik Säll
10/6/2016
*/

#include "GameMessage.h"



GameMessage::GameMessage()
{
}


GameMessage::~GameMessage()
{
}

void GameMessage::start() const
{
	std::cout << "Waiting to start game... (click game window)" << "\n";
}

void GameMessage::nextRound(const GameSession& session) const
{
	int lives = session.getLives();
	std::string lifeMessage;
	if (lives == 1)
		lifeMessage = "1 life left!";
	else
		lifeMessage = std::to_string(lives) + " lives left!";
	std::cout << lifeMessage << " Waiting to start... (click game window)" << "\n";
}

void GameMessage::gameOver(const GameSession& session) const
{
	std::cout << "Game Over! Your score: " << session.getScore() << "\n";
}

void GameMessage::sessionStatus(const GameSession& session) const
{
	std::cout << "Lives: " << session.getLives() << "\nScore: " << session.getScore() << "\n";
}

void GameMessage::score(const GameSession & session) const
{
	std::cout << "Score: " << session.getScore() << "\n";
}

void GameMessage::bonus()
{
	std::cout << "Bonus " << Config::BONUS_POINTS << " points!\n";
}
