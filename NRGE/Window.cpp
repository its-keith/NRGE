#include "Window.h"


Window::Window(const std::string &title, int width, int height) : 
	_title(title), _width(width), _height(height) 
{
	_windowOpen = init();
}

Window::~Window() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	SDL_Quit();
}

bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		Logging::Log(SDL_GetError());
		return false;
	}

	if (TTF_Init() != 0) {
		Logging::Log("SDL_ttf failed to init");
		return false;
	}

	window = SDL_CreateWindow(_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height,
		SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		Logging::Log(SDL_GetError());
		return false;
	}

	renderer = SDL_CreateRenderer(window, 
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		Logging::Log(SDL_GetError());
		return false;
	}

	return true;
}

void Window::pollEvents() {
	SDL_Event evnt;

	if (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:
			_windowOpen = false;
			break;
		default:
			break;
		}
	}
}

void Window::render() const {
	SDL_RenderPresent(renderer);
}