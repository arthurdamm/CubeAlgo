#pragma once

#include "CubeAlgorithm.h"
#include "CoreMinimal.h"


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
    bool isSolved();
};
