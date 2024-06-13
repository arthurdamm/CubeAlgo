#include "TestCubeSolver.h"

bool FCubeSolverTestBasic::RunTest(const FString& Parameters)
{
    TestCubeSolver TestCubeSolver;

    TestCubeSolver.TestIsSolved(*this);
    TestCubeSolver.TestGenerateNextStates(*this);

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

bool TestCubeSolver::TestGenerateNextStates(FAutomationTestBase& Test)
{
    AActor* dummyActor = NewObject<AActor>();
    CubeAlgorithm cubeAlgo(dummyActor);
    CubeSolver cubeSolverDefault(&cubeAlgo);

    SolutionState startState;
    std::vector<SolutionState> nextStates = cubeSolverDefault.generateNextStates(startState);

    Test.TestEqual("GenerateNextStates Default", nextStates.size(), 18);

    // Rotate the cube
    cubeAlgo.rotateLayer(1, 1);

    // Generate next states after rotation
    std::vector<SolutionState> nextStatesAfterRotation = cubeSolverDefault.generateNextStates(startState);

    startState.cubeGrid = cubeAlgo.grid;
    Test.TestEqual("GenerateNextStates After Rotation",
    filter(nextStatesAfterRotation, [startState](SolutionState state) {
        UE_LOG(LogTemp, Warning, TEXT(">> %s"), *state.cubeGrid.ToString());
        return state.cubeGrid == startState.cubeGrid;
    }).size(), 1);

    return true;
}
