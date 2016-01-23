#include "../include/Solo.h"

void Solo::initRectangle(sf::RectangleShape &rectangle, sf::Vector2f position)
{
    rectangle.setPosition(position.x, position.y);
    rectangle.setSize(sf::Vector2f(20, 150));
}
void Solo::initCircle (sf::CircleShape &circle) // Ball
{
    circle.setRadius(10);
    circle.setPosition(sf::Vector2f(400, 300));
}

void Solo::setIa(bool pIA)
{
    ia = pIA;

    if(ia)
        initRectangle(m_rectangle2, sf::Vector2f(RECTANGLE2X, 400)); //Init the AI curse
    else
        m_clock.restart(); //Restart clock of timer in survival mod
}

void Solo::setSensi(int pSensi)
{
    m_sensi = pSensi;
}

void Solo::moveRectangle(sf::RectangleShape &rectangle, int direction)
{

    if(direction == 1 && rectangle.getPosition().y >=0 ) // Up
        rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y - (0.1 *m_sensi));

    if(direction == 2 && rectangle.getPosition().y <= WINDOW_Y - 148) // Down
        rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y + (0.1 * m_sensi));
}
void Solo::IA()
{
    if(m_x <= 0)    //If the ball goes to Player 1
    {
        //Centre the curse at the middle of the window
        if(m_rectangle2.getPosition().y + (m_rectangle2.getSize().y/2) >= WINDOW_Y/2)
        {
            moveRectangle(m_rectangle2, 1);     //Move up
        }
        else if(m_rectangle2.getPosition().y + (m_rectangle2.getSize().y/2) <= WINDOW_Y/2)
        {
            moveRectangle(m_rectangle2, 2);     //Move down
        }
    }
    else if(m_ball.getPosition().x >= WINDOW_X/2 && m_x >= 0 ) //If the ball goes to IA
    {
        if(m_y < 0 && m_rectangle2.getPosition().y >= m_ball.getPosition().y) //If ball move up
        {
            moveRectangle(m_rectangle2, 1);              //Curse move up
        }
        else if(m_y >0 && m_rectangle2.getPosition().y <= WINDOW_Y - 148 &&
        m_rectangle2.getPosition().y <= m_ball.getPosition().y) //If ball move down
        {
            moveRectangle(m_rectangle2, 2);                          //Curse move down
        }
    }
}

void Solo::moveBall(sf::CircleShape &circle, sf::RectangleShape &rectangle1,  sf::RectangleShape &rectangle2)
{
    if(circle.getPosition().y >= WINDOW_Y - 20 && m_y >= 0)  // Rebound on the bottom of the window
    {
        m_y = -1*m_y;
    }
    if(circle.getPosition().y <= 0 && m_y <= 0)      //Rebound on the top of the window
    {
        m_y = -1*m_y;
    }

    if(circle.getPosition().x >= WINDOW_X - 20)    // Rebound on the right side of the window
    {
        if(ia == 1)                 //If IA mod: Goal for player
        {
            goal(1);
        }
        else if(m_x > 0)            //If Survival mod changing direction of the ball
        {
            m_x = -1*m_x;
        }
    }
    if(circle.getPosition().x <= 0 ) // Rebound on the left side of the window
    {
        if(ia == true)                 //If IA mod: goal for IA
        {
            goal(2);
        }
        else                 //If survival mod: Player lost -> end of the game
        {
            end = 1;
        }
    }
        //TODO: Probleme de collision avec les rectangles normal
    if(circle.getPosition().x <= RECTANGLE1X + rectangle1.getSize().x &&
       circle.getPosition().x >= RECTANGLE1X &&
       circle.getPosition().y >= rectangle1.getPosition().y &&          // Rebound curse 1
       circle.getPosition().y <= rectangle1.getPosition().y + rectangle1.getSize().y)
      {
        if(m_speed < 2 && m_x <= 0)
        {
            m_speed = 1.1*m_speed;
            m_x = m_speed;
        }
      }
    if(ia == 1 &&   //Rebound curse 2 if IA mod
       circle.getPosition().x >= RECTANGLE2X - rectangle2.getSize().x &&
       circle.getPosition().x <= RECTANGLE2X &&
       circle.getPosition().y >= rectangle2.getPosition().y &&
       circle.getPosition().y <= rectangle2.getPosition().y + rectangle2.getSize().y)
    {
        if(m_speed < 2 && m_x >= 0)
        {
            m_speed = 1.1*m_speed;
            m_x = -1 * m_speed;
        }
    }

    circle.setPosition(circle.getPosition().x + m_x, circle.getPosition().y + m_y);  //Moving of the ball
}
void Solo::goal(int player)                              // Goal
{
    if(player == 1)         //If goal for player 1
    {
        m_goalPlayer1 = m_goalPlayer1 +1;
        score(1);
    }
    if (player == 2)        //If goal for player 1
    {
        m_goalPlayer2 = m_goalPlayer2 +1;
        score(2);
    }
    waitGoal = true;    //Set a sleep time
    m_ball.setPosition(sf::Vector2f(400, 300)); //Replace the ball at the middle
    m_speed = 0.05; //Reset speed
     //TODO: Mettre limite de vitesse
}
void Solo::score(int player)
{
    if(player == 1) //Goal for player
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
    else //Goal for IA
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
            win(2);  //Win for IA
            break;
        }
    }
}
void Solo::survie()
{
    m_time = m_clock.getElapsedTime();  //Get the time  to the timer

    if((float)m_time.asMilliseconds()/1000 >= 10)
    {
        stream.precision(4);              //Increase significant digit for have 2 decimal
    }
    stream << (float)m_time.asMilliseconds()/1000;   //Store the time in a flow

    m_textTime.setString(stream.str());    //Set the time in a string

    stream.str(""); //Clear the flow

    if(m_timeSpeed < (int)m_time.asSeconds() && m_speed < 2)
    {
        m_timeSpeed = (int)m_time.asSeconds();      //The speed increase every second

        m_speed =  m_speed * (1 + m_time.asSeconds()/500);

        printf("%f", m_speed);
        //Update speed in vertical axis and horizontal axis
        if(m_x < 0)
        {
            m_x = -1 * m_speed;
        }
        else
            m_x = m_speed;

        if(m_y < 0)
        {
             m_y = -1 * m_speed;
        }
        else
            m_y = m_speed;
    }
}
bool Solo::update(sf::Event &event, sf::RenderWindow &window)
{
    if(end == 0) //If the game is not finish
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            moveRectangle(m_rectangle1, 1);     //Move  Player 1 rectangle's to the top
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            moveRectangle(m_rectangle1, 2);     //Move  Player 1 rectangle's to the bot
        }
        moveBall(m_ball, m_rectangle1, m_rectangle2); // Move of the ball

        if(ia == false)            //IF no IA get the time
        {
            survie();
        }
        else                    //If IA has been choosen
        {
            IA();
        }
    }
    if(end == 1)        // If the  game is finished asked if player want to replay
        replay(window);

    if(end == 2)        //If the player don't want to replay
    {
        sf::sleep(sf::milliseconds(150));
        return true;
    }


    return false;
}
void Solo::draw(sf::RenderWindow &window)
{
    if(end == 0)                    // If the game is not finished
    {
        window.draw(m_rectangle1);
        window.draw(m_ball);

        if(ia == false)            //If survival mod
        {
            window.draw(m_textTime);
        }
        else                        //If versus mod
        {
            window.draw(m_spritePlayer1);
            window.draw(m_spritePlayer2);
            window.draw(m_rectangle2);
        }
    }
    if (end == 1)                   // If the game is finished
    {
        if(afficherScore == 0 && ia == false)   //Survival mod
        {
            m_textTime.setPosition(540, 300);

            window.draw(m_textTime);
            window.draw(m_textWin);

            window.display();

            sf::sleep(sf::seconds(1));
            afficherScore = 1;
            m_textTime.setPosition(300, 70);
        }

        if(ia == false)                     //IA mod
            window.draw(m_spriteWin);

        window.draw(m_spriteReplay);        //Picture for replay
    }
}

void Solo::win(int player)
{
    if (player == 1)        //If player 1 win
    {
        m_textureWin.loadFromFile("ressource/Player1.png");
    }
    else       //If player 2 win
    {
        m_textureWin.loadFromFile("ressource/Player2.png");
    }
    end = 1;
}
void Solo::replay(sf::RenderWindow &window)
{

    if(sf::Mouse::getPosition(window).x >= 192 && sf::Mouse::getPosition(window).x <= 350 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
    sf::Mouse::isButtonPressed(sf::Mouse::Left)) //Yes
    {
        end = 0; //The game restart
    }

    if(sf::Mouse::getPosition(window).x >= 395 && sf::Mouse::getPosition(window).x <= 554 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
       sf::Mouse::isButtonPressed(sf::Mouse::Left)) //No
    {
        end = 2;        //Return to main menu reseting the solo mod
        ia = false;
    }

    //Reseting all value
    m_goalPlayer1 = 0;
    m_goalPlayer2 = 0;
    m_spritePlayer1.setTexture(m_textureNull);
    m_spritePlayer2.setTexture(m_textureNull);
    m_clock.restart();
}

Solo::Solo()    //Constructor
{
    //Init Curse of player and the ball
    this->initRectangle(m_rectangle1, sf::Vector2f(RECTANGLE1X, 250));
    this->initCircle(m_ball);

    //Initialisation variable for a sleep time after a goal
    waitGoal = false;

    //Set the picture of replay
    m_textureReplay.loadFromFile("ressource/Replay.png");
    m_spriteReplay.setTexture(m_textureReplay);

    font.loadFromFile("arial.ttf"); //Initialization Font

    //Initialization of time text in survival
    m_textTime.setFont(font);
    m_textTime.setColor(sf::Color::White);
    m_textTime.setPosition(300, 70);

    //Initialization of TextWin in survival mod which draw the score
    m_textWin.setFont(font);
    m_textWin.setColor(sf::Color::White);
    m_textWin.setPosition(300, 300);
    m_textWin.setString("Your score is");

    m_x = m_y = m_speed = 0.05;              //Initialization speed

    m_textureNull.loadFromFile("ressource/score/0.png");    //Initialization score to 0

    //Set position score of player 1
    m_spritePlayer1.setTexture(m_textureNull);
    m_spritePlayer1.setPosition(100 ,70);
    m_goalPlayer1 = 0;

    //Set position score of player 2
    m_spritePlayer2.setPosition(650 ,70);
    m_spritePlayer2.setTexture(m_textureNull);
    m_goalPlayer2 = 0;

    //Set texture and position for draw the winner in IA mod
    m_spriteWin.setTexture(m_textureWin);
    m_spriteWin.setPosition(100, 300);

    m_clock.restart();  //Start timer for solo mod
    m_timeSpeed = 0; //Initialize variable wherein stored seconds wherein the speed increase in survival mod
    stream.precision(3);        //Number of significant digit
}

Solo::~Solo()
{
    //Destructor
}
