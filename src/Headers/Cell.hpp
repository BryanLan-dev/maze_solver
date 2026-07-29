#pragma once
#include <SFML/Graphics.hpp>


class Cell{
    
    bool visited;
    bool Wall_top;
    bool Wall_bottom;
    bool Wall_left;
    bool Wall_right;

    unsigned short x;
    unsigned short y;

    sf:: Color color;

    public:
    Cell(unsigned short i_x, unsigned short i_y);

    bool get_visited() const;
	bool get_wall_bottom() const;
	bool get_wall_left() const;
	bool get_wall_right() const;
	bool get_wall_top() const;

	unsigned short get_x() const;
	unsigned short get_y() const;


	void set_visited(const bool i_value);
	void set_color(const sf::Color& i_value);
	void set_wall_bottom(const bool i_value);
	void set_wall_left(const bool i_value);
	void set_wall_right(const bool i_value);
	void set_wall_top(const bool i_value);

	sf::Color get_color() const;
};