#include "Solo.h"

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
            //goal(circle, 1);
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
            //goal(circle, 2);
        }
        if(ia == 0)
        {
        /*    m_y = -1*m_speed;
            m_x = -1*m_speed;*/
            end = 1;
        }
     /*   else
        {
            m_y = -1*m_speed;
            m_x = -1*m_speed;
        }*/
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
        m_x = -1 * m_speed;
    }
    circle.setPosition(circle.getPosition().x + m_x, circle.getPosition().y + m_y);
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
    }
    if(end == 1)
        replay(window);
}
void Solo::draw(sf::RenderWindow &window)
{
    if(end == 0)                    // Si partie n'est pas fini
    {
      /*  window.draw(m_spritePlayer1);
        window.draw(m_spritePlayer2);*/
        if(ia == 0)
            window.draw(m_text);
        window.draw(m_rectangle1);
        if (ia == 1)
            window.draw(m_rectangle2);
        window.draw(m_ball);
    }
    if (end == 1)                   // Si partie est fini
    {
        if(afficherScore == 0)
        {
            m_text.setPosition(540, 300);
            window.draw(m_text);
            window.draw(m_textWin);
            window.display();
            sf::sleep(sf::seconds(2));
            afficherScore = 1;
            m_text.setPosition(300, 70);
        }
        window.draw(m_spriteReplay);
        /*window.display();
        sf::sleep(sf::seconds(0.7));
        end = 2;*/
    }
}
void Solo::replay(sf::RenderWindow &window)
{

    if(sf::Mouse::getPosition(window).x >= 192 && sf::Mouse::getPosition(window).x <= 350 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
    sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        end = 0;
        debut = 1;
        m_speed = -0.5;
        afficherScore = 0;
        m_ball.setPosition(400, 300);
    }

    if(sf::Mouse::getPosition(window).x >= 395 && sf::Mouse::getPosition(window).x <= 554 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
       sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        end = 2;
    }

}
Solo::Solo()
{
    //ctor
    this->initRectangle(m_rectangle1, sf::Vector2f(RECTANGLE1X, 50));
    this->initCircle(m_ball);
    m_textureReplay.loadFromFile("ressource/Replay.png");
    m_spriteReplay.setTexture(m_textureReplay);
    font.loadFromFile("arial.ttf");
    m_text.setFont(font);
    m_text.setColor(sf::Color::White);
    m_text.setPosition(300, 70);
    m_textWin.setFont(font);
    m_textWin.setColor(sf::Color::White);
    m_textWin.setPosition(300, 300);
    m_x = m_y = m_speed = -0.5;
}

Solo::~Solo()
{
    //dtor
}
