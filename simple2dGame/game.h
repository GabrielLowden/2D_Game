#pragma once

//libraries
#include <iostream>
#include <string>
#include <sstream>>

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
	int leftScore;
	int rightScore;

	sf::Font font;
	sf::Text guiText;

	//create instances of players & ball
	LeftPlayer leftPlayer;
	RightPlayer rightPlayer;
	Ball ball;

	//Private Functinos
	void initVariables();
	void initWindow();
	void initFont();
	void initText();

	
public:
	//constructors & destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions
	void updateCollisions();
	void updateEvents();
	void updateGui();
	void update();

	void renderGui(sf::RenderTarget* target);
	void render();

};

