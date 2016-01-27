#include "..\include\Versus.h"

void Versus::initRectangle(sf::RectangleShape &rectangle, sf::Vector2f position)
{
    rectangle.setPosition(position.x, position.y);
    rectangle.setSize(sf::Vector2f(20, 150));
}
void Versus::initCircle (sf::CircleShape &circle) // Ball
{
    circle.setRadius(10);
    circle.setPosition(sf::Vector2f(400, 300));
}
void Versus::initScore (sf::Texture &texture)
{
    texture.loadFromFile("ressource/score/0.png"); // Initialize score at 0
}

void Versus::setSensi(int pSensi1, int pSensi2) //Set sensibility of the player's curse
{
    m_sensi1 = pSensi1;
    m_sensi2 = pSensi2;
}
void Versus::moveRectangle(sf::RectangleShape &rectangle, int direction, int player)
{
    if(player == 1)    //Player 1
    {
        if(direction == 1 && rectangle.getPosition().y >=0 ) // Move up
        {
            rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y - (0.1 * m_sensi2));
        }
        else if (direction == 2 && rectangle.getPosition().y <= WINDOW_Y - 148) // Move down
        {
            rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y + (0.1 * m_sensi2));
        }
    }
    else    //Player 2
    {
        if(direction == 1 && rectangle.getPosition().y >=0 ) // Move up
        {
            rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y - (0.1 * m_sensi2));
        }
        else if(direction == 2 && rectangle.getPosition().y <= WINDOW_Y - 148) //Move Down
        {
            rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y + (0.1 * m_sensi2));
        }
    }
}
bool Versus::update(sf::RenderWindow &window, sf::Event &event)
{
    if(end == 0)    //If the game is not finished
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            moveRectangle(m_rectangle1, 1, 1);     //Move up Player 1 curse
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            moveRectangle(m_rectangle1, 2, 1);     //Move down Player 1 curse
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            moveRectangle(m_rectangle2, 1, 2);     //Move top Player 2 curse
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            moveRectangle(m_rectangle2, 2, 2);     //Mode down Player 2 curse
        }
        moveBall(m_ball, m_rectangle1, m_rectangle2); // Move of the ball
    }
    else if (end == 2)  //If the game is finished
    {
        replay(window); //Asked to replay
    }
    else if(end == 3)   //If the player doesn't want to replay
    {
        sf::sleep(sf::milliseconds(150));
        return true;                //Return to main menu
    }
    return false;

}
void Versus::draw(sf::RenderWindow &window)
{
    if(end == 0)                    // if the game is not finished
    {
        window.draw(m_spritePlayer1);
        window.draw(m_spritePlayer2);
        window.draw(m_rectangle1);
        window.draw(m_rectangle2);
        window.draw(m_ball);
    }
    else if (end == 1)                   // If the game is finished draw who has won
    {
        window.draw(m_spriteWin);
        window.display();
        sf::sleep(sf::seconds(0.7));

        end = 2;
    }
    else if (end == 2)                  //Asked of player if he wants replay
    {
        window.draw(m_spriteReplay);
    }

}
void Versus::moveBall(sf::CircleShape &circle, sf::RectangleShape &rectangle1,  sf::RectangleShape &rectangle2)
{
    if(circle.getPosition().y >= WINDOW_Y - 20 && m_y >= 0)  // Rebound on the bottom of the window
    {
        m_y = -1*m_y;
    }

    if(circle.getPosition().y <= 0 && m_y <= 0)      //Rebound on the top of the window
    {
        m_y = -1*m_y;
    }

    if(circle.getPosition().x >= WINDOW_X - 20) // Rebound on the right side on the window: Goal for player 1
    {
        goal(1);
    }

    if(circle.getPosition().x <= RECTANGLE1X - 5 ) // Rebound on the left side on the window: Goal for player 2
    {
        goal(2);
    }

    if(circle.getPosition().x <= RECTANGLE1X + rectangle1.getSize().x && // Rebound Player 1 curse
       circle.getPosition().y >= rectangle1.getPosition().y &&
       circle.getPosition().y <= rectangle1.getPosition().y + rectangle1.getSize().y)
      {
        if(m_x <= 0)
        {
            if(m_speed < 0.5)  //If the limit of the speed is not reach
            {
                m_speed = 1.1*m_speed;  //Increasing speed
            }
            m_x = m_speed;
        }
      }

    if(circle.getPosition().x >= RECTANGLE2X - rectangle2.getSize().x &&
       circle.getPosition().y >= rectangle2.getPosition().y &&         //Rebound Player 2 curse
       circle.getPosition().y <= rectangle2.getPosition().y + rectangle2.getSize().y)
    {
        if(m_x >= 0)
        {
            if(m_speed < 0.5) //If the limit of the speed is not reach
            {
                m_speed = 1.1*m_speed;  //Increasing speed
            }
            m_x = -1 * m_speed;
        }
    }

    circle.setPosition(circle.getPosition().x + m_x, circle.getPosition().y + m_y); //Moving of the ball
}
void Versus::goal(int player)                              // Goal
{
    m_speed = 0.05; //Reseting speed

    if(player == 1)         //Goal player 1
    {
        m_goalPlayer1 = m_goalPlayer1 +1;
        score(1);

        //Reseting speed of the ball
        m_x = m_speed;
        m_y = m_speed;
    }
    else        //Goal player 2
    {
        m_goalPlayer2 = m_goalPlayer2 +1;
        score(2);

        //Reseting speed of the ball
        m_x = -1* m_speed;
        m_y = -1* m_speed;
    }
    waitGoal = true;

    m_ball.setPosition(sf::Vector2f(400, 300));  //Replace the ball at the middle
}
void Versus::score(int player)
{
    if(player == 1)  //Goal for player 1
    {
        switch(m_goalPlayer1)
        {
        case 1:
            m_texturePlayer1.loadFromFile("ressource/score/1.png");
            m_spritePlayer1.setTexture(m_texturePlayer1);
            break;
        case 2:
            m_texturePlayer1.loadFromFile("ressource/score/2.png");
            break;
        case 3:
            m_texturePlayer1.loadFromFile("ressource/score/3.png");
            break;
        case 4:
            m_texturePlayer1.loadFromFile("ressource/score/4.png");
            break;
        case 5:
            win(1);  //Win for player 1
            break;
        }
    }
    else  //Goal for Player 2
    {
        switch(m_goalPlayer2)
        {
        case 1:
            m_texturePlayer2.loadFromFile("ressource/score/1.png");
            m_spritePlayer2.setTexture(m_texturePlayer2);
            break;
        case 2:
            m_texturePlayer2.loadFromFile("ressource/score/2.png");
            break;
        case 3:
            m_texturePlayer2.loadFromFile("ressource/score/3.png");
            break;
        case 4:
            m_texturePlayer2.loadFromFile("ressource/score/4.png");
            break;
        case 5:
            win(2); //Win for player 2
            break;
        }
    }
}
void Versus::win(int player)
{
    if (player == 1) //If player 1 win
    {
        m_textureWin.loadFromFile("ressource/Player1.png");
    }
    else  //If player 2 win
    {
        m_textureWin.loadFromFile("ressource/Player2.png");
    }
    end = 1;

}
void Versus::replay(sf::RenderWindow &window)
{
    if(sf::Mouse::getPosition(window).x >= 192 && sf::Mouse::getPosition(window).x <= 350 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
       sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If yes
       {
            end = 0; //The game restart
       }

    else if(sf::Mouse::getPosition(window).x >= 395 && sf::Mouse::getPosition(window).x <= 554 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
       sf::Mouse::isButtonPressed(sf::Mouse::Left)) //if no
       {
            end = 3; //Return to main menu
       }

    //Reset score
    m_goalPlayer1 = 0, m_goalPlayer2 = 0;
    m_spritePlayer1.setTexture(m_textureNull);
    m_spritePlayer2.setTexture(m_textureNull);
}
Versus::Versus() //Constructor
{
     //Initialization of curse, score and ball
    this->initRectangle(m_rectangle1, sf::Vector2f(RECTANGLE1X, 250));
    this->initRectangle(m_rectangle2, sf::Vector2f(RECTANGLE2X, 250));
    this->initCircle(m_ball);
    this->initScore(m_textureNull);

    //Initialize variable for sleep time after a goal
    waitGoal = false;

    //Set position of the 2 curse and also their texture
    m_spritePlayer1.setTexture(m_textureNull);
    m_spritePlayer1.setPosition(100 ,70);
    m_spritePlayer2.setPosition(650 ,70);
    m_spritePlayer2.setTexture(m_textureNull);

    //Initialize texture for asked to replay
    m_textureReplay.loadFromFile("ressource/Replay.png");
    m_spriteReplay.setTexture(m_textureReplay);

    //Initialize Text of win
    m_spriteWin.setTexture(m_textureWin);
    m_spriteWin.setPosition(100, 300);

    //Var
        // Set sensibility of curses
        m_sensi1 = 3;
        m_sensi2 = 3;

        //Initialize score
        m_goalPlayer1 = 0, m_goalPlayer2 = 0;

        //Initialize speed
        m_speed = 0.05;
        m_x = m_speed, m_y = m_speed;

        //Set var of state of play
        end = 0;
}
Versus::~Versus()//Destructor
{

}
