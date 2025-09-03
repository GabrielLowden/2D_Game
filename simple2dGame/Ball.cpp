#include "Ball.h"


//private functinos
void Ball::initBallVariables()
{
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

void Ball::updateBall()
{
}

void Ball::renderBall(sf::RenderTarget* target)
{
	target->draw(this->ball);
}
