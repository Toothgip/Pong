#include "main.h"
#include "include\Game.h"


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Pong");
    //Versus Versus;
    //Menu menu;

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

        sf::sleep(sf::milliseconds(3)); // Pour ralentir la boucle pour la balle et les rectangles
    }
    return EXIT_SUCCESS;
}
