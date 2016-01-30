#include "Game.hpp"

Game::Game() //Constructor
{
    m_step = 0;
    init = true; //Use for initialize curse ... in some mode or IA
}

void Game::update(sf::RenderWindow &window, sf::Event &event)
{
    switch(m_step)
    {
        case 0:             //Main Menu
        {
            //Reset state of all the mod
            m_versus.end = 0;
            m_solo.end = 0;

            init = true;

            m_step = m_menu.update(window, event);

            //Set sensibility of rectangle
            m_solo.setSensi(m_menu.getSensiP1());
            m_versus.setSensi(m_menu.getSensiP1(), m_menu.getSensiP2());
            break;
        }
        case 1:             //Solo survival
        {
            if(init == true)
            {
                m_solo.setIa(false); //Init class Solo without IA
                init = false;
            }

            if(m_solo.update(event, window)) //Return to the main menu
                m_step = 0;
            break;
        }
        case 2:             //Player vs AI
        {
            if(init == true)
            {
                m_solo.setIa(true); //Init class Solo with IA
            }

            if(m_solo.update(event, window)) //If update return true: return to main menu
                m_step = 0;

            if(init == true)  //Add a delay at the beginning of the game
            {
                sf::sleep(sf::milliseconds(100));
                init = false;
            }
            break;
        }
        case 3:             //Versus mod
        {
            if(m_versus.update(window, event)) //If update return true: return to main menu
                m_step = 0;

            if(init == true)
            {
                sf::sleep(sf::milliseconds(100));
                init = false;
            }
            break;
        }
    }
    if(m_solo.waitGoal || m_versus.waitGoal) //If there is a goal in solo
    {
        sf::sleep(sf::milliseconds(500)); //delay of 500 ms when goal
        m_solo.waitGoal = false;
        m_versus.waitGoal = false;
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
        case 1:             //Survival mod
        {
            m_solo.draw(window);
            break;
        }
        case 2:             //Solo AI
        {
            m_solo.draw(window);
            break;
        }
        case 3:         //Versus Mod
        {
            m_versus.draw(window);
            break;
        }
    }

}

Game::~Game()   //Destructor
{

}
