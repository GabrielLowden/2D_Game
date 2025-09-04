#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class RightPlayer
{
private:
	sf::RectangleShape rPaddle;

	float movementSpeed;

	void initRightVariables();
	void initRightPaddle();

public:
	RightPlayer(float x = 750.f, float y = 250.f);
	virtual ~RightPlayer();

	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void updateRPaddle(const sf::RenderTarget* target);
	void renderR(sf::RenderTarget* target);

};

