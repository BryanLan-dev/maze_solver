<img width="800" height="600" alt="image" src="https://github.com/user-attachments/assets/29edf785-56c2-4926-bd0a-62bd131ea450" />

# Maze Solver

A C++ maze generator and solver built with SFML 3. The program procedurally generates a 20x20 maze using recursive backtracking, then solves it with breadth-first search (BFS) to find and display the shortest path from start to end.

## Features

- **Maze generation** — recursive backtracking (DFS-based) carves a solvable maze by knocking down walls between cells, using a custom `RandomManager` for randomness.
- **Maze solving** — BFS finds the shortest path from the top-left corner to the bottom-right corner, respecting walls, and highlights the solved path.
- **Rendering** — SFML 3 draws the maze walls and solved path directly to a window.

## Project Structure

| File | Responsibility |
|---|---|
| `Cell` | A single maze cell — tracks its own walls (top/bottom/left/right), position, visited state, and display color. |
| `RandomManager` | Wraps a `std::mt19937_64` engine with overloaded `get_random(max, min)` methods for every numeric type. |
| `Grid` | Owns the 2D collection of `Cell`s. Handles maze generation (`generate()`), solving (`solve()`), and rendering (`draw()`). |
| `DrawText` | Standalone helper function for rendering centered/positioned text with SFML's `Font`/`Text` API. |
| `Game` | Owns the SFML window and font, runs the main loop (`run()`, `handle_events()`, `update()`, `draw()`). |
| `main` | Wires everything together: constructs `RandomManager`, `Grid`, generates and solves the maze, then runs `Game`. |

## How It Works

### Generation
Starting from `(0,0)`, the algorithm uses an explicit stack to perform depth-first traversal: at each cell it checks all unvisited neighbors, randomly picks one, knocks down the wall between them, and pushes forward. When a cell has no unvisited neighbors, it backtracks by popping the stack — continuing until every cell has been visited.

### Solving
BFS starts from `(0,0)` and explores the maze layer by layer using a queue, tracking each visited cell's parent. Once the bottom-right corner is reached, the solved path is reconstructed by walking backward through the parent chain and marking each cell along the way.

## Built With

- C++
- [SFML 3](https://www.sfml-dev.org/) — window/graphics rendering
- MSYS2 UCRT64 (Windows build environment)

## Status

Core pipeline complete: maze generation, BFS solving, and rendering all working end-to-end. Possible future additions: multiple simultaneous mazes, randomized start/end points, animated step-by-step generation/solving visualization.
