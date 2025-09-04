#include "Ball.h"


//private functinos
void Ball::initBallVariables()
{
	this->movementSpeed = 4.0f;
}

void Ball::initBall()
{
	this->ball.setPosition(sf::Vector2f(375.f, 275.f));
	this->ball.setRadius(15.f);
	this->ball.setFillColor(sf::Color::White);
}

//public functions
Ball::Ball()
{
	this->initBallVariables();
	this->initBall();
}

Ball::~Ball()
{
	
}

const sf::CircleShape& Ball::getBall() const
{
	return this->ball;
}

void Ball::updateBallWindowsCollision()
{
	//top collision
	sf::Vector2f paddlePos = this->ball.getPosition();
	if (this->ball.getPosition().y <= 0.f)
	{
		this->ball.setPosition(sf::Vector2f(paddlePos.x, 0.f));
	}
	//bottom window collision
	else if (this->ball.getPosition().y >= 500.f)
	{
		this->ball.setPosition(sf::Vector2f(paddlePos.x, 500.f));
	}
}

//moves the ball
void Ball::updateBall()
{
	this->ball.move(sf::Vector2f(0.f, -this->movementSpeed));

	this->updateBallWindowsCollision();
}

void Ball::renderBall(sf::RenderTarget* target)
{
	target->draw(this->ball);
}
