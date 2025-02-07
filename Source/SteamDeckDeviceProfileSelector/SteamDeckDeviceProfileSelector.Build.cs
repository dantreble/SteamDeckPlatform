// Copyright Feral Cat Den, LLC. All Rights Reserved.

using UnrealBuildTool;

public class SteamDeckDeviceProfileSelector : ModuleRules
{
	public SteamDeckDeviceProfileSelector(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core"
			});
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Engine"
            });
    }
}
