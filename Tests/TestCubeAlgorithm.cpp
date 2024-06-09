#include "TestCubeAlgorithm.h"

FString RotateLayer0ExpectedStr = R"(
<L:(0.00, 0.00, 0.00) F:(1.00, 0.00, 0.00) O:(-0.71, 0.00, 0.00, 0.71) R:(0.00, 0.00, 0.00) [0][0][0] ([0][2][0])>, <L:(1.00, 0.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][0][0] ([1][0][0])>, 
<L:(2.00, 0.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][0][0] ([2][0][0])>, <L:(0.00, 1.00, 0.00) F:(1.00, 0.00, 0.00) O:(-0.71, 0.00, 0.00, 0.71) R:(0.00, 0.00, 0.00) [0][1][0] ([0][2][1])>, 
<L:(1.00, 1.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][1][0] ([1][1][0])>, <L:(2.00, 1.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][1][0] ([2][1][0])>, 
<L:(0.00, 2.00, 0.00) F:(1.00, 0.00, 0.00) O:(-0.71, 0.00, 0.00, 0.71) R:(0.00, 0.00, 0.00) [0][2][0] ([0][2][2])>, <L:(1.00, 2.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][2][0] ([1][2][0])>, 
<L:(2.00, 2.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][2][0] ([2][2][0])>, <L:(0.00, 0.00, 1.00) F:(1.00, 0.00, 0.00) O:(-0.71, 0.00, 0.00, 0.71) R:(0.00, 0.00, 0.00) [0][0][1] ([0][1][0])>, 
<L:(1.00, 0.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][0][1] ([1][0][1])>, <L:(2.00, 0.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][0][1] ([2][0][1])>, 
<L:(0.00, 1.00, 1.00) F:(1.00, 0.00, 0.00) O:(-0.71, 0.00, 0.00, 0.71) R:(0.00, 0.00, 0.00) [0][1][1] ([0][1][1])>, <L:(1.00, 1.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][1][1] ([1][1][1])>, 
<L:(2.00, 1.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][1][1] ([2][1][1])>, <L:(0.00, 2.00, 1.00) F:(1.00, 0.00, 0.00) O:(-0.71, 0.00, 0.00, 0.71) R:(0.00, 0.00, 0.00) [0][2][1] ([0][1][2])>, 
<L:(1.00, 2.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][2][1] ([1][2][1])>, <L:(2.00, 2.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][2][1] ([2][2][1])>, 
<L:(0.00, 0.00, 2.00) F:(1.00, 0.00, 0.00) O:(-0.71, 0.00, 0.00, 0.71) R:(0.00, 0.00, 0.00) [0][0][2] ([0][0][0])>, <L:(1.00, 0.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][0][2] ([1][0][2])>, 
<L:(2.00, 0.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][0][2] ([2][0][2])>, <L:(0.00, 1.00, 2.00) F:(1.00, 0.00, 0.00) O:(-0.71, 0.00, 0.00, 0.71) R:(0.00, 0.00, 0.00) [0][1][2] ([0][0][1])>, 
<L:(1.00, 1.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][1][2] ([1][1][2])>, <L:(2.00, 1.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][1][2] ([2][1][2])>, 
<L:(0.00, 2.00, 2.00) F:(1.00, 0.00, 0.00) O:(-0.71, 0.00, 0.00, 0.71) R:(0.00, 0.00, 0.00) [0][2][2] ([0][0][2])>, <L:(1.00, 2.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][2][2] ([1][2][2])>, 
<L:(2.00, 2.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][2][2] ([2][2][2])>, )";

FString RotateLayer7ExpectedStr = R"(
<L:(0.00, 0.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][0][0] ([0][0][0])>, <L:(1.00, 0.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][0][0] ([1][0][0])>, 
<L:(2.00, 0.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][0][0] ([2][0][0])>, <L:(0.00, 1.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][1][0] ([0][1][0])>, 
<L:(1.00, 1.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][1][0] ([1][1][0])>, <L:(2.00, 1.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][1][0] ([2][1][0])>, 
<L:(0.00, 2.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][2][0] ([0][2][0])>, <L:(1.00, 2.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][2][0] ([1][2][0])>, 
<L:(2.00, 2.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][2][0] ([2][2][0])>, <L:(0.00, 0.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.71, 0.71) R:(0.00, 0.00, 0.00) [0][0][1] ([0][2][1])>, 
<L:(1.00, 0.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.71, 0.71) R:(0.00, 0.00, 0.00) [1][0][1] ([0][1][1])>, <L:(2.00, 0.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.71, 0.71) R:(0.00, 0.00, 0.00) [2][0][1] ([0][0][1])>, 
<L:(0.00, 1.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.71, 0.71) R:(0.00, 0.00, 0.00) [0][1][1] ([1][2][1])>, <L:(1.00, 1.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.71, 0.71) R:(0.00, 0.00, 0.00) [1][1][1] ([1][1][1])>, 
<L:(2.00, 1.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.71, 0.71) R:(0.00, 0.00, 0.00) [2][1][1] ([1][0][1])>, <L:(0.00, 2.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.71, 0.71) R:(0.00, 0.00, 0.00) [0][2][1] ([2][2][1])>, 
<L:(1.00, 2.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.71, 0.71) R:(0.00, 0.00, 0.00) [1][2][1] ([2][1][1])>, <L:(2.00, 2.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.71, 0.71) R:(0.00, 0.00, 0.00) [2][2][1] ([2][0][1])>, 
<L:(0.00, 0.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][0][2] ([0][0][2])>, <L:(1.00, 0.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][0][2] ([1][0][2])>, 
<L:(2.00, 0.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][0][2] ([2][0][2])>, <L:(0.00, 1.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][1][2] ([0][1][2])>, 
<L:(1.00, 1.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][1][2] ([1][1][2])>, <L:(2.00, 1.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][1][2] ([2][1][2])>, 
<L:(0.00, 2.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][2][2] ([0][2][2])>, <L:(1.00, 2.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][2][2] ([1][2][2])>, 
<L:(2.00, 2.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][2][2] ([2][2][2])>, )";

FString InitializeCubesExpectedStr = R"(
<L:(0.00, 0.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][0][0] ([0][0][0])>, <L:(1.00, 0.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][0][0] ([1][0][0])>, 
<L:(2.00, 0.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][0][0] ([2][0][0])>, <L:(0.00, 1.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][1][0] ([0][1][0])>, 
<L:(1.00, 1.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][1][0] ([1][1][0])>, <L:(2.00, 1.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][1][0] ([2][1][0])>, 
<L:(0.00, 2.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][2][0] ([0][2][0])>, <L:(1.00, 2.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][2][0] ([1][2][0])>, 
<L:(2.00, 2.00, 0.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][2][0] ([2][2][0])>, <L:(0.00, 0.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][0][1] ([0][0][1])>, 
<L:(1.00, 0.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][0][1] ([1][0][1])>, <L:(2.00, 0.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][0][1] ([2][0][1])>, 
<L:(0.00, 1.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][1][1] ([0][1][1])>, <L:(1.00, 1.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][1][1] ([1][1][1])>, 
<L:(2.00, 1.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][1][1] ([2][1][1])>, <L:(0.00, 2.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][2][1] ([0][2][1])>, 
<L:(1.00, 2.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][2][1] ([1][2][1])>, <L:(2.00, 2.00, 1.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][2][1] ([2][2][1])>, 
<L:(0.00, 0.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][0][2] ([0][0][2])>, <L:(1.00, 0.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][0][2] ([1][0][2])>, 
<L:(2.00, 0.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][0][2] ([2][0][2])>, <L:(0.00, 1.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][1][2] ([0][1][2])>, 
<L:(1.00, 1.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][1][2] ([1][1][2])>, <L:(2.00, 1.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][1][2] ([2][1][2])>, 
<L:(0.00, 2.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [0][2][2] ([0][2][2])>, <L:(1.00, 2.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [1][2][2] ([1][2][2])>, 
<L:(2.00, 2.00, 2.00) F:(1.00, 0.00, 0.00) O:(0.00, 0.00, 0.00, 1.00) R:(0.00, 0.00, 0.00) [2][2][2] ([2][2][2])>, )";


bool FCubeAlgorithmTestBasic::RunTest(const FString& Parameters)
{
    TestCubeAlgorithm TestCubeAlgorithm;
    TestCubeAlgorithm.TestInitializeCubes(*this);
    return true;
}


void TestCubeAlgorithm::TestInitializeCubes(FAutomationTestBase& Test)
{
    // Initialize the CubeAlgorithm
    AActor* DummyActor = NewObject<AActor>();
    CubeAlgorithm Algo(DummyActor);

    // Call initializeCubes method
    Algo.initializeCubes();

    // Check if the actual result matches the expected result
    FString ActualResult = Algo.ToStringNormalized();
    Test.TestEqual(TEXT("Cube Initialization"), ActualResult, InitializeCubesExpectedStr);
}


bool FCubeAlgorithmTestRotation::RunTest(const FString& Parameters)
{
    TestCubeAlgorithm TestCubeAlgorithm;

    TestCubeAlgorithm.TestToString(*this);
    TestCubeAlgorithm.TestToStringNormalized(*this);
    TestCubeAlgorithm.TestRotateLayer0(*this);
    TestCubeAlgorithm.TestRotateLayer7(*this);
    TestCubeAlgorithm.TestGetRotationAxisForLayer(*this);
    TestCubeAlgorithm.TestGetCenterForLayer(*this);
    TestCubeAlgorithm.TestLayerRotations(*this);
    TestCubeAlgorithm.TestEqualLocal(*this);

    return true;
}

void TestCubeAlgorithm::TestToString(FAutomationTestBase& Test)
{
    // Initialize the CubeAlgorithm
    AActor* DummyActor = NewObject<AActor>();
    CubeAlgorithm Algo(DummyActor);

    // Check if the actual result matches the expected result
    bool ActualResult = Algo.ToString().Len() > 0;
    bool ExpectedResult = true;
    Test.TestEqual(TEXT("Cube ToString"), ActualResult, ExpectedResult);
}

void TestCubeAlgorithm::TestToStringNormalized(FAutomationTestBase& Test)
{
    // Initialize the CubeAlgorithm
    AActor* DummyActor = NewObject<AActor>();
    CubeAlgorithm Algo(DummyActor);

    // Check if the actual result matches the expected result
    bool ActualResult = Algo.ToStringNormalized().Len() > 0;
    bool ExpectedResult = true;
    Test.TestEqual(TEXT("Cube ToStringNormalized"), ActualResult, ExpectedResult);
}

void TestCubeAlgorithm::TestRotateLayer0(FAutomationTestBase& Test)
{
    // Initialize the CubeAlgorithm
    AActor* DummyActor = NewObject<AActor>();
    CubeAlgorithm Algo(DummyActor);

    // Perform a rotation on layer 1
    Algo.rotateLayer(0, 1);

    // Check if the actual result matches the expected result
    FString ActualResult = Algo.ToStringNormalized();
    Test.TestEqual(TEXT("Cube Layer 0 Rotation"), ActualResult, RotateLayer0ExpectedStr);
}

void TestCubeAlgorithm::TestRotateLayer7(FAutomationTestBase& Test)
{
    // Initialize the CubeAlgorithm
    AActor* DummyActor = NewObject<AActor>();
    CubeAlgorithm Algo(DummyActor);

    // Perform a rotation on layer 7
    Algo.rotateLayer(7, 1);

    // Check if the actual result matches the expected result
    FString ActualResult = Algo.ToStringNormalized();
    Test.TestEqual(TEXT("Cube Layer 7 Rotation"), ActualResult, RotateLayer7ExpectedStr);
}


void TestCubeAlgorithm::TestGetRotationAxisForLayer(FAutomationTestBase& Test)
{
    // Initialize the CubeAlgorithm
    AActor* DummyActor = NewObject<AActor>();
    CubeAlgorithm Algo(DummyActor);

    // Get the rotation axis for layer 1
    FVector ActualResult = Algo.getRotationAxisForLayer(1);
    FVector GetRotationAxisForLayerExpectedResult = FVector(-1, 0, 0);

    // Check if the actual result matches the expected result
    Test.TestEqual(TEXT("Rotation Axis for Layer 1"), ActualResult, GetRotationAxisForLayerExpectedResult);
}

void TestCubeAlgorithm::TestGetCenterForLayer(FAutomationTestBase& Test)
{
    // Initialize the CubeAlgorithm
    AActor* DummyActor = NewObject<AActor>();
    CubeAlgorithm Algo(DummyActor);

    // Get the center for layer 1
    FVector ActualResult = Algo.getCenterForLayer(1);
    FVector GetCenterForLayerExpectedResult = FVector(1, 1, 1);

    // Check if the actual result matches the expected result
    Test.TestEqual(TEXT("Center for Layer 1"), ActualResult, GetCenterForLayerExpectedResult);
}

void TestCubeAlgorithm::TestLayerRotations(FAutomationTestBase& Test)
{
    // Initialize the CubeAlgorithm
    AActor* DummyActor = NewObject<AActor>();
    CubeAlgorithm Algo(DummyActor);
    CubeAlgorithm AlgoCompare(DummyActor);

    // Loop through the N layers
    for (int layer = 0; layer < N*N; layer++)
    {
        // Rotate the layer in one direction
        Algo.rotateLayer(layer, 1);

        // Rotate the layer three times in the opposite direction
        AlgoCompare.rotateLayer(layer, -1);
        AlgoCompare.rotateLayer(layer, -1);
        AlgoCompare.rotateLayer(layer, -1);

        // Check if the actual result matches the expected result

        FQuat q1 = Algo.grid.cubes[0][0][0].orientation, q2 = AlgoCompare.grid.cubes[0][0][0].orientation;

        bool ActualResult = Algo == AlgoCompare;
        bool ExpectedResult = true;
        Test.TestEqual(FString::Printf(TEXT("Layer %d Rotation Equality"), layer), ActualResult, ExpectedResult);
    }
}

void TestCubeAlgorithm::TestEqualLocal(FAutomationTestBase& Test)
{
    // Initialize the CubeAlgorithm
    AActor* DummyActor = NewObject<AActor>();
    CubeAlgorithm Algo(DummyActor);
    CubeAlgorithm AlgoCompare(DummyActor);

    // Check if the actual result matches the expected result
    bool ActualResult = Algo == AlgoCompare;
    bool ExpectedResult = true;
    Test.TestEqual(TEXT("Cube Equality"), ActualResult, ExpectedResult);

    // Rotate the layer in one direction
    AlgoCompare.rotateLayer(0, 1);

    // Check if the actual result matches the expected result
    ActualResult = Algo == AlgoCompare;
    ExpectedResult = false;
    Test.TestEqual(TEXT("Cube Inequality"), ActualResult, ExpectedResult);

    // Rotate the layer in the opposite direction
    AlgoCompare.rotateLayer(0, -1);

    // Check if the actual result matches the expected result
    ActualResult = Algo == AlgoCompare;
    ExpectedResult = true;
    Test.TestEqual(TEXT("Cube Identity Equality"), ActualResult, ExpectedResult);
}
