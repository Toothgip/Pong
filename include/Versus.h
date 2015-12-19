#ifndef VERSUS_H
#define VERSUS_H

#include "..\main.h"
class Versus
{
    public:
        //Method
        Versus(); //Constructor

        void initRectangle(sf::RectangleShape &rectangle, sf::Vector2f position);
        void initCircle (sf::CircleShape &circle);
        void setSensi(int pSensi1, int pSensi2);
        void moveBall(sf::CircleShape &circle, sf::RectangleShape &rectangle1,  sf::RectangleShape &rectangle2);
        void moveRectangle(sf::RectangleShape &rectangle, int direction, int player);
        bool update(sf::RenderWindow &window, sf::Event &event);
        void draw(sf::RenderWindow &window);
        void goal(int player);
        void initScore (sf::Texture &texture);
        void score(int player);
        void win(int player);
        void replay(sf::RenderWindow &window);


        bool waitGoal;
        int end;

        virtual ~Versus(); //Destructor

    protected:
    private:
        int m_sensi1, m_sensi2,  m_goalPlayer1, m_goalPlayer2;
        sf::RectangleShape m_rectangle1;
        sf::RectangleShape m_rectangle2;
        sf::CircleShape m_ball;
        float m_x, m_y, m_speed;

        sf::Sprite m_spriteReplay, m_spritePlayer1, m_spritePlayer2, m_spriteWin;
        sf::Texture m_texturePlayer1, m_textureNull, m_texturePlayer2, m_textureWin, m_textureReplay;

};

#endif // Versus_H
