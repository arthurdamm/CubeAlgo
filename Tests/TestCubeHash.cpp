#include "TestCubeHash.h"

bool FCubeSolverTestCubeHash::RunTest(const FString& Parameters)
{
    TestCubeHash TestCubeHash;

    TestCubeHash.TestCubeHasher(*this);
    TestCubeHash.TestGridHasher(*this);
    TestCubeHash.TestGridEqual(*this);
    TestCubeHash.TestUnorderedSetCubeHash(*this);
    TestCubeHash.TestUnorderedSetGridHash(*this);

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

    CubeGrid grid;
    grid.cubes[0][0][0].orientation.X = 1;
    grid.cubes[0][0][0].orientation.Y = 2;
    grid.cubes[0][0][0].orientation.Z = 3;
    grid.cubes[0][0][0].orientation.W = 4;

    CubeGrid secondGrid;
    secondGrid.cubes[0][0][0].orientation.X = 1;
    secondGrid.cubes[0][0][0].orientation.Y = 2;
    secondGrid.cubes[0][0][0].orientation.Z = 3;
    secondGrid.cubes[0][0][0].orientation.W = 4;

    size_t hash = gridHasher(grid);
    Test.TestTrue("GridHasher Not null", hash != 0);

    size_t secondHash = gridHasher(secondGrid);
    
    Test.TestEqual("GridHasher Equal", hash, secondHash);

    secondGrid.cubes[0][0][0].orientation.W *= 2;
    secondHash = gridHasher(secondGrid);

    Test.TestNotEqual("GridHasher Not Equal", hash, secondHash);
    
    return true;
}

bool TestCubeHash::TestGridEqual(FAutomationTestBase& Test)
{
    CubeGrid grid;
    CubeGrid secondGrid;

    Test.TestEqual("GridEqual Equal", grid, secondGrid);

    grid.cubes[0][0][0].orientation.X = 1;
    grid.cubes[0][0][0].orientation.Y = 2;
    grid.cubes[0][0][0].orientation.Z = 3;
    grid.cubes[0][0][0].orientation.W = 4;

    secondGrid.cubes[0][0][0].orientation.X = 1;
    secondGrid.cubes[0][0][0].orientation.Y = 2;
    secondGrid.cubes[0][0][0].orientation.Z = 3;
    secondGrid.cubes[0][0][0].orientation.W = 4;

    Test.TestEqual("GridEqual Equal", grid, secondGrid);

    secondGrid.cubes[0][0][0].orientation.W *= 2;

    Test.TestNotEqual("GridEqual Not Equal", grid, secondGrid);

    return true;
}

bool TestCubeHash::TestUnorderedSetCubeHash(FAutomationTestBase& Test)
{
    std::unordered_set<Cube, CubeHasher> cubes;

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

    cubes.insert(cube);

    Test.TestTrue("UnorderedSetCubeHash Insert", cubes.find(secondCube) != cubes.end());

    secondCube.orientation.W *= 2;

    Test.TestFalse("UnorderedSetCubeHash Not Insert", cubes.find(secondCube) != cubes.end());

    return true;
}

bool TestCubeHash::TestUnorderedSetGridHash(FAutomationTestBase& Test)
{
    std::unordered_set<CubeGrid, GridHasher> grids;

    CubeGrid grid;
    grid.cubes[0][0][0].orientation.X = 1;
    grid.cubes[0][0][0].orientation.Y = 2;
    grid.cubes[0][0][0].orientation.Z = 3;
    grid.cubes[0][0][0].orientation.W = 4;

    CubeGrid secondGrid;
    secondGrid.cubes[0][0][0].orientation.X = 1;
    secondGrid.cubes[0][0][0].orientation.Y = 2;
    secondGrid.cubes[0][0][0].orientation.Z = 3;
    secondGrid.cubes[0][0][0].orientation.W = 4;

    grids.insert(grid);

    Test.TestTrue("UnorderedSetGridHash Insert", grids.find(secondGrid) != grids.end());

    secondGrid.cubes[0][0][0].orientation.W *= 2;

    Test.TestFalse("UnorderedSetGridHash Not Insert", grids.find(secondGrid) != grids.end());

    return true;
}
