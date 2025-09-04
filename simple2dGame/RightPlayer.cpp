#include "RightPlayer.h"


//private functions
void RightPlayer::initRightVariables()
{
	this->movementSpeed = 2.f;
}

void RightPlayer::initRightPaddle()
{
	
	this->rPaddle.setSize(sf::Vector2f(50.f, 200.f));
	this->rPaddle.setScale(sf::Vector2f(0.5f, 0.5f));
	this->rPaddle.setFillColor(sf::Color::Blue);
	this->rPaddle.setOutlineColor(sf::Color::Green);
	this->rPaddle.setOutlineThickness(1.f);

}


//public functions
RightPlayer::RightPlayer(float x, float y)
{

	this->rPaddle.setPosition(sf::Vector2f(x, y));

	this->initRightVariables();
	this->initRightPaddle();

}

RightPlayer::~RightPlayer()
{
	
}

void RightPlayer::updateInput()
{
	//keyboard input
	//move up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
	{
		this->rPaddle.move(sf::Vector2f(0.f, -this->movementSpeed));
	}
	//move down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))
	{
		this->rPaddle.move(sf::Vector2f(0.f, this->movementSpeed));
	}
}

void RightPlayer::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	//top collision
	sf::Vector2f paddlePos = this->rPaddle.getPosition();
	if (this->rPaddle.getPosition().y <= 0.f) 
	{
		this->rPaddle.setPosition(sf::Vector2f(paddlePos.x, 0.f));
	}
	//bottom window collision
	else if (this->rPaddle.getPosition().y >= 500.f) 
	{
		this->rPaddle.setPosition(sf::Vector2f(paddlePos.x, 500.f));
	}

}

void RightPlayer::updateRPaddle(const sf::RenderTarget* target)
{
	//window bounds collision
	this->updateWindowBoundsCollision(target);

	//update input
	this->updateInput();
}

void RightPlayer::renderR(sf::RenderTarget* target)
{
	target->draw(this->rPaddle);

}
