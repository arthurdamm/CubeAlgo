#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "../CubeAlgorithm.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCubeAlgorithmTest, "CubeAlgorithm.Tests.RotationTests", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

void TestRotateLayer0(FAutomationTestBase& Test);
void TestRotateLayer7(FAutomationTestBase& Test);
