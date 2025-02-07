// Copyright Feral Cat Den, LLC. All Rights Reserved.

using UnrealBuildTool;

public class SteamDeckConfig : ModuleRules
{
	public SteamDeckConfig(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;				

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Engine"
			});
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"SteamShared"
            });

        AddEngineThirdPartyPrivateStaticDependencies(Target, "Steamworks");
    }
}
