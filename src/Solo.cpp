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
void Solo::moveRectangle(sf::RectangleShape &rectangle, int direction)
{
    std::istringstream iss(sensiRec);           //Conversion de la sensibilitée entrer
    iss >> sensi;                               //Stockage dans une variable

    if(direction == 1 && rectangle.getPosition().y >=0 ) // Monter
        rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y - sensi);

    if(direction == 2 && rectangle.getPosition().y <= WINDOW_Y - 148) // Descendre
        rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y + sensi);
}
void Solo::IA()
{
    if(m_y < 0 && m_rectangle2.getPosition().y >= 0 && m_rectangle2.getPosition().y >= m_ball.getPosition().y) //Si balle montez
        moveRectangle(m_rectangle2, 1);              //Rectangle monte

    if(m_y >0 && m_rectangle2.getPosition().y <= WINDOW_Y - 148 && m_rectangle2.getPosition().y <= m_ball.getPosition().y) //Si balle descends
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
        if(ia == 1)                 //Si contre IA BUT de IA
        {
            m_speed = 0.5;
            goal(2);
        }
        if(ia == 0)
        {
            end = 1;
        }
    }
    if(circle.getPosition().x <= RECTANGLE1X + rectangle1.getSize().x && circle.getPosition().y >= rectangle1.getPosition().y &&   // Rebond rectangle 1
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
    if(circle.getPosition().x >= RECTANGLE2X - rectangle2.getSize().x && circle.getPosition().y >= rectangle2.getPosition().y && //Rebond rectangle 2 si IA
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
            m_texturePlayer1.loadFromFile("ressource/score/5.png");
            m_spritePlayer1.setTexture(m_texturePlayer1);
            break;
        }
    }
    if(player == 2)
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
            m_texturePlayer2.loadFromFile("ressource/score/5.png");
            m_spritePlayer2.setTexture(m_texturePlayer2);
            break;
        }
    }
    if(m_goalPlayer1 == 5)
    {
        win(1);
    }
    if(m_goalPlayer2 == 5)
    {
        win(2);
    }
}
void Solo::survie()
{
    ostringstream s;
    std::ostringstream stream;
    stream.precision(2);
    stream << m_time.asSeconds();
    std::string str = stream.str();
    temps = str;
    m_text.setString(temps);
    m_textWin.setString("Ton score est de");

}
void Solo::update(sf::Event &event, sf::RenderWindow &window)
{
    if(end == 0)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            moveRectangle(m_rectangle1, 1);     //Deplacement Player 1 vers le haut
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            moveRectangle(m_rectangle1, 2);     //Deplacement Player 1 vers le bas
        }
        moveBall(m_ball, m_rectangle1, m_rectangle2); // Deplacement de la balle
        if(debut == 1 && ia == 0)
        {
           m_clock.restart();
           debut = 0;
        }
        if(ia == 0 && end == 0)
        {
            m_time = m_clock.getElapsedTime();
            survie();
        }
        if(ia == 1)
            IA();
    }
    if(end == 1)        // If the  game is finished asked if player want to replay
        replay(window);

    if(end == 2)        //If the player don't want to replay
        return true;

    return false;
}
void Solo::draw(sf::RenderWindow &window)
{
    if(end == 0)                    // Si partie n'est pas fini
    {

        if(ia == 0)
            window.draw(m_text);
        window.draw(m_rectangle1);
        if (ia == 1)
        {
            window.draw(m_spritePlayer1);
            window.draw(m_spritePlayer2);
            window.draw(m_rectangle2);
        }
        window.draw(m_ball);
    }
    if (end == 1)                   // Si partie est fini
    {
        if(afficherScore == 0 && ia == 0)
        {
            m_text.setPosition(540, 300);
            window.draw(m_text);
            window.draw(m_textWin);
            window.display();
            sf::sleep(sf::seconds(2));
            afficherScore = 1;
            m_text.setPosition(300, 70);
        }
        if(ia == 1)
            window.draw(m_spriteWin);
        window.draw(m_spriteReplay);
    }
}
void Solo::win(int player)
{
    if (player == 1)
    {
        m_textureWin.loadFromFile("ressource/Player1.png");
    }
    if(player == 2)
    {
        m_textureWin.loadFromFile("ressource/Player2.png");
    }
    end = 1;
    m_spriteWin.setTexture(m_textureWin);
    m_spriteWin.setPosition(100, 300);

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
        play = 0;
        end = 2;
        ia = 0;
    }
        m_speed = -0.5;
        afficherScore = 0;
        m_ball.setPosition(400, 300);
        debut = 1;

}
Solo::Solo(bool pIa)
{
    //ctor
    this->initRectangle(m_rectangle1, sf::Vector2f(RECTANGLE1X, 50));
    this->initCircle(m_ball);

    //initialisation varaible
    ia = pIa
    waitGoal = false;
    sensi = 3;

    m_textureReplay.loadFromFile("ressource/Replay.png"); //Chargement de l'image replay
    m_spriteReplay.setTexture(m_textureReplay);

    font.loadFromFile("arial.ttf");
    m_text.setFont(font);
    m_text.setColor(sf::Color::White);
    m_text.setPosition(300, 70);
    m_textWin.setFont(font);
    m_textWin.setColor(sf::Color::White);
    m_textWin.setPosition(300, 300);
    m_x = m_y = m_speed = -0.5;
    m_textureNull.loadFromFile("ressource/score/0.png");
    m_spritePlayer1.setTexture(m_textureNull);
    m_spritePlayer1.setPosition(100 ,70);
    m_spritePlayer2.setPosition(650 ,70);
    m_spritePlayer2.setTexture(m_textureNull);
}

Solo::~Solo()
{
    //dtor
}
