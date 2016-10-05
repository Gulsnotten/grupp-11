/*
Team 11
Alexander Granell & Erik Säll
10/6/2016
*/

#pragma once
#include "SDL_System.h"
using namespace std;
#include <string>

class Font
{
private:
	TTF_Font* _ptr = nullptr;
	static const string FILE;
	static const int POINTS;
public:
	Font();
	~Font();

	TTF_Font* getPointer();
};

