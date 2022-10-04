#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "My Program");
    window.setFramerateLimit(60);
    
    sf::RectangleShape rect;

    sf::Vector2f rectanglePosition(600, 350);

    rect.setPosition(rectanglePosition);

    rect.setSize(sf::Vector2f(100, 100));

    float xVelocity = 3;
    float yVelocity = 3;
    srand(time(NULL));

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }
        //"physics"
        if (rectanglePosition.x < 0 || rectanglePosition.x+100 > 1280)
        {
            xVelocity *= -1;
            rect.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (rectanglePosition.y < 0 || rectanglePosition.y+100 > 720) 
        {
            yVelocity *= -1;
            rect.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        }

        rectanglePosition.x += xVelocity;
        rectanglePosition.y += yVelocity;
        rect.setPosition(rectanglePosition);

        //render
        window.clear();

        window.draw(rect);

        window.display();
    }

    return 0;
}