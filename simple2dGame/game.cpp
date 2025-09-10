#include <thread>
#include <chrono>

#include "game.h"

//Private Functions
void Game::initVariables()
{
	this->window = nullptr;
	this->leftScore = 0;
	this->rightScore = 0;
	this->endGame = false;
	this->lScore = false;
	this->rScore = false;
}

void Game::initWindow()
{
	this->videoMode.size;
	this->window = new sf::RenderWindow(sf::VideoMode({ 800, 600 }), "A Simple Game", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initFont()
{
	if (!this->font.openFromFile("fonts/Retro.otf")) 
	{
		//error
		std::cout << "error with font" << std::endl;
	}

}

void Game::initText()
{
	//score counts on screen
	this->rightScoreCount.setFont(this->font);
	this->rightScoreCount.setFillColor(sf::Color::Green);
	this->rightScoreCount.setCharacterSize(40);
	this->rightScoreCount.setPosition(sf::Vector2f(610.f, 0.f));

	this->leftScoreCount.setFont(this->font);
	this->leftScoreCount.setFillColor(sf::Color::Green);
	this->leftScoreCount.setCharacterSize(40);
	this->leftScoreCount.setPosition(sf::Vector2f(10.f, 0.f));

	//rightScore
	this->rightScoreText.setFillColor(sf::Color::Green);
	this->rightScoreText.setCharacterSize(50);
	this->rightScoreText.setString("Right Player Scored");

	//leftScore
	this->leftScoreText.setFillColor(sf::Color::Green);
	this->leftScoreText.setCharacterSize(50);
	this->leftScoreText.setString("Left Player Scored");

	//winner
	this->winner.setFillColor(sf::Color::Green);
	this->winner.setCharacterSize(50);

}

//constructor
Game::Game()
	: font{}
	, rightScoreCount(font)
	, leftScoreCount(font)
	, winner(font)
	, rightScoreText(font)
	, leftScoreText(font)
{
	this->initVariables();
	this->initWindow();
	this->initFont();
	this->initText();

}

//destructor
Game::~Game()
{
	delete this->window;
}


const bool Game::running() const
{
	return this->window->isOpen();
}

//ends game loop in main.cpp
const bool& Game::getEndGame() const
{
	return this->endGame;
}



void Game::updateCollisions()
{
	//check if ball hits left window border
	if (this->ball.getBall().getPosition().x < 0.f)
	{
		//reset the ball & give right player point
		rScore = true;
		rightScore++;
		this->ball.resetBall();

	}
	//check if ball hits right window border
	if (this->ball.getBall().getPosition().x > 775.f) 
	{
		//reset the ball & give left player point
		lScore = true;
		leftScore++;
		this->ball.resetBall();
	}

	//check right paddle ball collision
	if (this->rightPlayer.getRightPaddle().getGlobalBounds().findIntersection(this->ball.getBall().getGlobalBounds())) 
	{
		this->ball.setBallVelocity(-std::abs(this->ball.getBallVelocity().x), this->ball.getBallVelocity().y);
	}

	//check left paddle ball collision
	if (this->leftPlayer.getPaddle().getGlobalBounds().findIntersection(this->ball.getBall().getGlobalBounds())) 
	{
		this->ball.setBallVelocity(std::abs(this->ball.getBallVelocity().x), this->ball.getBallVelocity().y);
	}

}

void Game::updateEvents()
{
	//check all window events
	while (const std::optional event = this->window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			this->window->close();
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				this->window->close();
		}
	}
	
}

void Game::updateGui()
{
	std::stringstream leftperson;

	leftperson << "[+] Points: " << this->leftScore;

	this->leftScoreCount.setString(leftperson.str());

	std::stringstream rightperson;

	rightperson << "[+] Points: " << this->rightScore;

	this->rightScoreCount.setString(rightperson.str());

}

void Game::update()
{
	this->updateEvents();
	
	if (this->endGame == false)
	{
		this->rightPlayer.updateRPaddle(this->window);

		this->leftPlayer.updateLPaddle(this->window);

		this->ball.updateBall();

		this->updateCollisions();

		this->updateGui();
	}

	//update mouse position
	//std::cout << "Mouse Position: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << std::endl;
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->leftScoreCount);
	target->draw(this->rightScoreCount);

}

void Game::render()
{
	//renders the game objects.
	// - clear old frame
	// - render all objects
	// - display frame in window
	//


	this->window->clear(sf::Color::Black);

	//Render gui
	this->renderGui(this->window);

	//Draw game objects
	this->leftPlayer.renderL(this->window);
	this->rightPlayer.renderR(this->window);
	this->ball.renderBall(this->window);

	

	//
	if (this->endGame == true) 
	{
		this->window->draw(this->winner);
	}

	//render score text


	this->window->display();
	
	
}
