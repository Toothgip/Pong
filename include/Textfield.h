#ifndef TEXTFIELD_H
#define TEXTFIELD_H
#include "..\main.h"

class Textfield
{
    public:
        Textfield();
        virtual ~Textfield();
        void recordingCharacter(sf::Event &event, int choixCaractere);
        void draw(sf::RenderWindow &window);
        sf::String chaineCaractere;
        void focus(sf::RenderWindow &window);
        void update(sf::RenderWindow &window, sf::Event &event);
        int record;
    protected:
    private:
    char m_caractereEntrer = 0;
    sf::Texture m_texture, m_textureFocus;
    sf::Sprite m_sprite;
    sf::Text m_text;
    sf::Font font;
    int i, m_focus;
};

#endif // TEXTFIELD_H
