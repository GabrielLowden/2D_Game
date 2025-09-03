#include "RightPlayer.h"


//private functions
void RightPlayer::initRightVariables()
{
}

void RightPlayer::initRightPaddle()
{
	this->rPaddle.setPosition(sf::Vector2f(745.f, 250.f));
	this->rPaddle .setSize(sf::Vector2f(50.f, 200.f));
	this->rPaddle.setScale(sf::Vector2f(0.5f, 0.5f));
	this->rPaddle.setFillColor(sf::Color::Blue);
	this->rPaddle.setOutlineColor(sf::Color::Green);
	this->rPaddle.setOutlineThickness(1.f);

}


//public functions
RightPlayer::RightPlayer()
{
	this->initRightVariables();
	this->initRightPaddle();

}

RightPlayer::~RightPlayer()
{
	
}

void RightPlayer::updateRPaddle()
{
}

void RightPlayer::renderR(sf::RenderTarget* target)
{
	target->draw(this->rPaddle);

}
