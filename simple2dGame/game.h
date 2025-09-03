#pragma once

//libraries
#include <iostream>

//SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//classes
#include "LeftPlayer.h"
#include "RightPlayer.h"
#include "Ball.h"


//class that acts as game engine.

class Game
{
private:
	//Variabels
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	//Game logic
	int enemyScore;
	int protagonistScore;

	//create instances of players & ball
	LeftPlayer leftPlayer;
	RightPlayer rightPlayer;
	Ball ball;

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

