#ifndef MENU_H
#define MENU_H
#include "..\Main.hpp"
#include "Textfield.hpp"

class Menu
{
    public:
        //Method
        Menu();  //Constructor

        //Manage event triggered
        int update(sf::RenderWindow &window, sf::Event &event);

        //Display all sprites
        void draw(sf::RenderWindow &window);

        //Return sensibility of players entered by user
        int getSensiP1();
        int getSensiP2();

        virtual ~Menu(); //Destructor



    protected:
    private:
        //Object Textfield
        Textfield m_textfield;

        //Store the menu selected, sensibility of players and which sensibility is modified
        int m_choice = 0, m_sensibiliteP1, m_sensibiliteP2, m_selected;

        //Sprites and Texture of Menu
        sf::Texture m_textureMenu;
        sf::Sprite m_spriteMenu;

};

#endif // MENU_H
