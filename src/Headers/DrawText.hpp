#pragma once
#include <SFML/Graphics.hpp>
#include <string>

void draw_text(const bool& i_center_x, const bool& i_center_y, const short& i_x, const short& i_y,
                const std::string& i_text, sf::RenderWindow& i_window,
                const sf::Font& i_font, const sf::Color& i_color = sf::Color(255, 255, 255));