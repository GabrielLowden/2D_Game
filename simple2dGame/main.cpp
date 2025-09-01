#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "game.h"


int main()
{
    //window
    //sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "A Simple Game", sf::Style::Titlebar | sf::Style::Close);
    Game game;

    //game loop
    while (game.running())
    {
        //Update
        game.update();

        //Render
        game.render();
    }

   

    //end of application
    return 0;
}