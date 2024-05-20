// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CubeAlgo : ModuleRules
{
	public CubeAlgo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PrivateIncludePaths.AddRange(
			new string[] {
				"CubeAlgo/Tests"  // Ensure this line is here
			}
			);

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.Add("UnrealEd"); // Only include this if it's an Editor module
			// PrivateDependencyModuleNames.Add("AutomationTool");
			PublicDependencyModuleNames.Add("FunctionalTesting");
			DynamicallyLoadedModuleNames.Add("AutomationController");
		}
	}
}
