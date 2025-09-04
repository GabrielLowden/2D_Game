#include "game.h"

//Private Functions
void Game::initVariables()
{
	this->window = nullptr;
	this->leftScore = 0;
	this->rightScore = 0;

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
	
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::Green);
	this->guiText.setCharacterSize(40);
	this->guiText.setPosition(sf::Vector2f(500.f, 0.f));

}

//constructor
Game::Game()
	: font{}
	, guiText(font)
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


void Game::updateCollisions()
{
	//check if ball hits left window border
	
	//check if ball hits right window border
	
	//check if ball hits top window border

	//check if ball hits bottom window border

	//check right paddle ball collision
	

	//check left paddle ball collision
	if (this->leftPlayer.getPaddle().getGlobalBounds().findIntersection(this->ball.getBall().getGlobalBounds())) 
	{
		this->ball.~Ball();
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
	std::stringstream ss;

	ss << "[+] Points: " << this->leftScore;

	this->guiText.setString(ss.str());
}

void Game::update()
{
	this->updateEvents();
	
	this->rightPlayer.updateRPaddle(this->window);

	this->leftPlayer.updateLPaddle(this->window);

	this->ball.updateBall();

	this->updateCollisions();

	this->updateGui();

	//update mouse position
	//std::cout << "Mouse Position: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << std::endl;
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText);

}

void Game::render()
{
	//renders the game objects.
	// - clear old frame
	// - render all objects
	// - display frame in window
	//


	this->window->clear(sf::Color::Black);

	//Draw game objects
	this->leftPlayer.renderL(this->window);
	this->rightPlayer.renderR(this->window);
	this->ball.renderBall(this->window);

	//Render gui
	this->renderGui(this->window);

	this->window->display();


}
