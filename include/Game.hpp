#ifndef GAME_H
#define GAME_H

#include "Menu.hpp" //Including Main.hpp
#include "Versus.hpp"
#include "Solo.hpp"


class Game
{
    public:
        //Method
        Game(); //Constructor

        void update(sf::RenderWindow &window, sf::Event &event);
        void draw(sf::RenderWindow &window);


        virtual ~Game(); //Destructor

    protected:
    private:

        //Object
        Menu m_menu;
        Versus m_versus;
        Solo m_solo;

        //Variable
        int m_step;
        bool m_init;
};

#endif // GAME_H
