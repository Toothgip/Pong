#ifndef VERSUS_H
#define VERSUS_H

#include "..\Main.hpp"
class Versus
{
    public:
        //Method
        Versus(); //Constructor

        //Initialize curse, ball, sensibility of the curse and score for the players
        void initRectangle(sf::RectangleShape &rectangle, sf::Vector2f position);
        void initCircle (sf::CircleShape &circle);
        void setSensi(int pSensi1, int pSensi2);
        void initScore (sf::Texture &texture);

        //Manage collision of the ball et moving of the curse
        void moveBall(sf::CircleShape &circle, sf::RectangleShape &rectangle1,  sf::RectangleShape &rectangle2);
        void moveRectangle(sf::RectangleShape &rectangle, int direction, int player);

        //Mange event and draw sprites and all drawable objects
        bool update(sf::RenderWindow &window, sf::Event &event);
        void draw(sf::RenderWindow &window);

        //Manage goal, score of player, win, and the replay
        void goal(int player);
        void score(int player);
        void win(int player);
        void replay(sf::RenderWindow &window);

        virtual ~Versus(); //Destructor

        //Variable
            //Bool that manage sleep time after a goal and the drawing in solo mod at the end of the game
            bool waitGoal;

            //Manage the state of the game
            int end;

    protected:
    private:
        //Store sensibility of player and score of player
        int m_sensi1, m_sensi2,  m_goalPlayer1, m_goalPlayer2;

        //Curse of player and ball
        sf::RectangleShape m_rectangle1, m_rectangle2;
        sf::CircleShape m_ball;

        //Store the speed of the two axis of the ball
        float m_x, m_y, m_speed;

        //Texture and sprite of all elements
        sf::Sprite m_spriteReplay, m_spritePlayer1, m_spritePlayer2, m_spriteWin;
        sf::Texture m_texturePlayer1, m_textureNull, m_texturePlayer2, m_textureWin, m_textureReplay;
};
#endif // Versus_H
