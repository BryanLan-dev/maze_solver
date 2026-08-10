#include <stack>
#include <SFML/Graphics.hpp>
#include "Headers/Cell.hpp"
#include "Headers/RandomManager.hpp"
#include "Headers/Grid.hpp"



//Constructor to initialize the grid with a reference to the RandomManager instance
Grid::Grid(RandomManager& i_random_manager):
    random_manager(i_random_manager)
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
        
        if(current_cell->get_x() > 0 && !cells[current_cell->get_y()][current_cell->get_x() - 1].get_visited())
        {
            unvisited_neighbors.push_back(&cells[current_cell->get_y()][current_cell->get_x() - 1]);
        }


        if(current_cell->get_x() < width - 1 && !cells[current_cell->get_y()][current_cell->get_x() + 1].get_visited())
        {
            unvisited_neighbors.push_back(&cells[current_cell->get_y()][current_cell->get_x() + 1]);
        }


        if(current_cell->get_y() > 0 && !cells[current_cell->get_y() - 1][current_cell->get_x()].get_visited())
        {
        unvisited_neighbors.push_back(&cells[current_cell->get_y() - 1][current_cell->get_x()]);
        }


        if(current_cell->get_y() < height - 1 && !cells[current_cell->get_y() + 1][current_cell->get_x()].get_visited())
        {
            unvisited_neighbors.push_back(&cells[current_cell->get_y() + 1][current_cell->get_x()]);
        }


       /* if(!unvisited_neighbors.empty())
        {
        
        }
        */
    }

}