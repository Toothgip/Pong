#include "Game.h"

Game::Game() //Constructeur
{
    m_step = 0;
}

void Game::update(sf::RenderWindow &window, sf::Event &event)
{

    switch(m_step)
    {
        case 0:             //Main Menu
        {
            m_step = m_menu.update(window, event);
            break;
        }
        case 1:             //Solo survie
        {
            m_solo.update(event, window);

            if(m_solo.waitGoal) //Si il y a un but
            {
                sf::sleep(sf::milliseconds(500)); //Temporisation de 500 ms
                m_solo.waitGoal = false;
            }

            if(m_solo.end == 2) //Return to the main menu
                step = 0;
            break;
        }
    }
}

void Game::draw(sf::RenderWindow &window)
{
    switch(m_step)
    {
        case 0:             //Main Menu
        {
            m_menu.draw(window);
            break;
        }
        case 1:             //Solo survie
        {
            m_solo.draw(window);
            break;
        }
    }

}


Game::~Game()
{
    //dtor
}
