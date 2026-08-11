#include <SFML/Graphics.hpp>
#include "Headers/RandomManager.hpp"
#include "Headers/Grid.hpp"
#include "Headers/Game.hpp"

int main()
{
    RandomManager random_manager;
    Grid grid(random_manager);
    grid.generate();
    grid.solve();
    Game game(grid);
    game.run();

}