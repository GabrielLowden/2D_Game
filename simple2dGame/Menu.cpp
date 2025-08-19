
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Menu.hpp"
#include <iostream>

menu::menu(unsigned int width, unsigned int height, const std::string& title) {
	window.create(sf::VideoMode({ width, height }), title);
	//initialize font & selected item private vars
}
//
//
void menu::run() {
	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			//this correlates to black terminal
			//needs fixed
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
					window.close();
				}
			}
		}
	}
}


bool menu::isOpen() const {
	return window.isOpen();
}