#include "TestCubeSolver.h"

bool FCubeSolverTestBasic::RunTest(const FString& Parameters)
{
    CubeSolver cubeSolver;

    cubeSolver.solve();
    cubeSolver.reset();
    cubeSolver.isSolved();

    return true;
}