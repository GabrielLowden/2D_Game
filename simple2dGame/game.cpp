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

	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	//Enemy starts at bottom left corner
	this->enemy.setPosition(sf::Vector2f(30.f,250.f));
	this->enemy.setSize(sf::Vector2f(50.f, 200.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Red);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

void Game::initProtagonist()
{
	this->protagonist.setPosition(sf::Vector2f(745.f, 250.f));
	this->protagonist.setSize(sf::Vector2f(50.f, 200.f));
	this->protagonist.setScale(sf::Vector2f(0.5f, 0.5f));
	this->protagonist.setFillColor(sf::Color::Blue);
	this->protagonist.setOutlineColor(sf::Color::Green);
	this->protagonist.setOutlineThickness(1.f);
}

void Game::initBall()
{
	this->ball.setPosition(sf::Vector2f(375.f, 275.f));
	this->ball.setRadius(25.f);
	this->ball.setFillColor(sf::Color::White);
}

//constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
	this->initProtagonist();
	this->initBall();


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

	//update mouse position
	//std::cout << "Mouse Position: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << std::endl;
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
	this->window->draw(this->ball);
	this->window->draw(this->enemy);
	this->window->draw(this->protagonist);

	this->window->display();


}

void Game::updateEnemies()
{

}

void Game::renderEnemies()
{
}

void Game::updateProtagonist()
{
}

void Game::renderProtagonist()
{
}

void Game::updateBall()
{
}

void Game::renderBall()
{
}
