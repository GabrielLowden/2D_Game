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

	float movementSpeed;

	void initLeftVariables();
	void initLeftPaddle();

public:
	LeftPlayer(float x = 25.f, float y = 250.f);
	virtual ~LeftPlayer();

	const sf::RectangleShape getPaddle() const;

	void updateLInput();
	//passing target to these functions is not necessary after SFML v3.0.
	void updateLWindowBoundsCollision(const sf::RenderTarget* target);
	void updateLPaddle(const sf::RenderTarget* target);
	void renderL(sf::RenderTarget* target);


};

