#include "include\Game.hpp"


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Pong");

    //Create object game that manage the Pong game
    Game game;

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        game.update(window, event); //Manage event with mouse et keyboard
        game.draw(window);          //Draw all the sprite of game

        window.display();

        sf::sleep(sf::milliseconds(0.5)); //Delay for slow the ball and the curse
    }
    return EXIT_SUCCESS;
}
