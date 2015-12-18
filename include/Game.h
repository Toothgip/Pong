#ifndef GAME_H
#define GAME_H
#include "..\main.h"
#include "Menu.h"
#include "Versus.h"
#include "Solo.h"


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
        bool init;
};

#endif // GAME_H
