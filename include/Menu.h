#ifndef MENU_H
#define MENU_H
#include "..\main.h"

class Menu
{
    public:
        void draw(sf::RenderWindow &window);
        void update(sf::RenderWindow &window);

        Menu();
        virtual ~Menu();
        int choix = 0, m_sensibilite = 0;

    protected:
    private:
        sf::Texture m_textureMenu, m_textureFenetre, m_textureEvent, m_textureParametre;
        sf::Sprite m_spriteMenu, m_spriteFenetre, m_spriteEvent, m_spriteParametre;

};

#endif // MENU_H
