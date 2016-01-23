#include "../include/Textfield.h"

void Textfield::recordingCharacter(sf::Event &event)
{
    sf::sleep(sf::milliseconds(90));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
    {
            m_caractereEntrer = 0;
            chaineCaractere.erase(chaineCaractere.getSize()- 1, 1);
            i--;
            m_text.setString(chaineCaractere);
    }
    if (event.type == sf::Event::TextEntered)
    {
        m_caractereEntrer = event.text.unicode;
        if(m_caractereEntrer >= 49 && m_caractereEntrer <= 57 && i < 1) //If number are write by user (max 99)
        {
            chaineCaractere.insert(i, m_caractereEntrer);
            i++;
            m_sensi = atoi(pt);
        }
        m_text.setString(chaineCaractere);
    }
}
void Textfield::focus(sf::RenderWindow &window)
{
    if(sf::Mouse::getPosition(window).x >= 338 && sf::Mouse::getPosition(window).x <= 456 &&
       sf::Mouse::getPosition(window).y >= 240 && sf::Mouse::getPosition(window).y <= 305 &&  //Texfield focused
        sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_sprite.setTexture(m_textureFocus);
            m_focus = 1;
        }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_sprite.setTexture(m_texture);
            m_focus = 0;
        }
}
void Textfield::update(sf::RenderWindow &window, sf::Event &event)
{
    focus(window);
    if(m_focus == 1)
    {
        recordingCharacter(event);
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
    if(chaineCaractere.getSize() != 0)
    {
        chaineCaractere.erase(0, 1);
    }


    m_text.setString("");
}

Textfield::Textfield()
{
    //ctor
    m_textureFocus.loadFromFile("ressource/Menu/Parametre/Sensi-focus.png");
    m_texture.loadFromFile("ressource/Menu/Parametre/Sensi.png");
    m_sprite.setTexture(m_texture);
    font.loadFromFile("arial.ttf");
    m_text.setFont(font);
    m_text.setPosition(360, 227);
    m_text.setColor(sf::Color::Black);
    m_text.setCharacterSize(70);
    i = record = 0;
    m_caractereEntrer = 0;

    pt = &m_caractereEntrer;
}

Textfield::~Textfield()
{
    //dtor
}
