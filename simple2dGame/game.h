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

	//Game Objects
	
	//left player
	sf::RectangleShape enemy;
	//right player
	sf::RectangleShape protagonist;
	//pong ball
	sf::CircleShape ball;

	//Private Functinos
	void initVariables();
	void initWindow();
	void initEnemies();
	void initProtagonist();
	void initBall();
	
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
	void updateEnemies();
	void renderEnemies();
	void updateProtagonist();
	void renderProtagonist();
	void updateBall();
	void renderBall();

};

