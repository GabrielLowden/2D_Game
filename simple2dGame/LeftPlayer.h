#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class LeftPlayer
{
private:
	sf::RectangleShape lPaddle;

	void initLeftVariables();
	void initLeftPaddle();


public:
	LeftPlayer();
	virtual ~LeftPlayer();

	void updateLPaddle();
	void renderL(sf::RenderTarget* target);


};

