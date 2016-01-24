#ifndef TEXTFIELD_H
#define TEXTFIELD_H
#include "..\main.h"

class Textfield
{
    public:
        //Method
        Textfield(); //Constructor

        void recordingCharacter(sf::Event &event);
        void draw(sf::RenderWindow &window);
        sf::String chaineCaractere;
        void focus(sf::RenderWindow &window);
        void update(sf::RenderWindow &window, sf::Event &event);
        int getSensi();
        void reset();

        virtual ~Textfield(); //Destructor

    protected:
    private:

    char m_caractereEntrer, *pt;
    sf::Texture m_texture, m_textureFocus;
    sf::Sprite m_sprite;
    sf::Font font;
    int m_focus, m_sensi;
    sf::Text m_text;
};

#endif // TEXTFIELD_H
