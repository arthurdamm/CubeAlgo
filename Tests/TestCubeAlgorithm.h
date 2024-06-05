#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "../CubeAlgorithm.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCubeAlgorithmTestBasic, "CubeAlgorithm.Tests.Basic", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCubeAlgorithmTestRotation, "CubeAlgorithm.Tests.Rotation", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

class TestCubeAlgorithm
{
public:
    void TestInitializeCubes(FAutomationTestBase& Test);

    void TestToString(FAutomationTestBase& Test);
    void TestToStringNormalized(FAutomationTestBase& Test);

    void TestRotateLayer0(FAutomationTestBase& Test);
    void TestRotateLayer7(FAutomationTestBase& Test);
    void TestGetRotationAxisForLayer(FAutomationTestBase& Test);
    void TestGetCenterForLayer(FAutomationTestBase& Test);
    void TestLayerRotations(FAutomationTestBase& Test);
    void TestEqualLocal(FAutomationTestBase& Test);
};

