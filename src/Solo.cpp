#include "../include/Solo.h"

void Solo::initRectangle(sf::RectangleShape &rectangle, sf::Vector2f position)
{
    rectangle.setPosition(position.x, position.y);
    rectangle.setSize(sf::Vector2f(20, 150));
}
void Solo::initCircle (sf::CircleShape &circle) // Balle
{
    circle.setRadius(10);
    circle.setPosition(sf::Vector2f(400, 300));
}

void Solo::setIa(bool pIA)
{
    ia = pIA;

    if(ia)
        initRectangle(m_rectangle2, sf::Vector2f(RECTANGLE2X, 400)); //Init the AI curse
}

void Solo::setSensi(int pSensi)
{
    m_sensi = pSensi;
}

void Solo::moveRectangle(sf::RectangleShape &rectangle, int direction)
{

    if(direction == 1 && rectangle.getPosition().y >=0 ) // Monter
        rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y - m_sensi);

    if(direction == 2 && rectangle.getPosition().y <= WINDOW_Y - 148) // Descendre
        rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y + m_sensi);
}
void Solo::IA()
{
    if(m_y < 0 && m_rectangle2.getPosition().y >= 0 && m_rectangle2.getPosition().y >= m_ball.getPosition().y) //Si balle montez
        moveRectangle(m_rectangle2, 1);              //Rectangle monte

    if(m_y >0 && m_rectangle2.getPosition().y <= WINDOW_Y - 148 &&
       m_rectangle2.getPosition().y <= m_ball.getPosition().y) //Si balle descends
        moveRectangle(m_rectangle2, 2);                          //Rectangle descend


}
void Solo::moveBall(sf::CircleShape &circle, sf::RectangleShape &rectangle1,  sf::RectangleShape &rectangle2)
{
    if(circle.getPosition().y >= WINDOW_Y - 20)  // Rebond sur bas de la fenetre
        if(m_speed <= 0)
            m_y = m_speed;
        else
            m_y = -1*m_speed;

    if(circle.getPosition().y <= 0)      //Rebond sur le haut de la fênetre;
        if (m_speed <= 0)
            m_y = -1*m_speed;
        else
            m_y = m_speed;

    if(circle.getPosition().x >= WINDOW_X - 20)    // Rebond sur coté droit de la fenetre
    {
        if(ia == 1)                 //Si contre IA BUT du joueur
        {
            m_speed = 0.5;
            goal(1);
        }
        if(m_speed <= 0)
        {
            m_y = m_speed;
            m_x = m_speed;
        }
        else
        {
            m_y = -1*m_speed;
            m_x = -1*m_speed;
        }
    }
    if(circle.getPosition().x <= 0 ) // Rebond sur coté gauche de la fênetre
    {
        if(ia == true)                 //Si contre IA BUT de IA
        {
            m_speed = 0.5;  //TODO: Mettre limite de vitesse
            goal(2);
        }
        if(ia == false)
        {
            end = 1;
        }
    }
    if(circle.getPosition().x <= RECTANGLE1X + rectangle1.getSize().x &&
       circle.getPosition().y >= rectangle1.getPosition().y &&   // Rebond rectangle 1
       circle.getPosition().y <= rectangle1.getPosition().y + rectangle1.getSize().y)
      {
        if(m_speed < 3)
        {
            m_speed = 1.2*m_speed;
        }
            if (m_speed <= 0)
                m_x = -1*m_speed;
            else
                m_x = m_speed;
      }
    if(circle.getPosition().x >= RECTANGLE2X - rectangle2.getSize().x &&
       circle.getPosition().y >= rectangle2.getPosition().y && //Rebond rectangle 2 si IA
       circle.getPosition().y <= rectangle2.getPosition().y + rectangle2.getSize().y && ia == 1)
    {
        if(m_speed < 4)
        {
            m_speed = 1.2*m_speed;
        }
        if(m_speed > 0)
            m_x = -1 * m_speed;
        else
            m_x = m_speed;
    }
    circle.setPosition(circle.getPosition().x + m_x, circle.getPosition().y + m_y);
}
void Solo::goal(int player)                              // But
{
    if(player == 1)         //But joueur 1
    {
        m_goalPlayer1 = m_goalPlayer1 +1;
        score(1);
    }
    if (player == 2)        //But joueur 2
    {
        m_goalPlayer2 = m_goalPlayer2 +1;
        score(2);
    }
    waitGoal = true;
    m_ball.setPosition(sf::Vector2f(400, 300));
    m_speed = -0.5;
}
void Solo::score(int player)
{
    if(player == 1)
    {
        switch(m_goalPlayer1)
        {
        case 1:
            m_texturePlayer1.loadFromFile("ressource/score/1.png");
            m_spritePlayer1.setTexture(m_texturePlayer1);
            break;
        case 2:
            m_texturePlayer1.loadFromFile("ressource/score/2.png");
            m_spritePlayer1.setTexture(m_texturePlayer1);
            break;
        case 3:
            m_texturePlayer1.loadFromFile("ressource/score/3.png");
            m_spritePlayer1.setTexture(m_texturePlayer1);
            break;
        case 4:
            m_texturePlayer1.loadFromFile("ressource/score/4.png");
            m_spritePlayer1.setTexture(m_texturePlayer1);
            break;
        case 5:
            win(1);
            break;
        }
    }
    else if(player == 2)
    {
        switch(m_goalPlayer2)
        {
        case 1:
            m_texturePlayer2.loadFromFile("ressource/score/1.png");
            m_spritePlayer2.setTexture(m_texturePlayer2);
            break;
        case 2:
            m_texturePlayer2.loadFromFile("ressource/score/2.png");
            m_spritePlayer2.setTexture(m_texturePlayer2);
            break;
        case 3:
            m_texturePlayer2.loadFromFile("ressource/score/3.png");
            m_spritePlayer2.setTexture(m_texturePlayer2);
            break;
        case 4:
            m_texturePlayer2.loadFromFile("ressource/score/4.png");
            m_spritePlayer2.setTexture(m_texturePlayer2);
            break;
        case 5:
            win(2);
            break;
        }
    }
}
void Solo::survie() //TODO: Modifier vitesse de la balle en fonction du temps
{
    ostringstream s;
    std::ostringstream stream;
    stream.precision(2);

    m_time = m_clock.getElapsedTime();  //Get the time  to the timer

    stream << m_time.asSeconds();   //Store the time in a flux  //TODO affiches les demi-secondes après 10s
    std::string str = stream.str(); //Conversion float to char
    temps = str;                    //Store the char in a string

    m_textTime.setString(temps);    //Set the time in a string

    m_textWin.setString("Ton score est de"); //Text when the game is finshed

}
bool Solo::update(sf::Event &event, sf::RenderWindow &window)
{   //TODO: Gere bug de la balle bloqué dans un angle
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
        if(ia == true)
            IA();
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
            window.draw(m_textTime);

        if (ia == true)             //If versus mod
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
    if(player == 2)         //If player 2 win
    {
        m_textureWin.loadFromFile("ressource/Player2.png");
    }
    end = 1;

}
void Solo::replay(sf::RenderWindow &window)
{

    if(sf::Mouse::getPosition(window).x >= 192 && sf::Mouse::getPosition(window).x <= 350 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
    sf::Mouse::isButtonPressed(sf::Mouse::Left)) //Oui
    {
        end = 0;
    }

    if(sf::Mouse::getPosition(window).x >= 395 && sf::Mouse::getPosition(window).x <= 554 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
       sf::Mouse::isButtonPressed(sf::Mouse::Left)) //Non
    {

        end = 2;
        ia = false;
    }
        m_speed = -0.5;
        m_ball.setPosition(400, 300);

}
Solo::Solo()
{
    //ctor
    this->initRectangle(m_rectangle1, sf::Vector2f(RECTANGLE1X, 250));
    this->initCircle(m_ball);

    //initialisation varaible
    waitGoal = false;

    m_textureReplay.loadFromFile("ressource/Replay.png"); //Chargement de l'image replay
    m_spriteReplay.setTexture(m_textureReplay);

    font.loadFromFile("arial.ttf"); //Initilization Font

    m_textTime.setFont(font);
    m_textTime.setColor(sf::Color::White);          //Initilization of time text in survival
    m_textTime.setPosition(300, 70);

    m_textWin.setFont(font);
    m_textWin.setColor(sf::Color::White);
    m_textWin.setPosition(300, 300);

    m_x = m_y = m_speed = -0.5;              //Initialization speed

    m_textureNull.loadFromFile("ressource/score/0.png");    //Initialization score to 0

    m_spritePlayer1.setTexture(m_textureNull);              //Set score of player 1
    m_spritePlayer1.setPosition(100 ,70);

    m_spritePlayer2.setPosition(650 ,70);                   //Set score of player 2
    m_spritePlayer2.setTexture(m_textureNull);

    m_spriteWin.setTexture(m_textureWin);       //Set texture for win and position
    m_spriteWin.setPosition(100, 300);

    m_clock.restart();  //Start timer for solo mod
}

Solo::~Solo()
{
    //dtor
}
