#include "Game.hpp"

Game::Game() //Constructor
{
    m_step = 0;
    m_init = true; //Use for initialize curse ... in some mode or IA
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

            m_init = true;

            m_step = m_menu.update(window, event);

            break;
        }
        case 1:             //Solo survival
        {
            if(m_init == true) //Initialize the mod
            {
                sf::sleep(sf::milliseconds(100)); //Add a delay at the beginning of the game

                m_solo.setSensi(m_menu.getSensiP1());    //Set sensibility of curse
                m_solo.setIa(false); //Initialize class Solo without IA start clock
                m_init = false;
            }

            if(m_solo.update(event, window))
            {
                m_step = 0; //Return to the main menu
            }
            break;
        }
        case 2:      //Player vs AI
        {
            if(m_init == true) //Initialize the mod
            {
                m_solo.setIa(true); //Initialize class Solo with IA
                m_solo.setSensi(m_menu.getSensiP1());    //Set sensibility of curse

                sf::sleep(sf::milliseconds(100)); //Add a delay at the beginning of the game
                m_init = false;
            }

            if(m_solo.update(event, window) == true) //If update return true:
            {
                m_step = 0;         //Return to main menu
            }
            break;
        }
        case 3:      //Versus mod
        {
            if(m_init == true) //Initialize the mod
            {
                m_versus.setSensi(m_menu.getSensiP1(), m_menu.getSensiP2()); //Set sensibility of curse

                sf::sleep(sf::milliseconds(100));
                m_init = false;
            }

            if(m_versus.update(window, event) == true) //If update return true: return to main menu
            {
                m_step = 0;
            }
            break;
        }
    }
    if(m_solo.waitGoal || m_versus.waitGoal) //If there is a goal in solo or in versus
    {
        sf::sleep(sf::milliseconds(500)); //delay of 500 ms
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
    //TODO: Add branches in github with codeblocks project and just executable games for play

    //TODO: NEW FUNCTIONNALITY
    //TODO: MODE 3 jours avec pong en triange
    //TODO: Menu en anglais
    //TODO: Choisir langue au demarrage du jeu
    //TODO: Skin de rectangle et de balle
    //TODO: Textfield appuyer sur entrer = valider
    //TODO: Quand on quitte le solo retourner dans MAIN menu reset value menu
    //TODO: AJOUTER delay quand on rejoue en versus
