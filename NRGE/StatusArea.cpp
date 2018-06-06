#include "StatusArea.h"

StatusArea::StatusArea(SDL_Renderer *renderer, int x, int y, int w, int h) {
	statusRect.x = x - (x/4);
	statusRect.y = y;
	statusRect.w = w;
	statusRect.h = h - (h/3);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &statusRect);
}

StatusArea::~StatusArea() {

}
