#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <deque>

class GameConsole {

	//Methods
public:
	GameConsole(SDL_Renderer *ren, int x, int y, int w, int h, int fontSize);
	~GameConsole();
	void print(const std::string &message);
	void print(const std::string &message, SDL_Color color);
	void displayMessages();

private:
	std::deque<std::string> wrapText(const std::string &message);
	
	//Variables
public:

private:
	SDL_Renderer *renderer = nullptr;
	unsigned int wrapLimit = 115;
	std::deque <SDL_Texture*> messages;
	static const int lineAmount = 12;
	SDL_Rect lines[lineAmount];
	SDL_Rect consoleRect;
	TTF_Font *font;
	SDL_Color defaultColor = { 255,255,255 };
};