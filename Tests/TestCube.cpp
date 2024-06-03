#include "TestCube.h"

bool FCubeTest::RunTest(const FString& Parameters)
{
    TestEqualLocal(*this);
    TestNotEqualLocal(*this);
    TestToString(*this);
    TestToStringNormalized(*this);
    TestHandleNegativeZero(*this);
    TestAreQuatsEqual(*this);
    TestAreQuatsNotEqual(*this);
    TestDtoi(*this);

    return true;
}

void InitializeCube(Cube& cube)
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

void TestEqualLocal(FAutomationTestBase& Test)
{
    Cube cube1;
    Cube cube2;
    InitializeCube(cube1);
    InitializeCube(cube2);

    Test.TestTrue("Cubes are equal", cube1 == cube2);

}

void TestNotEqualLocal(FAutomationTestBase& Test)
{
    Cube cube1;
    Cube cube2;
    InitializeCube(cube1);
    InitializeCube(cube2);
    cube2.location = FVector(0.0f, 1.0f, 3.0f);

    Test.TestFalse("Cubes are not equal", cube1 == cube2);
}

void TestToString(FAutomationTestBase& Test)
{
    Cube cube;
    InitializeCube(cube);

    FString expected = "<L:(0.00, 1.00, 2.00) F:(1.00, 0.00, 0.00) O:(1.00, 2.00, 3.00, 4.00) R:(-90.00, 131.76, -159.83) [0][1][2] ([0][1][2])>, ";
    Test.TestEqual("ToString", cube.ToString(), expected);
}

void TestToStringNormalized(FAutomationTestBase& Test)
{
    Cube cube;
    InitializeCube(cube);

    FString expected = "<L:(0.00, 1.00, 2.00) F:(1.00, 0.00, 0.00) O:(1.00, 2.00, 3.00, 4.00) R:(90.00, 131.76, 159.83) [0][1][2] ([0][1][2])>, ";
    Test.TestEqual("ToStringNormalized", cube.ToStringNormalized(), expected);
}

void TestHandleNegativeZero(FAutomationTestBase& Test)
{
    Test.TestEqual("HandleNegativeZero", HandleNegativeZero(-0.0), 0.0);
}

void TestAreQuatsEqual(FAutomationTestBase& Test)
{
    FQuat quat1(1, 2, 3, 4);
    FQuat quat2(1, 2, 3, 4);

    Test.TestTrue("AreQuatsEqual True", AreQuatsEqual(quat1, quat2));

    quat2 = -quat2;
    Test.TestTrue("AreQuatsEqual Negative", AreQuatsEqual(quat1, quat2));

    FQuat quat3(2, 2, 3, 4);
    Test.TestFalse("AreQuatsEqual False", AreQuatsEqual(quat1, quat3));
}

void TestAreQuatsNotEqual(FAutomationTestBase& Test)
{
    FQuat quat(1, 2, 3, 4);
    FQuat shouldBeEqualQuat(1, 2, 3, 4 + 1e-7);
    FQuat shouldBeNotEqualQuat(1, 2, 3, 4 + 1e-6);

    Test.TestTrue("AreQuatsNotEqual Should be equal", AreQuatsEqual(quat, shouldBeEqualQuat));
    Test.TestFalse("AreQuatsNotEqual Should not be equal", AreQuatsEqual(quat, shouldBeNotEqualQuat));
}

void TestDtoi(FAutomationTestBase& Test)
{
    Test.TestEqual("Dtoi", dtoi(1.5), 2);
    Test.TestEqual("Dtoi", dtoi(1.4), 1);
    Test.TestEqual("Dtoi", dtoi(-1.5), 2);
    Test.TestEqual("Dtoi", dtoi(-1.4), 1);
}
