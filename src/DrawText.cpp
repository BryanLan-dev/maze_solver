#include <SFML/Graphics.hpp>
#include "Headers/DrawText.hpp"

void draw_text(const bool& i_center_x, const bool& i_center_y, const short& i_x, const short& i_y,
                const std::string& i_text, sf::RenderWindow& i_window,
                const sf::Font& i_font, const sf::Color& i_color)
{
    sf::Text text(i_font, i_text);
    text.setFillColor(i_color);

    float pos_x = i_x;
    float pos_y = i_y;

    if (i_center_x || i_center_y)
    {
        sf::FloatRect bounds = text.getLocalBounds();

        if (i_center_x)
        {
            pos_x = i_x - (bounds.size.x / 2.f + bounds.position.x);
        }
        if (i_center_y)
        {
            pos_y = i_y - (bounds.size.y / 2.f + bounds.position.y);
        }
    }

    text.setPosition(sf::Vector2f(pos_x, pos_y));
    i_window.draw(text);
}