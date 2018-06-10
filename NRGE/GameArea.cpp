#include "GameArea.h"

GameArea::GameArea(SDL_Renderer *ren, int x, int y, int w, int h) {
	renderer = ren;

	width = w - (w/4);
	height = h - (h/3);
	cellSize = Window::getFontSize();
	gridH = height / cellSize;
	gridW = width / cellSize;
	SDL_Rect cell;
	cell.h = cellSize;
	cell.w = cellSize;
	gameGrid.resize(gridW, std::vector<SDL_Rect>(gridH, cell));

	for (int i = 0; i < gridH; i++) {
		for (int j = 0; j < gridW; j++) {
			gameGrid[j][i].x = x;
			gameGrid[j][i].y = y;
			x += cellSize;
		}
		x = 0;
		y += cellSize;
	}

	/*SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &gameAreaRect);*/
}

GameArea::~GameArea() {

}