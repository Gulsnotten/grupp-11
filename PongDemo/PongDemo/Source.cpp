/*
Team 11
Alexander Granell & Erik Säll
10/6/2016
*/

#include <iostream>
#include "PongGame.h"

int main(int argc, char* argv[]) {
	try {
		PongGame game;
		game.run();
	}
	catch (const std::runtime_error& error) {
		std::cerr << error.what() << std::endl;
	}
	catch (...) {
		std::cerr << "You goofed up!\n";
	}

	return 0;
}