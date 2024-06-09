#include "TestCubeHash.h"

bool FCubeSolverTestCubeHash::RunTest(const FString& Parameters)
{
    TestCubeHash TestCubeHash;

    TestCubeHash.TestCubeHasher(*this);
    TestCubeHash.TestGridHasher(*this);
    TestCubeHash.TestGridEqual(*this);

    return true;
}

bool TestCubeHash::TestCubeHasher(FAutomationTestBase& Test)
{
    CubeHasher cubeHasher;

    Cube cube;
    cube.orientation.X = 1;
    cube.orientation.Y = 2;
    cube.orientation.Z = 3;
    cube.orientation.W = 4;

    Cube secondCube;
    secondCube.orientation.X = 1;
    secondCube.orientation.Y = 2;
    secondCube.orientation.Z = 3;
    secondCube.orientation.W = 4;

    size_t hash = cubeHasher(cube);
    Test.TestTrue("CubeHasher Not null", hash != 0);

    size_t secondHash = cubeHasher(secondCube);
    
    Test.TestEqual("CubeHasher Equal", hash, secondHash);

    secondCube.orientation.W *= 2;
    secondHash = cubeHasher(secondCube);

    Test.TestNotEqual("CubeHasher Not Equal", hash, secondHash);
    
    return true;
}

bool TestCubeHash::TestGridHasher(FAutomationTestBase& Test)
{
    GridHasher gridHasher;

    Cube cubes[3][3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
            {
                cubes[i][j][k].orientation.X = i;
                cubes[i][j][k].orientation.Y = j;
                cubes[i][j][k].orientation.Z = k;
                cubes[i][j][k].orientation.W = 0;
            }

    size_t hash = gridHasher(cubes);
    Test.TestTrue("GridHasher Not null", hash != 0);

    Cube secondCubes[3][3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
            {
                secondCubes[i][j][k].orientation.X = i;
                secondCubes[i][j][k].orientation.Y = j;
                secondCubes[i][j][k].orientation.Z = k;
                secondCubes[i][j][k].orientation.W = 0;
            }

    size_t secondHash = gridHasher(secondCubes);
    Test.TestEqual("GridHasher Equal", hash, secondHash);

    secondCubes[1][1][1].orientation.W = 1;
    secondHash = gridHasher(secondCubes);
    Test.TestNotEqual("GridHasher Not Equal", hash, secondHash);

    return true;
}

bool TestCubeHash::TestGridEqual(FAutomationTestBase& Test)
{
    GridEqual gridEqual;

    Cube cubes[3][3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
            {
                cubes[i][j][k].orientation.X = i;
                cubes[i][j][k].orientation.Y = j;
                cubes[i][j][k].orientation.Z = k;
                cubes[i][j][k].orientation.W = 0;
            }

    Cube secondCubes[3][3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
            {
                secondCubes[i][j][k].orientation.X = i;
                secondCubes[i][j][k].orientation.Y = j;
                secondCubes[i][j][k].orientation.Z = k;
                secondCubes[i][j][k].orientation.W = 0;
            }

    Test.TestTrue("GridEqual Equal", gridEqual(cubes, secondCubes));

    secondCubes[1][1][1].orientation.W = 1;
    Test.TestFalse("GridEqual Not Equal", gridEqual(cubes, secondCubes));

    return true;
}