#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//class that acts as game engine.


class Game
{
private:
	//Variabels
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	//Private Functinos
	void initVariables();
	void initWindow();
public:
	//constructors & destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions
	void updateEvents();
	void update();
	void render();
};

