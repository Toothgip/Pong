#ifndef MENU_H
#define MENU_H
#include "..\main.h"
#include "Textfield.h"
#include "Versus.h"
#include "Solo.h"

class Menu
{
    public:
        //Method
        Menu();  //Constructor

        void draw(sf::RenderWindow &window);
        int update(sf::RenderWindow &window, sf::Event &event);

        int getSensiP1();

        int getSensiP2();

        virtual ~Menu(); //Destructor

        Textfield textfield;
        Versus versus;
        Solo solo;

    protected:
    private:

        int choix = 0, m_sensibiliteP1, m_sensibiliteP2, m_selected;
        sf::Texture m_textureMenu, m_textureFenetre, m_textureEvent, m_textureParametre;
        sf::Sprite m_spriteMenu, m_spriteFenetre, m_spriteEvent, m_spriteParametre;

};

#endif // MENU_H
