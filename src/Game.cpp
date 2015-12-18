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
            m_step = m_menu.update(window, event);

            //Set sensibility of rectangle
            m_solo.setSensi(m_menu.getSensiP1());
            break;
        }
        case 1:             //Solo survival
        {
            m_solo.setIa(false);    //Init class Solo without IA

            m_solo.update(event, window);

            if(m_solo.end == 2) //Return to the main menu
                m_step = 0;
            break;
        }
        case 2:             //Player vs AI
            if(init == false)
            {
                m_solo.setIa(true); //Init class Solo with IA
                m_solo.initRectangle(m_solo.m_rectangle2, sf::Vector2f(RECTANGLE2X, 400)); //Init the AI curse
                init = true;
            }


            m_solo.update(event, window);


        break;
    }
        if(m_solo.waitGoal) //If there is a goal in solo
        {                   //TODO: Ajouter but pour le versus
            sf::sleep(sf::milliseconds(500)); //Temporisation de 500 ms
            m_solo.waitGoal = false;
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
        case 2:
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
