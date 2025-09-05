#include "Ball.h"


//private functinos
void Ball::initBallVariables()
{
	this->movementSpeed = 2.0f;
	
	int dirX;
	if (rand() % 2 == 0) 
	{
		dirX = 1;
	}
	else 
	{
		dirX = -1;
	}
	
	int dirY;
	if (rand() % 2 == 0)
	{
		dirY = 1;
	}
	else 
	{
		dirY = -1;
	}
	
	//int dirX = -1;
	//int dirY = 0;
	this->velocity = {dirX*movementSpeed, dirY*movementSpeed};

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

void Ball::resetBall()
{
	this->ball.setPosition(sf::Vector2f(375.f, 275.f));
	initBallVariables();
}

void Ball::updateBallWindowsCollision()
{
	
	//top collision
	sf::Vector2f paddlePos = this->ball.getPosition();
	if (this->ball.getPosition().y <= 0.f)
	{
		this->setBallVelocity(this->getBallVelocity().x, -this->getBallVelocity().y);
	}
	//bottom window collision
	else if (this->ball.getPosition().y >= 575.f)
	{
		this->setBallVelocity(this->getBallVelocity().x, -this->getBallVelocity().y);
	}
	
}

sf::Vector2f Ball::getBallVelocity()
{
	return this->velocity;
}

void Ball::setBallVelocity(int x, int y)
{
	velocity = sf::Vector2f(x, y);
}

//moves the ball
void Ball::updateBall()
{
	this->ball.move(velocity);

	this->updateBallWindowsCollision();
}

void Ball::renderBall(sf::RenderTarget* target)
{
	target->draw(this->ball);
}
