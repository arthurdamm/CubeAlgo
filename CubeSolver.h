#pragma once

#include "CubeAlgorithm.h"
#include "CubeHash.h"
#include "CoreMinimal.h"
#include <queue>


/**
 * CubeSolver class declaration
 */
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

    std::vector<CubeGrid> generateNextStates(const CubeGrid &cubeGrid);
};
