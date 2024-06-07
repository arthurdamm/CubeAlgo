#include "TestCubeSolver.h"

bool FCubeSolverTestBasic::RunTest(const FString& Parameters)
{
    TestCubeSolver TestCubeSolver;

    TestCubeSolver.TestIsSolved(*this);

    return true;
}

bool TestCubeSolver::TestIsSolved(FAutomationTestBase& Test)
{
    AActor* dummyActor = NewObject<AActor>();
    CubeAlgorithm cubeAlgo(dummyActor);
    CubeSolver cubeSolverDefault(&cubeAlgo);

    Test.TestEqual("IsSolved Default", cubeSolverDefault.isSolved(), true);
    cubeAlgo.rotateLayer(8, 1);
    Test.TestEqual("IsSolved False", cubeSolverDefault.isSolved(), false);
    cubeAlgo.rotateLayer(8, -1);
    Test.TestEqual("IsSolved True", cubeSolverDefault.isSolved(), true);
    
    cubeAlgo.rotateLayer(3, 1);
    Test.TestEqual("IsSolved False Again", cubeSolverDefault.isSolved(), false);
    cubeAlgo.rotateLayer(3, 1);
    cubeAlgo.rotateLayer(3, 1);
    cubeAlgo.rotateLayer(3, 1);
    Test.TestEqual("IsSolved True Again", cubeSolverDefault.isSolved(), true);

    return true;
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