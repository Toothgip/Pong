#include "../include/Menu.hpp"

int Menu::update(sf::RenderWindow &window, sf::Event &event)
{
    if(choice == 0) //If no mode is selected
    {
        if(sf::Mouse::getPosition(window).x >= 306 && sf::Mouse::getPosition(window).x <= 448 &&
           sf::Mouse::getPosition(window).y >= 156 && sf::Mouse::getPosition(window).y <= 206)   //Solo button
        {
            m_textureMenu.loadFromFile("ressource/Menu/Menu b1 focus.png"); //Solo button with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                choice = 1;
            }
        }
        else if(sf::Mouse::getPosition(window).x >= 265 && sf::Mouse::getPosition(window).x <= 485 &&
                sf::Mouse::getPosition(window).y >= 237 && sf::Mouse::getPosition(window).y <= 286 )  //Versus button
        {
            m_textureMenu.loadFromFile("ressource/Menu/Menu b2 focus.png"); //Versus button with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If left click return to Game
            {
                return 3;
            }
        }
        else if(sf::Mouse::getPosition(window).x >= 202 && sf::Mouse::getPosition(window).x <= 558 &&
                sf::Mouse::getPosition(window).y >= 319 && sf::Mouse::getPosition(window).y <= 369)  //Tool button
        {
            m_textureMenu.loadFromFile("ressource/Menu/Menu b3 focus.png"); //Tool button with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If left click switch to submenu of tool
            {
                choice = 4;
            }
        }
        else
        {
            m_textureMenu.loadFromFile("ressource/Menu/Menu.png"); //Basic menu whiout effect
        }
    }
    if (choice == 1)  //Solo menu is selected
    {
        if(sf::Mouse::getPosition(window).x >= 304 && sf::Mouse::getPosition(window).x <= 505 &&
           sf::Mouse::getPosition(window).y >= 207 && sf::Mouse::getPosition(window).y <= 257)  // Survival
        {
            m_textureMenu.loadFromFile("ressource/Menu/Solo/Menu 1 focus.png"); //Survival button with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                return 1;
            }
        }
        else if(sf::Mouse::getPosition(window).x >= 367 && sf::Mouse::getPosition(window).x <= 426 &&
                sf::Mouse::getPosition(window).y >= 291 && sf::Mouse::getPosition(window).y <= 339) // IA
        {
            m_textureMenu.loadFromFile("ressource/Menu/Solo/Menu 2 focus.png");  //IA button with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                return 2;
            }
        }
        else
        {
            m_textureMenu.loadFromFile("ressource/Menu/Solo/Menu.png"); //Basic menu whiout effect
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))    //Return to main menu
            choice = 0;
    }

    if(choice == 4 && m_selected == 0) // Tool
    {
        if(sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 711 &&
           sf::Mouse::getPosition(window).y >= 125 && sf::Mouse::getPosition(window).y <= 175)
        {
            m_textureMenu.loadFromFile("ressource/Menu/Parametre/Parametres_P1-focus.png"); //Button 2 with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                m_selected = 1;                             //Change sensibility of player 1
            }
        }
        else if(sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 718 &&
                sf::Mouse::getPosition(window).y >= 226 && sf::Mouse::getPosition(window).y <= 276)
        {
            m_textureMenu.loadFromFile("ressource/Menu/Parametre/Parametres_P2-focus.png");  //Button 2 with shape effect

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                m_selected = 2;                             //Change sensibility of player 1
            }
        }
        else
        {
            m_textureMenu.loadFromFile("ressource/Menu/Parametre/Parametres.png");   //Basic menu whithout effect
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))    //Return to main menu
            choice = 0;
    }
    if(choice == 4  && m_selected !=0 ) // Cursor Sensibility

    {
        textfield.update(window, event);

        if(sf::Mouse::getPosition(window).x >= 285 && sf::Mouse::getPosition(window).x <= 410 &&
           sf::Mouse::getPosition(window).y >= 367 && sf::Mouse::getPosition(window).y <= 416 && //Bouton valider
            sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(m_selected == 1)
                m_sensibiliteP1 = textfield.getSensi();
            else
                m_sensibiliteP2 = textfield.getSensi();

            m_selected = 0;     //There no anymore sensiblity currently modified
            textfield.reset(); //Once submit reset textfield
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))    //Return to menu of curse sensibility
        {
            m_selected = 0;     //There no anymore sensiblity currently modified
            textfield.reset(); //Once submit reset textfield
            sf::sleep(sf::milliseconds(200)); //delay for no return directly to main menu
        }
    }
    return 0;   //Tell at Game that wee are always in menu
}
void Menu::draw(sf::RenderWindow &window)
{
    if(choice == 0)      //Menu
    {
        window.draw(m_spriteMenu);  //Draw  menu
    }
    if (choice == 1 )     //Solo
    {
        window.draw(m_spriteMenu);
    }
    if(choice == 4 && m_selected == 0) //Tool
    {
        window.draw(m_spriteMenu);
    }
    if(choice == 4 && m_selected != 0)  //Changing sensibility of a player
    {
       textfield.draw(window);
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
    m_textureMenu.loadFromFile("ressource/Menu/Menu.png");  //Basic menu whiout effect
    m_spriteMenu.setTexture(m_textureMenu);


    //Var indicate which menu is selected
    choice = 0;

    //Default sensbility
    m_sensibiliteP1 = 3;
    m_sensibiliteP2 = 3;

    //Var indicate which sensibility player is currently modified
    m_selected = 0;

}
Menu::~Menu()
{
    //Destructor
}
