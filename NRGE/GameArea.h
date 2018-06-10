#pragma once

#include <SDL.h>
#include <vector>
#include "Window.h"

class GameArea {
	//Methods
public:
	GameArea(SDL_Renderer *ren, int x, int y, int w, int h);
	~GameArea();
private:

	//Variables
public:
private:
	SDL_Renderer * renderer;
	int width, height;
	int cellSize; //Size of a grid cell
	int gridH, gridW; //Number of cells tall/wide
	std::vector<std::vector<SDL_Rect>> gameGrid;
};