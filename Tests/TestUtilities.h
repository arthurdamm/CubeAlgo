#include "Misc/AutomationTest.h"
#include "../Utilities.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUtilitiesTest, "CubeUtilities.Tests.Basic", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)

class TestUtilities
{
public:
    void TestDtoi(FAutomationTestBase& Test);
    void TestHandleNegativeZero(FAutomationTestBase& Test);
    void TestAreQuatsEqual(FAutomationTestBase& Test);
    void TestAreQuatsNotEqual(FAutomationTestBase& Test);
    void TestFilter(FAutomationTestBase& Test);
};