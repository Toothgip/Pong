#include "Solo.h"

void Solo::initRectangle(sf::RectangleShape &rectangle, sf::Vector2f position)
{
    rectangle.setPosition(position.x, position.y);
    rectangle.setSize(sf::Vector2f(20, 120));
}
void Solo::initCircle (sf::CircleShape &circle) // Balle
{
    circle.setRadius(10);
    circle.setPosition(sf::Vector2f(240, 400));
}
void Solo::moveRectangle(sf::RectangleShape &rectangle, int direction)
{
    sensi = 5;                              //Stockage dans une variable
    if(direction == 1 && rectangle.getPosition().y >=0 ) // Monter
        rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y - sensi);

    if(direction == 2 && rectangle.getPosition().y <= WINDOW_Y - 118) // Descendre
        rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y + sensi);
}
void Solo::IA()
{
    if(m_rectangle2.getPosition().y >= 0 && m_rectangle2.getPosition().y >= m_ball.getPosition().y) //Si balle montez
        moveRectangle(m_rectangle2, 1);              //Rectangle monte
    else if(m_rectangle2.getPosition().y <= WINDOW_Y - 118 && m_rectangle2.getPosition().y <= m_ball.getPosition().y) //Si balle descends
        moveRectangle(m_rectangle2, 2);                          //Rectangle descend
}
void Solo::moveBall(sf::CircleShape &circle, sf::RectangleShape &rectangle1,  sf::RectangleShape &rectangle2)
{
    if(circle.getPosition().y >= WINDOW_Y - 20)  // Rebond sur bas de la fenetre but ia
        if(m_speed <= 0)
		{
            m_y = m_speed;
		}
        else
            m_y = -1*m_speed;

    if(circle.getPosition().y <= 0)      //Rebond sur le haut de la fênetre but joueur
	{
        if (m_speed <= 0)
            m_y = -1*m_speed;
        else
		{
            m_y = m_speed;
		}
	}
    if(circle.getPosition().x >= WINDOW_X - 20)    // Rebond sur coté droit de la fenetre
    {
        if(ia == 1)                 //Si contre IA rebond coté droit But du player 1
        {
			goal(1);
        }
		if(m_speed < 9 && ia == 0)
			m_speed = 1.4*m_speed;
			
        if(m_speed <= 0)
        {
            m_y = -1*m_speed;
            m_x = m_speed;
        }
        else
        {
            m_y = m_speed;
            m_x = -1*m_speed;
        }
    }
    if(circle.getPosition().x <= 0 ) // Rebond sur coté gauche de la fênetre
    {
        if(ia == 1)                 //Si contre IA rebond de coté gauche But IA
        {
			goal(2);
		    m_speed = 0.5;
			m_x = m_speed;
        }
        if(ia == 0)
        {
            play = 0;
        }
    }
    if(circle.getPosition().x <= rectangle1.getPosition().x + rectangle1.getSize().x && circle.getPosition().y >= rectangle1.getPosition().y &&   // Rebond rectangle 1
       circle.getPosition().y <= rectangle1.getPosition().y + rectangle1.getSize().y)
      {
        if(m_speed < 6 && ia == 1)
            m_speed = 1.2*m_speed;
			
		if(m_speed < 9 && ia == 0)
			m_speed = 1.4*m_speed;
			
        if (m_speed <= 0)
			m_x = -1.2*m_speed;
        else
            m_x = m_speed;
      }
    if(circle.getPosition().x >= rectangle2.getPosition().x - rectangle2.getSize().x && circle.getPosition().y >= rectangle2.getPosition().y && //Rebond rectangle 2 si IA
       circle.getPosition().y <= rectangle2.getPosition().y + rectangle2.getSize().y && ia == 1)
    {
        if(m_speed < 6)
        {
            m_speed = 1.2*m_speed;
        }
        if(m_speed > 0)
            m_x = -1.2 * m_speed;
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
    wait = 1;
    m_ball.setPosition(sf::Vector2f(240, 400));
    m_speed = 1;
	m_x = m_y = m_speed;
	
}
void Solo::score(int player)
{
    if(player == 1)
    {
        switch(m_goalPlayer1)
        {
        case 1:
            m_texturePlayer1.loadFromFile("Score/1.png");
            m_spritePlayer1.setTexture(m_texturePlayer1);
            break;
        case 2:
            m_texturePlayer1.loadFromFile("Score/2.png");
            m_spritePlayer1.setTexture(m_texturePlayer1);
            break;
        case 3:
            m_texturePlayer1.loadFromFile("Score/3.png");
            m_spritePlayer1.setTexture(m_texturePlayer1);
            break;
        case 4:
            m_texturePlayer1.loadFromFile("Score/4.png");
            m_spritePlayer1.setTexture(m_texturePlayer1);
            break;
        case 5:
            m_texturePlayer1.loadFromFile("Score/5.png");
            m_spritePlayer1.setTexture(m_texturePlayer1);
            break;
        }
    }
    if(player == 2)
    {
        switch(m_goalPlayer2)
        {
        case 1:
            m_texturePlayer2.loadFromFile("Score/1.png");
            m_spritePlayer2.setTexture(m_texturePlayer2);
            break;
        case 2:
            m_texturePlayer2.loadFromFile("Score/2.png");
            m_spritePlayer2.setTexture(m_texturePlayer2);
            break;
        case 3:
            m_texturePlayer2.loadFromFile("Score/3.png");
            m_spritePlayer2.setTexture(m_texturePlayer2);
            break;
        case 4:
            m_texturePlayer2.loadFromFile("Score/4.png");
            m_spritePlayer2.setTexture(m_texturePlayer2);
            break;
        case 5:
            m_texturePlayer2.loadFromFile("Score/5.png");
            m_spritePlayer2.setTexture(m_texturePlayer2);
            break;
        }
    }
    if(m_goalPlayer1 == 5)
    {
        //win(1);
		end = 1;
    }
    if(m_goalPlayer2 == 5)
    {
        //win(2);
		end = 1;
    }
}
void Solo::update(sf::Event &event, sf::RenderWindow &window)
{
    if(end == 0)
    {	//Player 1
        if (sf::Touch::isDown(0) && sf::Touch::getPosition(0).x < 240 && sf::Touch::getPosition(0).y < 400)
        {
            moveRectangle(m_rectangle1, 1);     //Deplacement Player 1 vers le haut
        }
        else if (sf::Touch::isDown(0) && sf::Touch::getPosition(0).x < 240 && sf::Touch::getPosition(0).y > 400)
        {
            moveRectangle(m_rectangle1, 2);     //Deplacement Player 1 vers le bas
        }
        moveBall(m_ball, m_rectangle1, m_rectangle2); // Deplacement de la balle
        if(ia == 1)
            IA();
    }
    //if(end == 1)
        //replay(window);
}
void Solo::draw(sf::RenderWindow &window)
{
    if(end == 0)                    // Si partie n'est pas fini
    {
        window.draw(m_rectangle1);
        if (ia == 1)
        {
            window.draw(m_spritePlayer1);
            window.draw(m_spritePlayer2);
            window.draw(m_rectangle2);
        }
        window.draw(m_ball);
    }
    /*if (end == 1)                   // Si partie est fini
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
    }*/
}
/*void Solo::win(int player)
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
        debut = 1;
        m_speed = -0.5;
        afficherScore = 0;
        m_ball.setPosition(400, 300);
    }

    if(sf::Mouse::getPosition(window).x >= 395 && sf::Mouse::getPosition(window).x <= 554 && sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 418 &&
       sf::Mouse::isButtonPressed(sf::Mouse::Left)) //Non
    {
        play = 0;
        end = 2;
        debut = 1;
        m_speed = -0.5;
        afficherScore = 0;
        m_ball.setPosition(400, 300);
        ia = 0;
    }

}*/
Solo::Solo()
{
    //ctor
    this->initRectangle(m_rectangle1, sf::Vector2f(RECTANGLE1X, 400));
    this->initCircle(m_ball);
	m_speed = 1;
    m_x = m_y = m_speed;
	
	m_texturePlayer1.loadFromFile("Score/0.png");
	m_texturePlayer2.loadFromFile("Score/0.png");
	m_spritePlayer1.setTexture(m_texturePlayer1);
	m_spritePlayer1.setPosition(70, 42);
	m_spritePlayer2.setTexture(m_texturePlayer2);
	m_spritePlayer1.setPosition(320, 42);
}
Solo::~Solo()
{
    //dtor
}