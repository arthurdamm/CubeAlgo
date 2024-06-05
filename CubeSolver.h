#pragma once

#include "CoreMinimal.h"

/**
 * CubeSolver class declaration
 */
class CubeSolver
{
public:
    // Constructor
    CubeSolver();

    // Destructor
    ~CubeSolver();

    // Solves the cube
    void solve();

    // Resets the cube to its initial state
    void reset();

    // Checks if the cube is solved
    bool isSolved();
};
