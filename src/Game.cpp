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
