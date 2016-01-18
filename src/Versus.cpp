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

void Versus::setSensi(int pSensi1, int pSensi2)
{
    m_sensi1 = pSensi1;
    m_sensi2 = pSensi2;
}
void Versus::moveRectangle(sf::RectangleShape &rectangle, int direction, int player)
{
    if(player == 1)
    {
        if(direction == 1 && rectangle.getPosition().y >=0 ) // Monter
        {
            rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y - (0.1 * m_sensi2));
        }

        if(direction == 2 && rectangle.getPosition().y <= WINDOW_Y - 148) // Descendre
        {
            rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y + (0.1 * m_sensi2));
        }
    }
    else if(player == 2)
    {
        if(direction == 1 && rectangle.getPosition().y >=0 ) // Monter
        {
            rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y - (0.1 * m_sensi2));
        }

        if(direction == 2 && rectangle.getPosition().y <= WINDOW_Y - 148) // Descendre
        {
            rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y + (0.1 * m_sensi2));
        }
    }

}
bool Versus::update(sf::RenderWindow &window, sf::Event &event)
{
    if(end == 0)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            moveRectangle(m_rectangle1, 1, 1);     //Deplacement Player 1 vers le haut
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            moveRectangle(m_rectangle1, 2, 1);     //Deplacement Player 1 vers le bas
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            moveRectangle(m_rectangle2, 1, 2);     //Deplacement Player 2 vers le haut
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            moveRectangle(m_rectangle2, 2, 2);     //Deplacement Player 1 vers le bas
        }
        moveBall(m_ball, m_rectangle1, m_rectangle2); // Deplacement de la balle
    }
    else if (end == 2)
    {
        replay(window);
    }
    else if(end == 3)
    {
        sf::sleep(sf::milliseconds(150));
        return true;
    }
    return false;

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
    else if (end == 1)                   // If the game is finihed draw who has won
    {
        window.draw(m_spriteWin);
        window.display();
        sf::sleep(sf::seconds(0.7));

        end = 2;
    }
    else if (end == 2)
    {
        window.draw(m_spriteReplay);
    }

}
void Versus::moveBall(sf::CircleShape &circle, sf::RectangleShape &rectangle1,  sf::RectangleShape &rectangle2)
{
    if(circle.getPosition().y >= WINDOW_Y - 20)  // Rebond sur bas de la fenetre
        m_y = -1*m_speed;

    if(circle.getPosition().y <= 0)      //Rebond sur le haut de la fênetre
        m_y = m_speed;

    if(circle.getPosition().x >= WINDOW_X - 20)    // Rebond sur coté droit de la fenetre But pour joueur 1
    {
        m_speed = 0.05;
        m_x = m_speed;
        m_y = m_speed;
        goal(1);
    }
    if(circle.getPosition().x <= 0 ) // Rebond sur coté gauche de la fênetre  But pou joueur 2
    {
        m_speed = 0.05;
        m_x = -1* m_speed;
        m_y = -1* m_speed;
        goal(2);
    }
    if(circle.getPosition().x <= RECTANGLE1X + rectangle1.getSize().x &&
       circle.getPosition().y >= rectangle1.getPosition().y &&   // Rebond rectangle 1
       circle.getPosition().y <= rectangle1.getPosition().y + rectangle1.getSize().y)
      {
        if(m_speed < 4)
        {
        m_speed = 1.2*m_speed;
        }
         m_x = m_speed;
      }
    if(circle.getPosition().x >= RECTANGLE2X - rectangle2.getSize().x &&
       circle.getPosition().y >= rectangle2.getPosition().y && //Rebond rectangle 2
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
void Versus::goal(int player)                              // Goal
{
    if(player == 1)         //Goal player 1
    {
        m_goalPlayer1 = m_goalPlayer1 +1;
        score(1);
    }
    if (player == 2)        //Goal player 2
    {
        m_goalPlayer2 = m_goalPlayer2 +1;
        score(2);
    }
    waitGoal = true;
    m_ball.setPosition(sf::Vector2f(400, 300));
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
            break;
        case 3:
            m_texturePlayer1.loadFromFile("ressource/score/3.png");
            break;
        case 4:
            m_texturePlayer1.loadFromFile("ressource/score/4.png");
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
            break;
        case 3:
            m_texturePlayer2.loadFromFile("ressource/score/3.png");
            break;
        case 4:
            m_texturePlayer2.loadFromFile("ressource/score/4.png");
            break;
        case 5:
            win(2);
            break;
        }
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
void Versus::replay(sf::RenderWindow &window)
{
    if(sf::Mouse::getPosition(window).x >= 192 && sf::Mouse::getPosition(window).x <= 350 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
       sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If yes
       {
            end = 0;
       }

    if(sf::Mouse::getPosition(window).x >= 395 && sf::Mouse::getPosition(window).x <= 554 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
       sf::Mouse::isButtonPressed(sf::Mouse::Left)) //if no
       {
            end = 3;
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

    //Set position of the 2 curse and also their texture
    m_spritePlayer1.setTexture(m_textureNull);
    m_spritePlayer1.setPosition(100 ,70);
    m_spritePlayer2.setPosition(650 ,70);
    m_spritePlayer2.setTexture(m_textureNull);

    //Initailise texture for asked to replay
    m_textureReplay.loadFromFile("ressource/Replay.png");
    m_spriteReplay.setTexture(m_textureReplay);

    //Var
    m_sensi1 = 3; // Set sensibility
    m_sensi2 = 3;
    m_goalPlayer1 = 0, m_goalPlayer2 = 0;
    m_speed = 0.05;
    m_x = m_speed, m_y = m_speed;
    end = 0;
    waitGoal = false;
}
Versus::~Versus()
{
    //dtor
}
