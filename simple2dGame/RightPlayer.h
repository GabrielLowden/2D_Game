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

	void initRightVariables();
	void initRightPaddle();

public:
	RightPlayer();
	virtual ~RightPlayer();

	void updateRPaddle();
	void renderR(sf::RenderTarget* target);

};

