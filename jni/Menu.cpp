#include "Menu.h"

void Menu::update(sf::RenderWindow &window, sf::Event &event)
{
    if(choix == 0) // Menu principal
    {
        if(sf::Touch::getPosition(0).x >= 290 && sf::Touch::getPosition(0).x <= 344 && sf::Touch::getPosition(0).y >= 329 && sf::Touch::getPosition(0).y <= 460 &&
           sf::Touch::isDown(0))//bouton solo
        {
            choix = 1;
        }
        else if(sf::Touch::getPosition(0).x >= 192 && sf::Touch::getPosition(0).x <= 245 && sf::Touch::getPosition(0).y >= 292 && sf::Touch::getPosition(0).y <= 508 &&
           sf::Touch::isDown(0)) //Bouton Versus
        {
            choix = 2;
        }
    }
    if (choix == 1 && solo.play == 0)  // Lancement du Solo
    {
		solo.initRectangle(solo.m_rectangle2, sf::Vector2f(RECTANGLE2X, 400));
        solo.ia = solo.play = 1; //Lancement partie + bot
    }
    if(solo.play == 1) //Si solo lancer 
        solo.update(event, window);

    if(solo.wait == 1)                  //Attente apres un but en solo
    {
        sf::sleep(sf::milliseconds(500));
        solo.wait = 0;
    }
    if (choix == 2 && versus.end == 0) // Si Versus lancer
        versus.update(event);

    if(versus.wait == 1)    // Attente après un but en versus
    {
        sf::sleep(sf::milliseconds(500));
        versus.wait = 0;
    }
}
void Menu::draw(sf::RenderWindow &window)
{
    if(choix == 0)      //Menu
    {
        window.draw(m_spriteMenu);
    }
    if (solo.play == 1) // Solo lancé
    {
        solo.draw(window);
    }
    if (choix == 2 )  //Versus mode
    {
        window.clear(sf::Color::Black);
        versus.draw(window);
    }
    if(versus.end == 2 && choix == 2)  //Versus mode finish
    {
        window.draw(versus.m_spriteReplay);
        //versus.replay(versus.rejouer, window);
    }
}
Menu::Menu()
{
    //ctor
    m_textureMenu.loadFromFile("Menu/Menu.png");
    m_spriteMenu.setTexture(m_textureMenu);
	choix = 0;
}
Menu::~Menu()
{
    //dtor
}