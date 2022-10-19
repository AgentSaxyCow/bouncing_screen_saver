#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Square {
    private:
        int xVelocity;
        int yVelocity;
        sf::Vector2f pos;
        sf::Color color;
        sf::Vector2f size;
        sf::RectangleShape body;
    public:
        Square()
        {
            srand(time(NULL));
            xVelocity = 3;
            yVelocity = 3;
            pos.x = rand() % (1280 - 100);
            pos.y = rand() % (720 - 100);
            color = sf::Color(255, 255, 255);
            size = sf::Vector2f(100, 100);

            body.setPosition(pos);
            body.setFillColor(color);
            body.setSize(size);
        }
        Square(int s, int x=0, int y=0)
        {
            xVelocity = 3;
            yVelocity = 3;
            pos.x = x;
            pos.y = y;
            color = sf::Color(255, 255, 255);
            size = sf::Vector2f(s, s);

            body.setPosition(pos);
            body.setFillColor(color);
            body.setSize(size);
        }
        sf::Vector2f getPosition()
        {
            return pos;
        }
        void setColor(sf::Color newColor)
        {
            color = newColor;
            body.setFillColor(color);
        }
        sf::RectangleShape getBody() {return body;}
        void move()
        {
            pos.x += xVelocity;
            pos.y += yVelocity;
            body.setPosition(pos);
        }
        void xbounce()
        {
            xVelocity *= -1;
        }
        void ybounce()
        {
            yVelocity *= -1;
        }
};

#endif