#include "Misc/AutomationTest.h"
#include "../Cube.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCubeTest, "Cube.Tests.Equal", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)

void InitializeCube(Cube& cube);
void TestEqualLocal(FAutomationTestBase& Test);
void TestNotEqualLocal(FAutomationTestBase& Test);
void TestToString(FAutomationTestBase& Test);
void TestToStringNormalized(FAutomationTestBase& Test);
void TestHandleNegativeZero(FAutomationTestBase& Test);
void TestAreQuatsEqual(FAutomationTestBase& Test);
void TestDtoi(FAutomationTestBase& Test);
