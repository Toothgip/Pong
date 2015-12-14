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

    protected:
    private:

        int choice = 0, m_sensibiliteP1, m_sensibiliteP2, m_selected;
        sf::Texture m_textureMenu, m_textureFenetre, m_textureEvent;
        sf::Sprite m_spriteMenu, m_spriteFenetre, m_spriteEvent;

};

#endif // MENU_H
