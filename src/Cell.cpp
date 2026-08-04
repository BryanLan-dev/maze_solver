#include <chrono>
#include <SFML/Graphics.hpp>

#include "Headers/Cell.hpp"
#include "Headers/Global.hpp"

//Calling Cell class form h file and asignning default values
Cell::Cell(unsigned short i_x, unsigned short i_y):
    
    visited(false),
    Wall_top(true),
    Wall_bottom(true),
    Wall_left(true),
    Wall_right(true),
    x(i_x),
    y(i_y),
    color(gbl::Cell::COLORS::DEFAULT)
    {

    }

//Return values of true or false for each cell(wall) visted depending on the direction
bool Cell::get_visited()const
{
    return visited;
}

bool Cell::get_wall_top()const
{
    return Wall_top;
}

bool Cell::get_wall_bottom()const
{
    return Wall_bottom;
}

bool Cell::get_wall_left()const
{
    return Wall_left;
}

bool Cell::get_wall_right()const
{
    return Wall_right;
}

//Set values of true or false for visited/each wall, and update the cell's color
void Cell::set_visited(const bool i_value)
{
    visited = i_value;
} 

void Cell::set_wall_top(const bool i_value)
{
    Wall_top = i_value;
} 

void Cell::set_wall_bottom(const bool i_value)
{
    Wall_bottom = i_value;
} 

void Cell::set_wall_left(const bool i_value)
{
    Wall_left = i_value;
} 

void Cell::set_wall_right(const bool i_value)
{
    Wall_right = i_value;
} 

void Cell::set_color(const sf::Color& i_value)
{
    color = i_value;
} 

//Return this cell's grid position (x, y) and its current display color
 unsigned short Cell::get_x() const
 {
    return x;
 }

 unsigned short Cell::get_y() const
 {
    return y;
 }

 sf::Color Cell::get_color() const
{
	return color;
}