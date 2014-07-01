#ifndef SOLO_H
#define SOLO_H
#include "main.h"

class Solo
{
    public:
        void initRectangle(sf::RectangleShape &rectangle, sf::Vector2f position);
        void initCircle (sf::CircleShape &circle);
        void moveRectangle(sf::RectangleShape &rectangle, int direction);
        void moveBall(sf::CircleShape &circle, sf::RectangleShape &rectangle1,  sf::RectangleShape &rectangle2);
        void update(sf::Event &event, sf::RenderWindow &window);
        void draw(sf::RenderWindow &window);
        void replay(sf::RenderWindow &window);
        void survie();
        void goal(int player);
        void IA();
        void score(int player);
        void win(int player);
        int ia = 0, sensi = 3, end = 0, debut = 1, afficherScore = 0, play = 0, wait = 0;
        float m_temps = 0;
        sf::RectangleShape m_rectangle2;
        string sensiRec, temps;
        Solo();
        virtual ~Solo();
    protected:
    private:
        int m_goalPlayer1 = 0, m_goalPlayer2 = 0;
        sf::RectangleShape m_rectangle1;
        sf::CircleShape m_ball;
        float m_x, m_y, m_speed;
        sf::Time m_time;
        sf::Clock m_clock;
        sf::Texture m_textureReplay, m_textureWin, m_texturePlayer1, m_textureNull, m_texturePlayer2;
        sf::Sprite m_spriteReplay, m_spritePlayer1, m_spritePlayer2, m_spriteWin;
        sf::String m_string;
        sf::Text m_text, m_textWin;
        sf::Font font;
};

#endif // SOLO_H