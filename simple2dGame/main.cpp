#include <iostream>

#include "game.h"


int main()
{
    //initialize random seed
    srand(static_cast<unsigned>(time(0)));

    //window
    //sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "A Simple Game", sf::Style::Titlebar | sf::Style::Close);
    Game game;

    //game loop
    while (game.running() && !game.getEndGame())
    {
        //Update
        game.update();

        //Render
        game.render();
    }

   

    //end of application
    return 0;
}