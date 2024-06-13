#include "TestCube.h"

bool FCubeTest::RunTest(const FString& Parameters)
{
    TestCube TestCube;

    TestCube.TestToString(*this);
    TestCube.TestToStringNormalized(*this);
    TestCube.TestEqualLocal(*this);
    TestCube.TestNotEqualLocal(*this);

    return true;
}

void TestCube::InitializeCube(Cube& cube)
{
    cube.location = FVector(0.0f, 1.0f, 2.0f);
    cube.facing = FVector(1.0f, 0.0f, 0.0f);
    cube.orientation = FQuat(1, 2, 3, 4);
    cube.rotation = cube.orientation.Rotator();
    
    cube.indices[0] = 0;
    cube.indices[1] = 1;
    cube.indices[2] = 2;
    cube.originalIndices[0] = 0;
    cube.originalIndices[1] = 1;
    cube.originalIndices[2] = 2;
}


void TestCube::TestToString(FAutomationTestBase& Test)
{
    Cube cube;
    InitializeCube(cube);

    FString expected = "<L:(0.00, 1.00, 2.00) F:(1.00, 0.00, 0.00) O:(1.00, 2.00, 3.00, 4.00) R:(-90.00, 131.76, -159.83) [0][1][2] ([0][1][2])>, ";
    Test.TestEqual("ToString", cube.ToString(), expected);
}

void TestCube::TestToStringNormalized(FAutomationTestBase& Test)
{
    Cube cube;
    InitializeCube(cube);

    FString expected = "<L:(0.00, 1.00, 2.00) O:(1.00, 2.00, 3.00, 4.00) [0][1][2] ([0][1][2])>, ";
    Test.TestEqual("ToStringNormalized", cube.ToStringNormalized(), expected);
}

void TestCube::TestEqualLocal(FAutomationTestBase& Test)
{
    Cube cube1;
    Cube cube2;
    InitializeCube(cube1);
    InitializeCube(cube2);

    Test.TestTrue("Cubes are equal", cube1 == cube2);

}

void TestCube::TestNotEqualLocal(FAutomationTestBase& Test)
{
    Cube cube1;
    Cube cube2;
    InitializeCube(cube1);
    InitializeCube(cube2);
    cube2.location = FVector(0.0f, 1.0f, 3.0f);

    Test.TestTrue("Cubes are not equal", cube1 != cube2);
}
