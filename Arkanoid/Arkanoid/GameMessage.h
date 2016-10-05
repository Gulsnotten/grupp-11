/*
Team 11
Alexander Granell & Erik S�ll
10/6/2016
*/

#pragma once
#include "GameSession.h"
#include <iostream>
class GameMessage
{
public:
	GameMessage();
	~GameMessage();

	void start() const;
	void nextRound(const GameSession& session) const;
	void gameOver(const GameSession& session) const;
	void sessionStatus(const GameSession& session) const;
	void score(const GameSession& session) const;
	void bonus();
};

