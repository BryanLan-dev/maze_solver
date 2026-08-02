# Maze Solver (C++ / SFML)

**Status: In Progress** 🚧

A maze generation and pathfinding visualizer built in C++ with SFML. This project is actively being developed — see below for what's working and what's next.

## What's Working

- 10x10 grid rendering using a `Cell` struct stored in a 1D vector
- Core pathfinding logic scaffolded:
  - Recursive backtracking (for maze generation)
  - Breadth-first search (BFS) (for pathfinding)
- Build pipeline configured via CMake, compiled with the MSYS2 UCRT64 toolchain

## What's Left

- Wire up recursive backtracking to actually generate maze walls on the grid
- Animate/visualize the BFS solve step-by-step
- Add start/end point selection
- Support grid sizes larger than 10x10
- Clean up build artifacts from version control

## Tech Stack

- **Language:** C++17
- **Graphics:** SFML
- **Build system:** CMake
- **Toolchain:** MSYS2 (UCRT64)

## Build & Run

```bash
mkdir build && cd build
cmake ..
cmake --build .
./maze_solver
```

*(Adjust the executable name/path if it differs on your system.)*

## Why This Project

Built to get hands-on with grid-based pathfinding algorithms and 2D graphics programming in C++, after working with Raylib on a previous project ([Ping Pong](https://github.com/BryanLan-dev/Ping-Pong)). This one dives deeper into algorithmic logic (BFS, backtracking) rather than real-time physics.

## Author

Bryan Landers — [GitHub](https://github.com/BryanLan-dev) | [LinkedIn](https://www.linkedin.com/in/bryan-landers-a5529b370)
