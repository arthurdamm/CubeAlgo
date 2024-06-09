#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "../CubeHash.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCubeSolverTestCubeHash, "CubeSolver.Tests.CubeHash", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

class TestCubeHash
{
public:
    bool TestCubeHasher(FAutomationTestBase& Test);
    bool TestGridHasher(FAutomationTestBase& Test);
    bool TestGridEqual(FAutomationTestBase& Test);
    bool TestUnorderedSetCubeHash(FAutomationTestBase& Test);
    bool TestUnorderedSetGridHash(FAutomationTestBase& Test);
};
