#include "../include/Textfield.hpp"

void Textfield::recordingCharacter(sf::Event &event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && m_chaineCaractere.getSize() != 0)
    {
            m_caractereEntrer = 0;  //Reset the number entered
            m_chaineCaractere.erase(m_chaineCaractere.getSize()- 1, 1); //Delete the number that was entered                        //There are currently no number entered

            m_text.setString(m_chaineCaractere);  //Update the text that is draw on the window
    }

    if (event.type == sf::Event::TextEntered)   //If some number was entered
    {
        m_caractereEntrer = event.text.unicode; //Store the number entered

        if(m_caractereEntrer >= 49 && m_caractereEntrer <= 57 && m_chaineCaractere.getSize() < 1) //If it's a number (max 9)
        {
            m_chaineCaractere.insert(0, m_caractereEntrer);   //Insert in the string that will be draw on the window

            m_sensi = atoi(pt); //Convert the char enter by user in a integer
        }
        m_text.setString(m_chaineCaractere); //Update the text that is draw on the window
    }
}
void Textfield::focus(sf::RenderWindow &window)
{
    if(sf::Mouse::getPosition(window).x >= 338 && sf::Mouse::getPosition(window).x <= 456 &&
       sf::Mouse::getPosition(window).y >= 240 && sf::Mouse::getPosition(window).y <= 305 &&  //Textfield focused
        sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_sprite.setTexture(m_textureFocus);
            m_focus = 1;
        }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left))    //If user click Outside the Textfield
        {
            m_sprite.setTexture(m_texture);
            m_focus = 0;
        }
}
void Textfield::update(sf::RenderWindow &window, sf::Event &event)
{
    focus(window);
    if(m_focus == 1)    //If Textfield focused
    {
        recordingCharacter(event);  //Record text entered by user
    }
}
void Textfield::draw(sf::RenderWindow &window)
{
    window.draw(m_sprite);
    window.draw(m_text);
}

int Textfield::getSensi()
{
    return m_sensi;
}

void Textfield::reset()
{
    if(m_chaineCaractere.getSize() != 0)
    {
        m_chaineCaractere.erase(0, 1);       //Delete text that was entered
    }

    m_text.setString("");       //Reset text that is draw
}

Textfield::Textfield()  //Constructor
{
    //Initialize sprite of Textfield
    m_textureFocus.loadFromFile("ressource/Menu/Parametre/Sensi-focus.png");
    m_texture.loadFromFile("ressource/Menu/Parametre/Sensi.png");
    m_sprite.setTexture(m_texture);

    //Initialize text of textField
    font.loadFromFile("arial.ttf");
    m_text.setFont(font);
    m_text.setPosition(360, 227);
    m_text.setColor(sf::Color::Black);
    m_text.setCharacterSize(70);

    //Variable
    m_caractereEntrer = 0;
    pt = &m_caractereEntrer;
}

Textfield::~Textfield() //Destructor
{

}
