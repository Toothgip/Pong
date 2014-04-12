#include "Menu.h"


void Menu::update(sf::RenderWindow &window, sf::Event &event)
{
    if(choix == 0) // Menu principal
    {
        if(sf::Mouse::getPosition(window).x >= 306 && sf::Mouse::getPosition(window).x <= 448 && sf::Mouse::getPosition(window).y >= 156 && sf::Mouse::getPosition(window).y <= 206 &&
           sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            choix = 1;
            m_textureMenu.loadFromFile("ressource/Menu/Menu b1 focus.png");
            m_spriteFenetre.setTexture(m_textureFenetre);
        }
        else if(sf::Mouse::getPosition(window).x >= 265 && sf::Mouse::getPosition(window).x <= 485 && sf::Mouse::getPosition(window).y >= 237 && sf::Mouse::getPosition(window).y <= 286 &&
           sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            choix = 2;
            m_textureMenu.loadFromFile("ressource/Menu/Menu b2 focus.png");
        }
        else if(sf::Mouse::getPosition(window).x >= 202 && sf::Mouse::getPosition(window).x <= 558 && sf::Mouse::getPosition(window).y >= 319 && sf::Mouse::getPosition(window).y <= 369 &&
           sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            choix = 3;
            m_textureMenu.loadFromFile("ressource/Menu/Menu b3 focus.png");
        }
        else
        {
            m_textureMenu.loadFromFile("ressource/Menu/Menu.png");
        }
    }
    if (choix == 1)  // Solo
    {
        if(sf::Mouse::getPosition(window).x >= 304 && sf::Mouse::getPosition(window).x <= 505 && sf::Mouse::getPosition(window).y >= 207 && sf::Mouse::getPosition(window).y <= 257 &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_textureFenetre.loadFromFile("ressource/Menu/Solo/Menu 1 focus.png");
        }
        else if(sf::Mouse::getPosition(window).x >= 367 && sf::Mouse::getPosition(window).x <= 426 && sf::Mouse::getPosition(window).y >= 291 && sf::Mouse::getPosition(window).y <= 339 &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_textureFenetre.loadFromFile("ressource/Menu/Solo/Menu 2 focus.png");
        }
        else
        {
            m_textureFenetre.loadFromFile("ressource/Menu/Solo/Menu.png");
        }
    }
    if(choix == 3 && m_sensibilite == 0) // Parametre
    {
        if(sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 711 && sf::Mouse::getPosition(window).y >= 125 && sf::Mouse::getPosition(window).y <= 175 &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_textureFenetre.loadFromFile("ressource/Menu/Parametre/Parametres b1 focus.png");
            m_sensibilite = 1;
        }
        else if(sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 718 && sf::Mouse::getPosition(window).y >= 226 && sf::Mouse::getPosition(window).y <= 276 &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_textureFenetre.loadFromFile("ressource/Menu/Parametre/Parametres b2 focus.png");
            m_sensibilite = 1;
        }
        else
        {
            m_textureFenetre.loadFromFile("ressource/Menu/Parametre/Parametres.png");
        }
    }
    if(m_sensibilite != 0)
    {
        textfield.update(window, event);
        if(sf::Mouse::getPosition(window).x >= 285 && sf::Mouse::getPosition(window).x <= 410 && sf::Mouse::getPosition(window).y >= 367 && sf::Mouse::getPosition(window).y <= 416 &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_sensibilite = 0;
        }
    }
}
void Menu::draw(sf::RenderWindow &window)
{
    if(choix == 0)
    {
        window.draw(m_spriteMenu);
    }
    if (choix == 1)
    {
        m_textureMenu.loadFromFile("ressource/Menu/Solo/Menu.png");
        window.draw(m_spriteMenu);
        window.draw(m_spriteFenetre);
    }

    if(choix == 3 && m_sensibilite == 0)
    {
        m_textureFenetre.loadFromFile("ressource/Menu/Parametre/Parametres.png");
        m_spriteFenetre.setTexture(m_textureFenetre);
        window.draw(m_spriteFenetre);
    }
    if(m_sensibilite != 0)
    {
       textfield.draw(window);
    }
}
/*void Menu::option(int joueur)
{
    if(joueur == 1)
    {

    }
    else if(joueur == 3)
    {

    }

}*/
Menu::Menu()
{
    //ctor
    m_textureMenu.loadFromFile("ressource/Menu/Menu.png");
    m_spriteMenu.setTexture(m_textureMenu);
    m_spriteFenetre.setTexture(m_textureMenu);
    m_textureParametre.loadFromFile("ressource/Menu/Parametre/Sensi.png");
    m_spriteParametre.setTexture(m_textureParametre);

}
Menu::~Menu()
{
    //dtor
}
