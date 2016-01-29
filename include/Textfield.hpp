#ifndef TEXTFIELD_H
#define TEXTFIELD_H
#include "..\Main.hpp"

class Textfield
{
    public:
        //Method
        Textfield(); //Constructor

        //Store the number entered by the user
        void recordingCharacter(sf::Event &event);

        //Manage the focus of the texfield
        void focus(sf::RenderWindow &window);

        //Manage event of Textfield
        void update(sf::RenderWindow &window, sf::Event &event);

        //Draw all elements of Textfield
        void draw(sf::RenderWindow &window);


        //Return sensibility entered
        int getSensi();

        //Reset number entered in the Textfield
        void reset();

        virtual ~Textfield(); //Destructor

    protected:
    private:
        //String store number entered by the user
        sf::String m_chaineCaractere;


        //char store the current digit enter by user, pointer is used to convert the char to int
        char m_caractereEntrer, *pt;

        //Texture and sprite of Textfield
        sf::Texture m_texture, m_textureFocus;
        sf::Sprite m_sprite;

        //Store if the Textfield and sensibility
        int m_focus, m_sensi;

        //Text that display the number entered by user
        sf::Font font;
        sf::Text m_text;
};

#endif // TEXTFIELD_H
