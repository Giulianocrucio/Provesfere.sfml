#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
public:
    Game();
    void run();
private:

    void ProcessEvents();
    void update();
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void spostamentoverde();
private:
    sf::RenderWindow myWindow;
    sf::CircleShape tipo1;
    sf::CircleShape tipo2;
    sf::CircleShape tipo3;
    bool movingLeft, movingUp, movingRight, movingDown, a = true , y = true , x = true;
    sf::Clock clock;

};


Game::Game() : myWindow(sf::VideoMode(1024, 768), "SFML Game"), tipo1()
{
    tipo1.setRadius(40.f);
    tipo1.setFillColor(sf::Color::Red);
    tipo1.setPosition(100,100);
    tipo2.setRadius(30.f);
    tipo2.setFillColor(sf::Color::Green);
    tipo2.setPosition(510, 384);
    tipo3.setRadius(20.f);
    tipo3.setFillColor(sf::Color::Blue);
    tipo3.setPosition(610, 0);
}

void Game::run()
{
    while (myWindow.isOpen())
    {
        ProcessEvents();
        update();
        render();

    }
}

void Game::ProcessEvents()
{    
    sf::Event event;
    while (myWindow.pollEvent(event))
    {   

        switch (event.type)
        {
        case sf::Event::KeyPressed: handlePlayerInput(event.key.code, true); break;
        case sf::Event::KeyReleased: handlePlayerInput(event.key.code, false); break;
        case sf::Event::Closed: myWindow.close(); break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W) movingUp = isPressed;
    else if (key == sf::Keyboard::S) movingDown = isPressed;
    else if (key == sf::Keyboard::A) movingLeft = isPressed;
    else if (key == sf::Keyboard::D) movingRight = isPressed;
}
void Game::update()
{
    sf::Vector2f movement(0.f, 0.f);
    if (movingUp && tipo1.getPosition().y>0 ) movement.y -= 1E-1f;
    if (movingDown && tipo1.getPosition().y < 688) movement.y += 1E-1f;
    if (movingLeft && tipo1.getPosition().x > 0) movement.x -= 1E-1f;
    if (movingRight && tipo1.getPosition().x < 944) movement.x += 1E-1f;

    tipo1.move(movement);
    sf::Time time = clock.getElapsedTime();
    if( time.asMicroseconds() > 5000) spostamentoverde();
    
}
void Game::spostamentoverde()
{
    if (tipo2.getPosition().x == 964.0) a = false;
    if (tipo2.getPosition().x == 0.0) a = true;
    if (a == true) tipo2.move(1, 0);
    if (a == false) tipo2.move(-1, 0);

    if (tipo3.getPosition().x == 984.0) x = false;
    if (tipo3.getPosition().x == 0.0) x = true;
    if (tipo3.getPosition().y == 728.0) y = false;
    if (tipo3.getPosition().y == 0.0) y = true;
    if (x == true) tipo3.move(2, 0);
    if (x == false) tipo3.move(-2, 0);
    if (y == true) tipo3.move(0, 2);
    if (y == false) tipo3.move(0, -2);


    clock.restart();

}
void Game::render()
{
    myWindow.clear();
    myWindow.draw(tipo3);
    myWindow.draw(tipo2);
    myWindow.draw(tipo1);
    myWindow.display();
}

int main()
{   
    sf::Clock clock;
    Game game;
    game.run();

    return 0;
}