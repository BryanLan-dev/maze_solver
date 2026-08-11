#include <stack>
#include <SFML/Graphics.hpp>
#include "Headers/Cell.hpp"
#include "Headers/RandomManager.hpp"
#include "Headers/Grid.hpp"
#include <queue>
#include <vector>


//Constructor to initialize the grid with a reference to the RandomManager instance
Grid::Grid(RandomManager& i_random_manager):
    random_manager(i_random_manager),
    cell_sprite(cell_texture)
{
    for(unsigned short y =0; y < height; ++y)
    {
        std::vector<Cell> row;
        for(unsigned short x = 0; x < width; ++x)
        {
            row.emplace_back(x, y);
        }
        cells.push_back(row);
    }
}

//Generate the maze using a depth-first search algorithm
void Grid::generate()
{
    //Stack to hold the path of the maze generation
    std::stack<Cell*> path;

    cells[0][0].set_visited(true);

    path.push(&cells[0][0]);
    
    //While there are still cells in the path stack, continue generating the maze
    while (!path.empty())
    {
        Cell* current_cell = path.top();

        std::vector<Cell*> unvisited_neighbors;
        
        //Check if the current cell has a neighbor to the left that has not been visited
        if(current_cell->get_x() > 0 && !cells[current_cell->get_y()][current_cell->get_x() - 1].get_visited())
        {
            unvisited_neighbors.push_back(&cells[current_cell->get_y()][current_cell->get_x() - 1]);
        }

        //Check if the current cell has a neighbor to the right that has not been visited
        if(current_cell->get_x() < width - 1 && !cells[current_cell->get_y()][current_cell->get_x() + 1].get_visited())
        {
            //If the current cell has a neighbor to the right that has not been visited, add it to the list of unvisited neighbors
            unvisited_neighbors.push_back(&cells[current_cell->get_y()][current_cell->get_x() + 1]);
        }

        //Check if the current cell has a neighbor above it that has not been visited
        if(current_cell->get_y() > 0 && !cells[current_cell->get_y() - 1][current_cell->get_x()].get_visited())
        {
            //If the current cell has a neighbor above it that has not been visited, add it to the list of unvisited neighbors
            unvisited_neighbors.push_back(&cells[current_cell->get_y() - 1][current_cell->get_x()]);
        }


        //Check if the current cell has a neighbor below it that has not been visited
        if(current_cell->get_y() < height - 1 && !cells[current_cell->get_y() + 1][current_cell->get_x()].get_visited())
        {
            //If the current cell has a neighbor below it that has not been visited, add it to the list of unvisited neighbors
            unvisited_neighbors.push_back(&cells[current_cell->get_y() + 1][current_cell->get_x()]);
        }


        //If there are no unvisited neighbors, backtrack by popping the current cell off the path stack
        if(unvisited_neighbors.empty())
        {
            path.pop();
        }

        else
        {
            //Select a random unvisited neighbor from the list of unvisited neighbors
            Cell* next_cell = unvisited_neighbors[static_cast<unsigned short>(random_manager.get_random(static_cast<unsigned>(unvisited_neighbors.size() - 1), (static_cast<unsigned>(0))))];

            //Remove the wall between the current cell and the next cell based on their relative positions
            if(next_cell->get_x() == current_cell->get_x())
            {
                //If the next cell is in the same column as the current cell, we check if it's above or below the current cell
                if(next_cell->get_y() < current_cell->get_y())
                {   
                    //If the next cell is above the current cell, remove the top wall of the current cell and the bottom wall of the next cell
                    current_cell->set_wall_top(false);
                    next_cell->set_wall_bottom(false);
                }

                else
                {
                    //If the next cell is below the current cell, remove the bottom wall of the current cell and the top wall of the next cell
                    current_cell->set_wall_bottom(false);
                    next_cell->set_wall_top(false);
                }
            }
            else
            {
                //If the next cell is not in the same column as the current cell, it must be in the same row, so we check if it's to the left or right of the current cell
                if(next_cell->get_x() < current_cell->get_x())
                {
                    //If the next cell is to the left of the current cell, remove the left wall of the current cell and the right wall of the next cell
                    current_cell->set_wall_left(false);
                    next_cell->set_wall_right(false);
                }

                else
                {
                    //If the next cell is to the right of the current cell, remove the right wall of the current cell and the left wall of the next cell
                    current_cell->set_wall_right(false);
                    next_cell->set_wall_left(false);
                }
            }

            //Mark the next cell as visited and push it onto the path stack
            next_cell->set_visited(true);
            path.push(next_cell);    
        }
        
    }
}
    
//Draw the grid and its cells onto the provided SFML window
void Grid::draw(sf::RenderWindow& i_window)
{
    //Define the size of each cell in pixels
    const unsigned short cell_size = 25;

    //Iterate through each cell in the grid and draw its walls based on their existence
    for (unsigned short y = 0; y < height; ++y)
    {
        //Iterate through each cell in the current row
        for (unsigned short x = 0; x < width; ++x)
        {
        
            if (cells[y][x].get_wall_top())
            {
                //Draw the top wall of the cell if it exists
                sf::RectangleShape wall(sf::Vector2f(cell_size, 2));
                wall.setPosition(sf::Vector2f(x * cell_size, y * cell_size));                
                wall.setFillColor(sf::Color::Blue);
                i_window.draw(wall);
            }

            if (cells[y][x].get_wall_bottom())
            {
                //Draw the bottom wall of the cell if it exists
                sf::RectangleShape wall(sf::Vector2f(cell_size, 2));
                wall.setPosition(sf::Vector2f(x * cell_size, (y + 1) * cell_size - 2));
                wall.setFillColor(sf::Color::Blue);
                i_window.draw(wall);
            }

            if (cells[y][x].get_wall_left())
            {
                //Draw the left wall of the cell if it exists
                sf::RectangleShape wall(sf::Vector2f(2, cell_size));
                wall.setPosition(sf::Vector2f(x * cell_size, y * cell_size));
                wall.setFillColor(sf::Color::Blue);
                i_window.draw(wall);
            }

            if (cells[y][x].get_wall_right())
            {
                //Draw the right wall of the cell if it exists
                sf::RectangleShape wall(sf::Vector2f(2, cell_size));
                wall.setPosition(sf::Vector2f((x + 1) * cell_size - 2, y * cell_size));
                wall.setFillColor(sf::Color::Blue);
                i_window.draw(wall);
            }
        }
    }
}


void Grid::solve()
{
    std::queue<Cell*> path;
    std::vector<std::vector<Cell*>> parent(height, std::vector<Cell*>(width, nullptr));


    for(unsigned short y = 0; y < height; ++y)
    {
        for (unsigned short x = 0; x < width; ++x)
        {
            cells[y][x].set_visited(false);
        }
    }

    cells[0][0].set_visited(true);
    path.push(&cells[0][0]);

    while(!path.empty())
    {
        Cell* current_cell = path.front();
        path.pop();

        if(current_cell->get_x() == width - 1 && current_cell->get_y() == height - 1)
        {
            while(current_cell != nullptr)
            {
                current_cell->set_color(sf::Color::Red);
                current_cell = parent[current_cell->get_y()][current_cell->get_x()];
            }
            return;
        }

        std::vector<Cell*> neighbors;
        

        if(current_cell->get_y() > 0 && !current_cell->get_wall_top() && !cells[current_cell->get_y() - 1][current_cell->get_x()].get_visited())
        {
            neighbors.push_back(&cells[current_cell->get_y() - 1][current_cell->get_x()]);
        }

        if(current_cell->get_y() < height - 1 && !current_cell->get_wall_bottom() && !cells[current_cell->get_y() + 1][current_cell->get_x()].get_visited())
        {
            neighbors.push_back(&cells[current_cell->get_y() + 1][current_cell->get_x()]);
        }

        if(current_cell->get_x() > 0 && !current_cell->get_wall_left() && !cells[current_cell->get_y()][current_cell->get_x() - 1].get_visited())
        {
            neighbors.push_back(&cells[current_cell->get_y()][current_cell->get_x() - 1]);
        }

        if(current_cell->get_x() < width - 1 && !current_cell->get_wall_right() && !cells[current_cell->get_y()][current_cell->get_x() + 1].get_visited())
        {
            neighbors.push_back(&cells[current_cell->get_y()][current_cell->get_x() + 1]);
        }

        for(Cell* neighbor : neighbors)
        {
            neighbor->set_visited(true);
            parent[neighbor->get_y()][neighbor->get_x()] = current_cell;
            path.push(neighbor);
        }
    }

}