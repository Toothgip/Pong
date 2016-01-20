#include "main.h"
#include "include\Game.h"


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Pong");

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
        game.update(window, event);
        game.draw(window);

        window.display();

        sf::sleep(sf::milliseconds(0.5)); //Temporization for slow the ball and the curse
    }
    return EXIT_SUCCESS;
}
