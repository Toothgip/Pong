#ifndef MENU_H
#define MENU_H
#include "..\Main.hpp"
#include "Textfield.hpp"
#include "Versus.hpp"
#include "Solo.hpp"

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
        sf::Texture m_textureMenu;
        sf::Sprite m_spriteMenu;

};

#endif // MENU_H
