#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "square.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "My Program");
    window.setFramerateLimit(60);
    sf::Clock clock;
    float lastTime = 0;
    srand(time(NULL));
    
    int square_size = 20;
    const int NUM_SQUARES = 100;
    Square squares[NUM_SQUARES];
    
    for (int i=0; i < NUM_SQUARES; i++)
    {
        squares[i] = Square(square_size, rand() % (1280 - square_size), rand() % (720 - square_size));
        int r = rand() % 100;
        if (r < 33)
            squares[i].xbounce();
        else if (r > 66)
            squares[i].ybounce();
    }


    while (window.isOpen())
    {
        float currentTime = clock.restart().asSeconds();
        float fps = 1.f / (currentTime - lastTime);
        lastTime = currentTime;
        std::cout << fps << std::endl;

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }
        //"physics"
        for (int i=0; i < NUM_SQUARES; i++)
        {
            if (squares[i].getPosition().x < 0 || squares[i].getPosition().x+square_size > 1280)
            {
                squares[i].xbounce();
                squares[i].setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
            }
            if (squares[i].getPosition().y < 0 || squares[i].getPosition().y+square_size > 720) 
            {
                squares[i].ybounce();
                squares[i].setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
            }
        

            squares[i].move();
        }

        //render
        window.clear();

        for (int i=0; i < NUM_SQUARES; i++)
            window.draw(squares[i].getBody());

        window.display();
    }

    return 0;
}