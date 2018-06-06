#pragma once
#include <SDL.h>

class StatusArea {
	//Methods
public:
	StatusArea(SDL_Renderer *renderer, int x, int y, int w, int h);
	~StatusArea();

private:

	//Variables
public:
private:
	SDL_Rect statusRect;
};

