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

	//movement speed
	float movementSpeed;

	void initBallVariables();
	void initBall();

public:
	Ball();
	virtual ~Ball();

	//returns ball
	const sf::CircleShape& getBall() const;

	//functinons
	void updateBallWindowsCollision();
	void updateBall();
	void renderBall(sf::RenderTarget* target);

};

