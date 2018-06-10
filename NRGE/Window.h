#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "Logging.h"

class Window {

	//Methods
public:
	Window(const std::string &title, int width, int height, int fontSize);
	~Window();
	inline bool isOpen() const { return _windowOpen; }
	inline SDL_Renderer* getRenderer() const { return renderer; }
	inline int getHeight() const { return _height; }
	inline int getWidth() const { return _width; }
	void pollEvents();
	void render() const;
	void clear() const;
	static TTF_Font* getFont();
	static int getFontSize();

private:
	bool init();

	//Variables
private:
	std::string _title;
	int _width;
	int _height;
	bool _windowOpen = false;
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
};