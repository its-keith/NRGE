#include "GameConsole.h"
#include "Window.h"

GameConsole::GameConsole(SDL_Renderer *ren, int x, int y, int w, int h, int fontSize) {
	
	renderer = ren;

	lines[0].x = x;
	lines[0].y = y - (y / 3);
	lines[0].w = w;
	lines[0].h = fontSize;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &lines[0]);

	for (int i = 1; i < lineAmount; i++) {
		lines[i].x = x;
		lines[i].y = lines[i - 1].y + lines[i - 1].h;
		lines[i].w = w;
		lines[i].h = fontSize;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, &lines[i]);
	}

	font = Window::getFont();
}

GameConsole::~GameConsole() {

}

void GameConsole::print(const std::string &message) {
	GameConsole::print(message, defaultColor);
}

void GameConsole::print(const std::string &message, SDL_Color color) {
	
	SDL_Surface *surface;
	SDL_Texture *texture;

	//At font size 20 and 1280x720 resolution (the default), can fit 126 characters (with no spaces) on one line.
	std::deque<std::string> wrappedText = wrapText(message);

	for (int i = 0; i < wrappedText.size(); i++) {
		surface = TTF_RenderText_Solid(font, wrappedText.at(i).c_str(), color);
		texture = SDL_CreateTextureFromSurface(renderer, surface);

		messages.insert(messages.begin(), texture);
		
		//SDL_DestroyTexture(texture);
		SDL_FreeSurface(surface);
	}

	//Remove messages that have "scrolled" past the console window
	while (messages.size() > lineAmount) {
		SDL_DestroyTexture(messages.back());
		messages.pop_back();
	}
}

void GameConsole::displayMessages() {
	for (int i = 0; i < lineAmount && i < messages.size(); i++) {
		SDL_QueryTexture(messages.at(i), NULL, NULL, &lines[i].w, &lines[i].h);
		SDL_RenderCopy(renderer, messages.at(i), NULL, &lines[i]);
	}
}

//At font size 20 and 1280x720 resolution (the default), can fit 126 characters (with no spaces) on one line.
std::deque<std::string> GameConsole::wrapText(const std::string &message) {
	std::deque<std::string> lines;
	std::string wrappedString = message;
	while (wrappedString.length() > wrapLimit) {
		lines.insert(lines.begin(), wrappedString.substr(0, wrapLimit));
		wrappedString.erase(0, wrapLimit);
	}
	lines.insert(lines.begin(), wrappedString);
	return lines;
}