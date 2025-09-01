#include "game.h"

//Private Functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.size;
	this->window = new sf::RenderWindow(sf::VideoMode({ 800, 600 }), "A Simple Game", sf::Style::Titlebar | sf::Style::Close);
}

//constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();

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

void Game::update()
{
	this->updateEvents();
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

	this->window->display();


}
