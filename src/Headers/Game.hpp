#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.hpp"

class Game
{
    private:
    sf::RenderWindow window;
    sf::Font font;
    Grid& grid;
    void handle_events();
    void update();
    void draw();

    public:
    Game(Grid& i_grid);
    void run();
};
