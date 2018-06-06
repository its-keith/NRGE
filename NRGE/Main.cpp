#include "Window.h"
#include "GameConsole.h"
#include "GameArea.h"
#include "StatusArea.h"

int main(int, char**) {
	Window window("NRGE", 1280, 720);
	GameConsole gameConsole(window.getRenderer(), 0, window.getHeight(), window.getWidth(), window.getHeight(), 20);
	GameArea gameArea(window.getRenderer(), 0, 0, window.getWidth(), window.getHeight());
	StatusArea statusArea(window.getRenderer(), window.getWidth(), 0, window.getWidth(), window.getHeight());

	gameConsole.print("========== Game Console ==========");

	while (window.isOpen()) {
		window.pollEvents();
		

		window.render();
	}

	window.~Window();
	return 0;
}