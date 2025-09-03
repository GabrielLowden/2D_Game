#include "LeftPlayer.h"


//private functions
void LeftPlayer::initLeftVariables()
{
}

void LeftPlayer::initLeftPaddle()
{
	//leftPlayer starts at bottom left corner
	this->lPaddle.setPosition(sf::Vector2f(30.f, 250.f));
	this->lPaddle.setSize(sf::Vector2f(50.f, 200.f));
	this->lPaddle.setScale(sf::Vector2f(0.5f, 0.5f));
	this->lPaddle.setFillColor(sf::Color::Red);
	this->lPaddle.setOutlineColor(sf::Color::Green);
	this->lPaddle.setOutlineThickness(1.f);
}

//public functions
LeftPlayer::LeftPlayer()
{
	this->initLeftVariables();
	this->initLeftPaddle();

}

LeftPlayer::~LeftPlayer()
{

}

void LeftPlayer::updateLPaddle()
{

}

void LeftPlayer::renderL(sf::RenderTarget* target)
{
	target->draw(this->lPaddle);

}
