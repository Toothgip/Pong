#ifndef MENU_H
#define MENU_H
#include "main.h"
#include "Versus.h"
#include "Solo.h"

class Menu
{
    public:
        void draw(sf::RenderWindow &window);
        void update(sf::RenderWindow &window, sf::Event &event);

        Menu();
        virtual ~Menu();
        int choix;
        Versus versus;
        Solo solo;
    protected:
    private:
        sf::Texture m_textureMenu, m_textureEvent;
        sf::Sprite m_spriteMenu, m_spriteEvent;

};

#endif // MENU_H
