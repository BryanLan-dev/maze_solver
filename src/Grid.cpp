#include <stack>
#include <SFML/Graphics.hpp>
#include "Headers/Cell.hpp"
#include "Headers/RandomManager.hpp"
#include "Headers/Grid.hpp"



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