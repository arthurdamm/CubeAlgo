#pragma once

#include "CubeAlgorithm.h"
#include "CubeHash.h"
#include "CoreMinimal.h"
#include <queue>


enum Direction {
    CLOCKWISE,
    COUNTERCLOCKWISE
};

struct CubeMove {
    int layer;
    Direction direction;

    CubeMove(int l, Direction d) : layer(l), direction(d) {}
};

struct SolutionState
{
    CubeGrid cubeGrid;
    std::vector<CubeMove> moves;
};

class CubeSolver
{
private:
    CubeAlgorithm* cubeAlgo = nullptr;

public:
    // Constructor
    CubeSolver();
    CubeSolver(CubeAlgorithm* cubeAlgo);

    // Destructor
    ~CubeSolver();

    // Solves the cube
    void solve();

    // Resets the cube to its initial state
    void reset();

    // Checks if the cube is solved
    bool isSolved(const CubeGrid &cubeGrid);
    bool isSolved();

    std::vector<SolutionState> generateNextStates(SolutionState& solutionState);
};
