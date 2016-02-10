#include "../include/Menu.hpp"

int Menu::update(sf::RenderWindow &window, sf::Event &event)
{
    if(m_choice == 0) //If no mode is selected
    {
        if(sf::Mouse::getPosition(window).x >= 306 && sf::Mouse::getPosition(window).x <= 448 &&
           sf::Mouse::getPosition(window).y >= 156 && sf::Mouse::getPosition(window).y <= 206)   //Solo button
        {
            m_textureMenu.loadFromFile("ressource/Menu/Menu b1 focus.png"); //Solo button with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                m_choice = 1; //Solo Menu
            }
        }
        else if(sf::Mouse::getPosition(window).x >= 265 && sf::Mouse::getPosition(window).x <= 485 &&
                sf::Mouse::getPosition(window).y >= 237 && sf::Mouse::getPosition(window).y <= 286 )  //Versus button
        {
            m_textureMenu.loadFromFile("ressource/Menu/Menu b2 focus.png"); //Versus button with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If left click return to Game
            {
                return 3;   //Play in versus
            }
        }
        else if(sf::Mouse::getPosition(window).x >= 202 && sf::Mouse::getPosition(window).x <= 558 &&
                sf::Mouse::getPosition(window).y >= 319 && sf::Mouse::getPosition(window).y <= 369)  //Tool button
        {
            m_textureMenu.loadFromFile("ressource/Menu/Menu b3 focus.png"); //Tool button with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If left click switch to Tool Menu
            {
                m_choice = 4;
            }
        }
        else //If nothing is select
        {
            m_textureMenu.loadFromFile("ressource/Menu/Menu.png"); //Basic menu whiout effect
        }
    }
    if (m_choice == 1)  //Solo menu is selected
    {
        if(sf::Mouse::getPosition(window).x >= 304 && sf::Mouse::getPosition(window).x <= 505 &&
           sf::Mouse::getPosition(window).y >= 207 && sf::Mouse::getPosition(window).y <= 257)  // Survival
        {
            m_textureMenu.loadFromFile("ressource/Menu/Solo/Menu 1 focus.png"); //Survival button with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If  survival mod is clicked
            {
                return 1;   //Launch the Survival mod by Game class
            }
        }
        else if(sf::Mouse::getPosition(window).x >= 367 && sf::Mouse::getPosition(window).x <= 426 &&
                sf::Mouse::getPosition(window).y >= 291 && sf::Mouse::getPosition(window).y <= 339) // IA
        {
            m_textureMenu.loadFromFile("ressource/Menu/Solo/Menu 2 focus.png");  //IA button with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If IA mod is clicked
            {
                return 2;  //Launch IA mod by Game class
            }
        }
        else
        {
            m_textureMenu.loadFromFile("ressource/Menu/Solo/Menu.png"); //Basic menu without effect
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))    //Return to main menu
            m_choice = 0;
    }

    if(m_choice == 4 && m_selected == 0) // Tool
    {
        if(sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 711 &&    //Sensibility of player 1
           sf::Mouse::getPosition(window).y >= 125 && sf::Mouse::getPosition(window).y <= 175)
        {
            m_textureMenu.loadFromFile("ressource/Menu/Parametre/Parametres_P1-focus.png"); //Button 2 with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                m_selected = 1;                             //Change sensibility of player 1
            }
        }
        else if(sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 718 &&  //Sensibility of player 2
                sf::Mouse::getPosition(window).y >= 226 && sf::Mouse::getPosition(window).y <= 276)
        {
            m_textureMenu.loadFromFile("ressource/Menu/Parametre/Parametres_P2-focus.png");  //Button 2 with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                m_selected = 2;                             //Change sensibility of player 2
            }
        }
        else    //If nothing is selected
        {
            m_textureMenu.loadFromFile("ressource/Menu/Parametre/Parametres.png");   //Basic menu without effect
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))    //Return to main menu
            m_choice = 0;
    }
    if(m_selected != 0 ) // Cursor Sensibility
    {
        m_textfield.update(window, event);

        if(sf::Mouse::getPosition(window).x >= 285 && sf::Mouse::getPosition(window).x <= 410 &&
           sf::Mouse::getPosition(window).y >= 367 && sf::Mouse::getPosition(window).y <= 416 && //Validate button
            sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(m_selected == 1)     //Player 1
                m_sensibiliteP1 = m_textfield.getSensi();
            else                    //Player 2
                m_sensibiliteP2 = m_textfield.getSensi();

            m_selected = 0;     //There no anymore sensibility currently modified
            m_textfield.reset(); //Once submit reset Textfield
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))    //Return to menu of curse sensibility
        {
            m_selected = 0;     //There no anymore sensibility currently modified
            m_textfield.reset(); //Once submit reset Textfield
            sf::sleep(sf::milliseconds(200)); //delay for no return directly to main menu
        }
    }
    return 0;   //Tell at Game that we are always in menu
}
void Menu::draw(sf::RenderWindow &window)
{
    if(m_choice == 0)      //Menu
    {
        window.draw(m_spriteMenu);  //Draw  menu
    }
    if (m_choice == 1 )     //Solo Menu
    {
        window.draw(m_spriteMenu);
    }
    if(m_selected == 0) //Tool Menu
    {
        window.draw(m_spriteMenu);
    }
    if(m_selected != 0)  //Changing sensibility of a player
    {
       m_textfield.draw(window);
    }
}

int Menu::getSensiP1()
{
    return m_sensibiliteP1;
}

int Menu::getSensiP2()
{
    return m_sensibiliteP2;
}

Menu::Menu() //Constructor
{
    //Sprite of menu
    m_textureMenu.loadFromFile("ressource/Menu/Menu.png");  //Basic menu without effect
    m_spriteMenu.setTexture(m_textureMenu);

    //Variable indicate which menu is selected
    m_choice = 0;

    //Default sensibility
    m_sensibiliteP1 = 3;
    m_sensibiliteP2 = 3;

    //Var indicate which sensibility player is currently modified
    m_selected = 0;
}
Menu::~Menu()
{
    //Destructor
}
