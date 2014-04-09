#include "main.h"
#include "include\Versus.h"
#include "include\Menu.h"


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Pong");
    Versus Versus;
    Menu menu;

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        if(Versus.end == 0 && menu.choix != 2)      //Affichage dujeu
        {
            menu.update(window);
            menu.draw(window);
        }
        if(Versus.end == 0 && menu.choix == 2)      //Affichage du versus
        {
            window.clear();
            Versus.update(event);
            Versus.draw(window);
        }
        if(Versus.end == 2 && menu.choix == 2)
        {
            window.draw(Versus.m_spriteReplay);
            Versus.replay(Versus.rejouer, window);
        }
        window.display();

        if(Versus.wait)
        {
            sf::sleep(sf::milliseconds(500));
            Versus.wait = 0;
        }
        sf::sleep(sf::milliseconds(3));
        if(Versus.m_quit == 1)
        {
            window.close();
        }
    }
    return EXIT_SUCCESS;
}
