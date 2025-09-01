#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


int main()
{
    //window
    sf::RenderWindow window(sf::VideoMode({ 600, 800 }), "A Simple Game", sf::Style::Titlebar | sf::Style::Close);


    //game loop
    while (window.isOpen())
    {
        //event polling
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
        }
    }

    //end of application
    return 0;
}