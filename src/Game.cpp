#include "Game.h"

Game::Game() //Constructeur
{
    m_step = 0;
    init = false; //Use for initialise curse ... in some mode
}

void Game::update(sf::RenderWindow &window, sf::Event &event)
{

    switch(m_step)
    {
        case 0:             //Main Menu
        {

            //reset the mod
            m_versus.end = 0;
            m_solo.end = 0;
            init = false;

            m_step = m_menu.update(window, event);

            //Set sensibility of rectangle
            m_solo.setSensi(m_menu.getSensiP1());
            m_versus.setSensi(m_menu.getSensiP1(), m_menu.getSensiP2());
            break;
        }
        case 1:             //Solo survival
        {
            if(init == false)
            {
                m_solo.setIa(false); //Init class Solo without IA
                init = true;
            }

            if(m_solo.update(event, window)) //Return to the main menu
                m_step = 0;
            break;
        }
        case 2:             //Player vs AI
        {
            if(init == false)
            {
                m_solo.setIa(true); //Init class Solo with IA
                init = true;
            }

            if(m_solo.update(event, window)) //If update return true: return to main menu
                m_step = 0;
            break;
        }
        case 3:             //Versus mod
        {
            if(m_versus.update(window, event)) //If update return true: return to main menu
                m_step = 0;
            break;
        }
    }

    if(m_solo.waitGoal || m_versus.waitGoal) //If there is a goal in solo
    {
        sf::sleep(sf::milliseconds(500)); //Temporisation de 500 ms
        m_solo.waitGoal = false;
        m_versus.waitGoal = false;
    }
    //TODO: Ajouter une temporisation au d�but du jeu
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
        case 2:             //Solo AI
        {
            m_solo.draw(window);
            break;
        }
        case 3:
        {
            m_versus.draw(window);
            break;
        }
    }

}


Game::~Game()
{
    //dtor
}
