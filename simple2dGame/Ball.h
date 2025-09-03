#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Ball
{
private:
	//pong ball
	sf::CircleShape ball;

	void initBallVariables();
	void initBall();

public:
	Ball();
	virtual ~Ball();

	void updateBall();
	void renderBall(sf::RenderTarget* target);

};

