#include "LeftPlayer.h"


//private functions
void LeftPlayer::initLeftVariables()
{
	this->movementSpeed = 2.f;
}

void LeftPlayer::initLeftPaddle()
{
	
	this->lPaddle.setSize(sf::Vector2f(50.f, 200.f));
	this->lPaddle.setScale(sf::Vector2f(0.5f, 0.5f));
	this->lPaddle.setFillColor(sf::Color::Red);
	this->lPaddle.setOutlineColor(sf::Color::Green);
	this->lPaddle.setOutlineThickness(1.f);
}

//public functions
LeftPlayer::LeftPlayer(float x, float y)
{
	//leftPlayer starts at bottom left corner
	this->lPaddle.setPosition(sf::Vector2f(x, y));

	this->initLeftVariables();
	this->initLeftPaddle();

}

LeftPlayer::~LeftPlayer()
{

}

const sf::RectangleShape LeftPlayer::getPaddle() const
{
	return this->lPaddle;
}

void LeftPlayer::updateLInput()
{
	//keyboard input
	//move up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
	{
		this->lPaddle.move(sf::Vector2f(0.f, -this->movementSpeed));
	}
	//move down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S))
	{
		this->lPaddle.move(sf::Vector2f(0.f, this->movementSpeed));
	}
}

void LeftPlayer::updateLWindowBoundsCollision(const sf::RenderTarget* target)
{
	//top collision
	sf::Vector2f paddlePos = this->lPaddle.getPosition();
	if (this->lPaddle.getPosition().y <= 0.f)
	{
		this->lPaddle.setPosition(sf::Vector2f(paddlePos.x, 0.f));
	}
	//bottom window collision
	else if (this->lPaddle.getPosition().y >= 500.f)
	{
		this->lPaddle.setPosition(sf::Vector2f(paddlePos.x, 500.f));
	}

}

void LeftPlayer::updateLPaddle(const sf::RenderTarget* target)
{
	//window bounds collision
	this->updateLWindowBoundsCollision(target);

	//update input
	this->updateLInput();
}

void LeftPlayer::renderL(sf::RenderTarget* target)
{
	target->draw(this->lPaddle);

}
