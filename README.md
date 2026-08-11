<img width="800" height="600" alt="image" src="https://github.com/user-attachments/assets/29edf785-56c2-4926-bd0a-62bd131ea450" />
<img width="800" height="600" alt="image" src="https://github.com/user-attachments/assets/7de8ddbd-cbd2-43f6-a6f3-65e2dbea3585" />
<img width="800" height="600" alt="image" src="https://github.com/user-attachments/assets/6271e34f-4a40-4337-9f30-3174ea5a2d16" />


# Maze Solver

An interactive C++ maze generator and solver built with SFML 3. The program procedurally generates a 20x20 maze using recursive backtracking, solves it with breadth-first search (BFS) to find the shortest path, and renders both live in a window — press **Space** to generate and solve a brand-new maze at any time.

## Features

- **Maze generation** — recursive backtracking (DFS-based) carves a solvable maze by knocking down walls between cells, using a custom `RandomManager` for randomness.
- **Maze solving** — BFS finds the shortest path from the top-left corner to the bottom-right corner, respecting walls, and highlights the solved path in red.
- **Interactive** — press **Space** to instantly regenerate and re-solve a new maze.
- **Rendering** — SFML 3 draws the maze walls, solved path, and a "Maze Solved" message directly to a window.

## Controls

| Key | Action |
|---|---|
| `Space` | Generate and solve a new maze |
| Close button | Exit |

## Project Structure

| File | Responsibility |
|---|---|
| `Cell` | A single maze cell — tracks its own walls (top/bottom/left/right), position, visited state, and display color. |
| `RandomManager` | Wraps a `std::mt19937_64` engine with overloaded `get_random(max, min)` methods for every numeric type. |
| `Grid` | Owns the 2D collection of `Cell`s. Handles maze generation (`generate()`), solving (`solve()`), and rendering (`draw()`). |
| `DrawText` | Standalone helper function for rendering centered/positioned text with SFML's `Font`/`Text` API. |
| `Game` | Owns the SFML window and font, runs the main loop (`run()`, `handle_events()`, `update()`, `draw()`), and handles the spacebar input. |
| `main` | Wires everything together: constructs `RandomManager`, `Grid`, generates and solves the initial maze, then runs `Game`. |

## How It Works

### Generation
Starting from `(0,0)`, the algorithm resets every cell (walls back up, unvisited) and uses an explicit stack to perform depth-first traversal: at each cell it checks all unvisited neighbors, randomly picks one, knocks down the wall between them, and pushes forward. When a cell has no unvisited neighbors, it backtracks by popping the stack — continuing until every cell has been visited. This reset means generation can safely run again on demand (e.g. spacebar).

### Solving
BFS starts from `(0,0)` and explores the maze layer by layer using a queue, tracking each visited cell's parent. Once the bottom-right corner is reached, the solved path is reconstructed by walking backward through the parent chain and coloring each cell along the way.

## Built With

- C++
- [SFML 3](https://www.sfml-dev.org/) — window/graphics rendering
- MSYS2 UCRT64 (Windows build environment)

## Status

Complete. Core pipeline — maze generation, BFS solving, rendering, and spacebar-triggered regeneration — all working end-to-end. Possible future additions: multiple simultaneous mazes, randomized start/end points, animated step-by-step generation/solving visualization.
