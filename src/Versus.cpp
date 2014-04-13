#include "..\include\Versus.h"

void Versus::initRectangle(sf::RectangleShape &rectangle, sf::Vector2f position)
{
    rectangle.setPosition(position.x, position.y);
    rectangle.setSize(sf::Vector2f(20, 150));
}
void Versus::initCircle (sf::CircleShape &circle) // Balle
{
    circle.setRadius(10);
    circle.setPosition(sf::Vector2f(400, 300));
}
void Versus::initScore (sf::Texture &texture)
{
    texture.loadFromFile("ressource/score/0.png"); // Sprite Score a 0
}
void Versus::moveRectangle(sf::RectangleShape &rectangle, int direction)
{
    if(direction == 1 && rectangle.getPosition().y >=0 ) // Monter
        rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y - 3);

    if(direction == 2 && rectangle.getPosition().y <= WINDOW_Y - 148) // Descendre
        rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y + 3);
}
void Versus::update(sf::Event &event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        moveRectangle(m_rectangle1, 1);     //Deplacement Player 1 vers le haut
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveRectangle(m_rectangle1, 2);     //Deplacement Player 1 vers le bas
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        moveRectangle(m_rectangle2, 1);     //Deplacement Player 2 vers le haut
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        moveRectangle(m_rectangle2, 2);     //Deplacement Player 1 vers le bas
    }
    moveBall(m_ball, m_rectangle1, m_rectangle2); // Deplacement de la balle
}
void Versus::draw(sf::RenderWindow &window)
{
    if(end == 0)                    // Si partie n'est pas fini
    {
        window.draw(m_spritePlayer1);
        window.draw(m_spritePlayer2);
        window.draw(m_rectangle1);
        window.draw(m_rectangle2);
        window.draw(m_ball);
    }
    if (end == 1)                   // Si partie est fini
    {
        window.draw(m_spriteWin);
        window.display();
        sf::sleep(sf::seconds(0.7));
        m_textureReplay.loadFromFile("ressource/Replay.png");
        m_spriteReplay.setTexture(m_textureReplay);
        end = 2;
    }
}
void Versus::moveBall(sf::CircleShape &circle, sf::RectangleShape &rectangle1,  sf::RectangleShape &rectangle2)
{
    if(circle.getPosition().y >= WINDOW_Y - 20)  // Rebond sur bas de la fenetre
        m_y = -1*m_speed;

    if(circle.getPosition().y <= 0)      //Rebond sur le haut de la fênetre;
        m_y = m_speed;

    if(circle.getPosition().x >= WINDOW_X - 20)    // Rebond sur coté droit de la fenetre But pour joueur 1
    {
        m_speed = 0.5;
        m_x = m_speed;
        m_y = m_speed;
        goal(circle, 1);
    }
    if(circle.getPosition().x <= 0 ) // Rebond sur coté gauche de la fênetre  But pou joueur 2
    {
        m_speed = 0.5;
        m_x = m_speed;
        m_y = m_speed;
        goal(circle, 2);
    }
    if(circle.getPosition().x <= RECTANGLE1X + rectangle1.getSize().x && circle.getPosition().y >= rectangle1.getPosition().y &&   // Rebond rectangle 1
       circle.getPosition().y <= rectangle1.getPosition().y + rectangle1.getSize().y)
      {
        if(m_speed < 4)
        {
        m_speed = 1.2*m_speed;
        }
         m_x = m_speed;
      }
    if(circle.getPosition().x >= RECTANGLE2X - rectangle2.getSize().x && circle.getPosition().y >= rectangle2.getPosition().y && //Rebond rectangle 2
       circle.getPosition().y <= rectangle2.getPosition().y + rectangle2.getSize().y)
    {
        if(m_speed < 4)
        {
         m_speed = 1.2*m_speed;
        }
        m_x = -1 * m_speed;
    }
    circle.setPosition(circle.getPosition().x + m_x, circle.getPosition().y + m_y);
}
void Versus::goal(sf::CircleShape &circle, int player)                              // But
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
    wait = 1;
    circle.setPosition(sf::Vector2f(400, 300));
}
void Versus::score(int player)
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
void Versus::win(int player)
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
void Versus::replay(int rejouer, sf::RenderWindow &window)
{                                       // Gestion des X                            Gestion des Y              BOUTON OUI
    if(sf::Mouse::getPosition(window).x >= 192 && sf::Mouse::getPosition(window).x <= 350 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
       sf::Mouse::isButtonPressed(sf::Mouse::Left))
       {
        rejouer = 1;
       }

    if(sf::Mouse::getPosition(window).x >= 395 && sf::Mouse::getPosition(window).x <= 554 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
       sf::Mouse::isButtonPressed(sf::Mouse::Left))
       {
            rejouer = 0;
       }

    if(rejouer == 1)
    {
        m_goalPlayer1 = 0, m_goalPlayer2 = 0;
        m_spritePlayer1.setTexture(m_textureNull);
        m_spritePlayer2.setTexture(m_textureNull);
        m_goalPlayer1 = m_goalPlayer2 = end = 0;
    }
    if(rejouer == 0)
    {
        window.close();
    }
}
Versus::Versus()
{
     //ctor
    this->initRectangle(m_rectangle1, sf::Vector2f(RECTANGLE1X, 50));
    this->initRectangle(m_rectangle2, sf::Vector2f(RECTANGLE2X, 400));
    this->initCircle(m_ball);
    this->initScore(m_textureNull);

    m_spritePlayer1.setTexture(m_textureNull);
    m_spritePlayer1.setPosition(100 ,70);
    m_spritePlayer2.setPosition(650 ,70);
    m_spritePlayer2.setTexture(m_textureNull);

    m_goalPlayer1 = 0, m_goalPlayer2 = 0;
    m_speed = 0.5;
    m_x = m_speed, m_y = m_speed;

}
Versus::~Versus()
{
    //dtor
}
