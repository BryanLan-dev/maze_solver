#include <chrono>
#include <random>
#include <stack>
#include <SFML/Graphics.hpp>

#include "Headers/Cell.hpp"
#include "Headers/Global.hpp"
#include "Headers/RandomManager.hpp"
#include "Headers/Grid.hpp"
#include "Headers/Game.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

}