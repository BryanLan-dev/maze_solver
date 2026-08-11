#include <iostream>
#include "Headers/Game.hpp"

Game::Game(Grid& i_grid) :
    window(sf::VideoMode({800u, 600u}), "Maze Solver"),
    grid(i_grid)
{
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
    }
}

void Game::run()
{
    while (window.isOpen())
    {
        handle_events();
        update();
        window.clear(sf::Color::White);
        draw();
        window.display();
    }
}

void Game::draw()
{
    grid.draw(window);
}

void Game::handle_events()
{
    while (auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }

        if (const auto* key_event = event->getIf<sf::Event::KeyPressed>())
        {
            if (key_event->code == sf::Keyboard::Key::Space)
            {
                grid.generate();
                grid.solve();
            }
        }
    }
}

void Game::update()
{

}



