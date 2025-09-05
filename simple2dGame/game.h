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
	sf::Clock scoreClock;
	bool endGame;

	//Game logic
	int leftScore;
	int rightScore;
	bool lScore;
	bool rScore;
	bool showingScore;

	sf::Font font;
	sf::Text guiText;
	sf::Text rightScoreText;
	sf::Text leftScoreText;
	sf::Text winner;

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
	const bool& getEndGame() const;

	//Functions
	void updateScoreKeeping();
	void updateCollisions();
	void updateEvents();
	void updateGui();
	void update();

	void renderGui(sf::RenderTarget* target);
	void render();

};

