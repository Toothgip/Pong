#include "main.h"
#include "Versus.h"
#include "Menu.h"


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "");
    //Versus Versus;
    Menu menu;

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
        window.clear(sf::Color::Black);
        menu.update(window, event);
        menu.draw(window);

        window.display();

        sf::sleep(sf::milliseconds(3)); // Pour ralentir la boucle pour la balle et les rectangles
    }
    return EXIT_SUCCESS;
}
