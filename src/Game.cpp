#include <iostream>
#include "Headers/Game.hpp"

Game::Game(Grid& i_grid) :
    window(sf::VideoMode({800u, 600u}), "Maze Solver"),
    grid(i_grid)
{
    if (!font.openFromFile("assets/arial.ttf"))
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
        window.clear();
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
    }
}

void Game::update()
{

}



