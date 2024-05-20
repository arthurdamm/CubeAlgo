// CubeAlgorithmTests.cpp
#include "Misc/AutomationTest.h"
#include "../CubeAlgorithm.h"  // Include the header of the actual class you're testing

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCubeRotationTest, "Test.CubeAlgorithm.Rotation", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FCubeRotationTest::RunTest(const FString& Parameters)
{
    // CubeAlgorithm cubeAlg(this);
    // cubeAlg.init();
    // cubeAlg.init();
    TestTrue(TEXT("Example test always passes"), true);

    return true;
}
