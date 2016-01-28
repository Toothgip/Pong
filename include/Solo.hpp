#ifndef SOLO_H
#define SOLO_H
#include "..\Main.hpp"

class Solo
{
    public:
        //Method
            Solo(); //Constructor

            //Initialization of Ball, curse sensibility and the solo mod
            void initRectangle(sf::RectangleShape &rectangle, sf::Vector2f position);
            void initCircle (sf::CircleShape &circle);
            void setIa(bool pIA);
            void setSensi(int pSensi);

            //Manage collision of the ball and the curse also moving the curse
            void moveRectangle(sf::RectangleShape &rectangle, int direction);
            void moveBall(sf::CircleShape &circle, sf::RectangleShape &rectangle1,  sf::RectangleShape &rectangle2);

            //Mange event and draw sprites and all drawable objects
            bool update(sf::Event &event, sf::RenderWindow &window);
            void draw(sf::RenderWindow &window);

            //Method that manage goal, the score and the end of the game
            void goal(int player);
            void score(int player);
            void win(int player);
            void replay(sf::RenderWindow &window);

            //Manage the mod that is selected
            void survie();
            void IA();

            //Destructor
            virtual ~Solo();

        //Variable

            //Manage the state of the game
            int end;

            //Bool that manage sleep time after a goal and the drawing in solo mod at the end of the game
            bool waitGoal, afficherScore;

            //Flow for survival mod
            std::ostringstream stream;

    protected:
    private:
        //Manage if AI is enabled
        bool m_ia;

        /* Store the score of players, AI, the sensibility of curse
        and  manage the increasing of speed depending of the time  */
        int m_goalPlayer1, m_goalPlayer2, m_sensi, m_timeSpeed;

        //Curse of player AI and the ball
        sf::RectangleShape m_rectangle1, m_rectangle2;
        sf::CircleShape m_ball;

        //Store the speed of the two axis of the ball
        float m_x, m_y, m_speed;

        //Store time in survival mod
        sf::Time m_time;

        //Clock used in survival mod
        sf::Clock m_clock;

        //Texture and sprite of all elements
        sf::Texture m_textureReplay, m_textureWin, m_texturePlayer1, m_textureNull, m_texturePlayer2;
        sf::Sprite m_spriteReplay, m_spritePlayer1, m_spritePlayer2, m_spriteWin;

        //Text which draw the time in survival mod and the player or AI who wins the game
        sf::Text m_textTime, m_textWin;

        //Font used in the text
        sf::Font font;
};

#endif // SOLO_H
