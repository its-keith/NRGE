#include "GameArea.h"

GameArea::GameArea(SDL_Renderer *renderer, int x, int y, int w, int h) {
	gameAreaRect.x = x;
	gameAreaRect.y = y;
	gameAreaRect.w = w - (w/4);
	gameAreaRect.h = h - (h/3);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &gameAreaRect);
}

GameArea::GameArea() {

}