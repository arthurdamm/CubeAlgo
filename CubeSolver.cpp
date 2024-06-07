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

// Implement the solve method
void CubeSolver::solve() {
    // Add your code here
}

// Implement the reset method
void CubeSolver::reset() {
    // Add your code here
}

// Implement the isSolved method
bool CubeSolver::isSolved() {
    
    for (size_t x = 0; x < N; x++) {
        for (size_t y = 0; y < N; y++) {
            for (size_t z = 0; z < N; z++) {
                if (!AreQuatsEqual(cubeAlgo->cubes[x][y][z].orientation, cubeAlgo->cubes[0][0][0].orientation)) {
                    return false;
                }
            }
        }
    }

    return true;
}