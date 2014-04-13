#ifndef VERSUS_H
#define VERSUS_H

#include "..\main.h"
class Versus
{
    public:
        void initRectangle(sf::RectangleShape &rectangle, sf::Vector2f position);
        void initCircle (sf::CircleShape &circle);
        void moveBall(sf::CircleShape &circle, sf::RectangleShape &rectangle1,  sf::RectangleShape &rectangle2);
        void moveRectangle(sf::RectangleShape &rectangle, int direction);
        void update(sf::Event &event);
        void draw(sf::RenderWindow &window);
        void goal(sf::CircleShape &circle, int player);
        void initScore (sf::Texture &texture);
        void score(int player);
        void win(int player);
        void replay(int rejouer, sf::RenderWindow &window);

        sf::Sprite m_spriteReplay, m_spritePlayer1, m_spritePlayer2, m_spriteWin;
        sf::Texture m_texturePlayer1, m_textureNull, m_texturePlayer2, m_textureWin, m_textureReplay;
        bool wait = 0, m_quit = 0;
        int end = 0, rejouer = 2, sensi = 3;
        int m_goalPlayer1, m_goalPlayer2;
        string sensiRec;
        Versus();
        virtual ~Versus();
    protected:
    private:
        sf::RectangleShape m_rectangle1;
        sf::RectangleShape m_rectangle2;
        sf::CircleShape m_ball;
        float m_x, m_y, m_speed;

};

#endif // Versus_H
