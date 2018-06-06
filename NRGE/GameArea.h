#pragma once

#include <SDL.h>

class GameArea {
	//Methods
public:
	GameArea(SDL_Renderer *renderer, int x, int y, int w, int h);
	GameArea();
private:

	//Variables
public:
private:
	SDL_Rect gameAreaRect;
};