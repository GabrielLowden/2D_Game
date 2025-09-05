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
	sf::Vector2f velocity;

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
	void resetBall();
	void updateBallWindowsCollision();
	sf::Vector2f getBallVelocity();
	void setBallVelocity(int x, int y);
	void updateBall();
	void renderBall(sf::RenderTarget* target);

};

