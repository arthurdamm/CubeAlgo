#include "CubeSolver.h"

// Implement the constructor
CubeSolver::CubeSolver() {
}

CubeSolver::CubeSolver(CubeAlgorithm* cubeAlgo) {
    this->cubeAlgo = cubeAlgo;
}

// Implement the destructor
CubeSolver::~CubeSolver() {
    // Add your code here
}

void CubeSolver::solve() {
    std::queue<SolutionState> cubeGrids;

    SolutionState startState;
    cubeGrids.push(startState);

    while (!cubeGrids.empty()) {
        SolutionState currentGrid = cubeGrids.front();
        cubeGrids.pop();

        if (isSolved(currentGrid.cubeGrid)) {
            // If it is, we've found a solution
            break;
        }

        // Generate all possible next states from the current grid
        std::vector<SolutionState> nextStates = generateNextStates(currentGrid.cubeGrid);

        // Add the next states to the queue
        for (SolutionState& nextState : nextStates) {
            cubeGrids.push(nextState);
        }
    }
}

std::vector<SolutionState> CubeSolver::generateNextStates(const CubeGrid &cubeGrid) {
    std::vector<SolutionState> nextStates;
    return nextStates;
}

// Implement the reset method
void CubeSolver::reset() {
    // Add your code here
}

// Implement the isSolved method
bool CubeSolver::isSolved(const CubeGrid &cubeGrid) {
    
    for (size_t x = 0; x < N; x++) {
        for (size_t y = 0; y < N; y++) {
            for (size_t z = 0; z < N; z++) {
                if (!AreQuatsEqual(cubeGrid.cubes[x][y][z].orientation, cubeGrid.cubes[0][0][0].orientation)) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool CubeSolver::isSolved() {
    return isSolved(this->cubeAlgo->grid);
    return false;
}

/*

CubeSolver gets a CubeAlgorithm object and solves it. The CubeAlgorithm object is a 3x3x3 cube with 6 faces. Each face has 9 stickers. The stickers are colored. The goal is to solve the cube by rotating the faces. The cube is solved when each face has the same color.

- isSoloved
    checks state of cubes
    if all orientation quats are equal

bfs memoization
    add current algo state to queue
    while queue
    pop rube, rotations
    for each layer
        rotate it
        is cube solved?
            if so return
        add to queue


how to store stat of rube?
    min # bits?
    27 cubes, each 6 states
        27 * 6 = 162 values
*/