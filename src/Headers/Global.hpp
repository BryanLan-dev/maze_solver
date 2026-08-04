#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <vector>

//Global constants and shared types used across the whole project
namespace gbl
{
	//Constants related to individual maze cells
	namespace Cell
	{
		//Pixel size of a single cell when drawn
		constexpr unsigned char SIZE = 4;

		//Colors used to represent a cell's state (unvisited, generation path, final maze path, etc.)
		namespace COLORS
		{
			const sf::Color GENERATION_PATH(0, 146, 255);
			const sf::Color DEFAULT(36, 36, 85);
			const sf::Color MAZE_PATH(255, 255, 255);
		}
	}

	//Constants related to the overall maze grid/map
	namespace MAP
	{
		//We're showing 4 mazes. This is the margin around them.
		constexpr unsigned char BORDER_OFFSET = 2;
		//How many times we run the algorithm per frame.
		constexpr unsigned char STEPS_PER_FRAME = 16;

		//Number of columns and rows in the maze grid
		constexpr unsigned short COLUMNS = 79;
		constexpr unsigned short ROWS = 40;
	}

	//Constants related to the window/screen and frame timing
	namespace SCREEN
	{
		//Scale factor applied to the window size
		constexpr unsigned char RESIZE = 2;

		constexpr unsigned short HEIGHT = 360;
		constexpr unsigned short WIDTH = 640;

		//1 Second / 60 Frames = 16.667 ms per frame
		constexpr std::chrono::microseconds FRAME_DURATION(16667);
	}

	//Reusable alias for a 2D grid of any type (e.g. Vector2D<Cell> for the maze grid)
	template <typename i_value_type>
	using Vector2D = std::vector<std::vector<i_value_type>>;
}