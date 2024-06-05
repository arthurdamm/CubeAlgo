#include "Misc/AutomationTest.h"
#include "../Cube.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCubeTest, "Cube.Tests.Equal", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)

class TestCube
{
public:
    void InitializeCube(Cube& cube);

    // Cube.h
    void TestToString(FAutomationTestBase& Test);
    void TestToStringNormalized(FAutomationTestBase& Test);
    void TestEqualLocal(FAutomationTestBase& Test);
    void TestNotEqualLocal(FAutomationTestBase& Test);

    // Utilities.h
    void TestDtoi(FAutomationTestBase& Test);
    void TestHandleNegativeZero(FAutomationTestBase& Test);
    void TestAreQuatsEqual(FAutomationTestBase& Test);
    void TestAreQuatsNotEqual(FAutomationTestBase& Test);
};