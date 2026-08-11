#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.hpp"
#include "RandomManager.hpp"
#include <vector>


class Grid{
    //2D vector to hold the cells of the grid
    std::vector<std::vector<Cell>> cells;
    
    //Width and height of the grid
    static constexpr unsigned short width = 20;
    static constexpr unsigned short height = 20;

    
    //Reference to the RandomManager instance for generating random numbers
    RandomManager& random_manager;
    
    //Sprite and texture for rendering the cells
    sf::Sprite cell_sprite;
	sf::Texture cell_texture;

    public:
    Grid(RandomManager& i_random_manager);
    void generate();
    void draw(sf::RenderWindow& i_window);
};