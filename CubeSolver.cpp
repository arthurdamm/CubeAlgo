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

bool CubeSolver::solve(SolutionState& finalState) {
    std::queue<SolutionState> cubeGrids;

    SolutionState startState;
    startState.cubeGrid = this->cubeAlgo->grid;
    cubeGrids.push(startState);

    while (!cubeGrids.empty()) {
        SolutionState currentGrid = cubeGrids.front();
        cubeGrids.pop();

        if (isSolved(currentGrid.cubeGrid)) {
            // If it is, we've found a solution
            finalState = currentGrid;
            // UE_LOG(LogTemp, Display, TEXT("SOLVED!"));
            // printSolutionState(currentGrid);
            return true;
        }

        // Generate all possible next states from the current grid
        std::vector<SolutionState> nextStates = generateNextStates(currentGrid);

        // Add the next states to the queue
        for (SolutionState& nextState : nextStates) {
            cubeGrids.push(nextState);
        }
    }
    return false;
}

std::vector<SolutionState> CubeSolver::generateNextStates(SolutionState& currentState)
{
    std::vector<SolutionState> nextStates;
    for (size_t layer = 0; layer < LAYERS; layer++) {
        for (int direction = 0; direction < 2; direction++) {
            CubeAlgorithm nextCubeAlgo = CubeAlgorithm(currentState.cubeGrid);
            nextCubeAlgo.rotateLayer(layer, direction == 0 ? 1 : -1);
            
            SolutionState newState;
            newState.cubeGrid = nextCubeAlgo.grid;
            newState.moves = currentState.moves;
            newState.moves.push_back(CubeMove(layer, direction == 0 ? CLOCKWISE : COUNTERCLOCKWISE));
            nextStates.push_back(newState);
        }
    }
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

void printSolutionState(SolutionState solutionState) {
    UE_LOG(LogTemp, Warning, TEXT("Solution State: %s"), *solutionState.cubeGrid.ToString());
    for (CubeMove move : solutionState.moves) {
        UE_LOG(LogTemp, Warning, TEXT("Layer: %d, Direction: %d"), move.layer, move.direction);
    }
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