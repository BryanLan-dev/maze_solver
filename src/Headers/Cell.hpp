#pragma once
#include <SFML/Graphics.hpp>

//Made class cell to represent each cell(walls and visited) in the maze
class Cell{
    
	//Properties of the cell
    bool visited;
    bool Wall_top;
    bool Wall_bottom;
    bool Wall_left;
    bool Wall_right;

	//Position of the cell in the maze
    unsigned short x;
    unsigned short y;

	//Color of the cell
    sf:: Color color;

	//Constructor to initialize the cell with its position and default properties
    public:
    Cell(unsigned short i_x, unsigned short i_y);

	//Getters for the cell properties
    bool get_visited() const;
	bool get_wall_bottom() const;
	bool get_wall_left() const;
	bool get_wall_right() const;
	bool get_wall_top() const;

	//Getters for the position of the cell
	unsigned short get_x() const;
	unsigned short get_y() const;

	//Setters for the cell properties
	void set_visited(const bool i_value);
	void set_color(const sf::Color& i_value);
	void set_wall_bottom(const bool i_value);
	void set_wall_left(const bool i_value);
	void set_wall_right(const bool i_value);
	void set_wall_top(const bool i_value);

	//Getter for the color of the cell
	sf::Color get_color() const;
};