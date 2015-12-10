#include "../include/Menu.h"

int Menu::update(sf::RenderWindow &window, sf::Event &event)
{
    if(choix == 0) //If no mode is selected
    {
        if(sf::Mouse::getPosition(window).x >= 306 && sf::Mouse::getPosition(window).x <= 448 &&
           sf::Mouse::getPosition(window).y >= 156 && sf::Mouse::getPosition(window).y <= 206 &&
           sf::Mouse::isButtonPressed(sf::Mouse::Left))                                             //Solo button
        {
            choix = 1;
           m_textureMenu.loadFromFile("ressource/Menu/Menu b1 focus.png"); //Solo button with shape effect
           m_spriteFenetre.setTexture(m_textureFenetre);
        }
        else if(sf::Mouse::getPosition(window).x >= 265 && sf::Mouse::getPosition(window).x <= 485 &&
                sf::Mouse::getPosition(window).y >= 237 && sf::Mouse::getPosition(window).y <= 286 &&
           sf::Mouse::isButtonPressed(sf::Mouse::Left))                                             //Versus button
        {
            return 3;
            m_textureMenu.loadFromFile("ressource/Menu/Menu b2 focus.png"); //Versus button with shape effect
        }
        else if(sf::Mouse::getPosition(window).x >= 202 && sf::Mouse::getPosition(window).x <= 558 &&
                sf::Mouse::getPosition(window).y >= 319 && sf::Mouse::getPosition(window).y <= 369 &&
           sf::Mouse::isButtonPressed(sf::Mouse::Left))                                             //Tool button
        {
            choix = 4;
            m_textureMenu.loadFromFile("ressource/Menu/Menu b3 focus.png"); //Tool button with shape effect
        }
        else
        {
            m_textureMenu.loadFromFile("ressource/Menu/Menu.png"); //Basic menu whiout effect
        }
    }
    if (choix == 1 && solo.play == 0)  //Solo menu is selected
    {
        if(sf::Mouse::getPosition(window).x >= 304 && sf::Mouse::getPosition(window).x <= 505 &&
           sf::Mouse::getPosition(window).y >= 207 && sf::Mouse::getPosition(window).y <= 257 &&
           sf::Mouse::isButtonPressed(sf::Mouse::Left))  // Survie
        {
            m_textureFenetre.loadFromFile("ressource/Menu/Solo/Menu 1 focus.png");
            solo.ia = 0;
            solo.play = 1;

            return 1;
        }
        else if(sf::Mouse::getPosition(window).x >= 367 && sf::Mouse::getPosition(window).x <= 426 &&
                sf::Mouse::getPosition(window).y >= 291 && sf::Mouse::getPosition(window).y <= 339 &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) // IA
        {
            m_textureFenetre.loadFromFile("ressource/Menu/Solo/Menu 2 focus.png");
            solo.initRectangle(solo.m_rectangle2, sf::Vector2f(RECTANGLE2X, 400));
            solo.ia = 1;
            solo.play = 1;
            return 2;
        }
        else
        {
            m_textureFenetre.loadFromFile("ressource/Menu/Solo/Menu.png");
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            choix = 0;
    }
    /* if(solo.play == 1) //Si solo lancer
        solo.update(event, window);
    if(solo.wait == 1)                  //Attente apres un but en solo
    {
        sf::sleep(sf::milliseconds(500));
        solo.wait = 0;
    }
    if (choix == 2 && versus.end == 0) //Versus update
        versus.update(event);

    if(versus.wait == 1)    // Attente après un but en versus
    {
        sf::sleep(sf::milliseconds(500));
        versus.wait = 0;
    } */

    if(choix == 3 && m_sensibilite == 0) // Parametre
    {
        if(sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 711 &&
           sf::Mouse::getPosition(window).y >= 125 && sf::Mouse::getPosition(window).y <= 175 &&
           sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_textureFenetre.loadFromFile("ressource/Menu/Parametre/Parametres b1 focus.png");
            m_sensibilite = 1;
        }
        else if(sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 718 &&
                sf::Mouse::getPosition(window).y >= 226 && sf::Mouse::getPosition(window).y <= 276 &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_textureFenetre.loadFromFile("ressource/Menu/Parametre/Parametres b2 focus.png");
            m_sensibilite = 1;
            versus.reglageSensi = 1;
        }
        else
        {
            m_textureFenetre.loadFromFile("ressource/Menu/Parametre/Parametres.png");
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            choix = 0;
    }
    if(choix == 3 && m_sensibilite != 0) //Sensibilité des curseurs
    {
        textfield.update(window, event);
        if(sf::Mouse::getPosition(window).x >= 285 && sf::Mouse::getPosition(window).x <= 410 &&
           sf::Mouse::getPosition(window).y >= 367 && sf::Mouse::getPosition(window).y <= 416 && //Bouton valider
            sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            versus.sensiRec = textfield.chaineCaractere;
            versus.sensiRec = solo.sensiRec;
            m_sensibilite = 0;
        }
    }
    return 0;
}
void Menu::draw(sf::RenderWindow &window)
{
    if(choix == 0)      //Menu
    {
        window.draw(m_spriteMenu);
    }
    if (choix == 1 && solo.play == 0)     //Solo
    {
        m_textureMenu.loadFromFile("ressource/Menu/Solo/Menu.png");
        window.draw(m_spriteMenu);
        window.draw(m_spriteFenetre);
    }
   /* if (solo.play == 1) // Solo lancé
    {
        solo.draw(window);
    }
    if (choix == 2 )  //Versus mode
    {
        window.clear();
        versus.draw(window);
    }
    if(versus.end == 2 && choix == 2)  //Versus mode finish
    {
        window.draw(versus.m_spriteReplay);
        versus.replay(versus.rejouer, window);
    }*/
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
