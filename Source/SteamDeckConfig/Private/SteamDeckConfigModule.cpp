// Copyright Feral Cat Den, LLC. All Rights Reserved.

#include "SteamDeckConfigModule.h"
#include "SteamSharedModule.h"
#include <steam/isteamutils.h>
#include "Misc/ConfigCacheIni.h"

DEFINE_LOG_CATEGORY(LogSteamDeckConfig);

void FSteamDeckConfigModule::StartupModule()
{
	if (IsRunningOnSteamDeck_EarlyInit())
	{
		UE_LOG(LogSteamDeckConfig, Log, TEXT("Applying SteamDeck configs"));

		TArray<FName> ConfigFileBaseNames = {  FName("Engine"), FName("Game"), FName("Input"), FName("DeviceProfiles") };
		for (const FName& ConfigFileBaseName : ConfigFileBaseNames)
		{
			FConfigBranch* FoundBranch = GConfig->FindBranch(ConfigFileBaseName,FString() ); // Pass empty string for filename as we only use the base name to look up the branch
			if (FoundBranch)
			{
				FString ConfigFileName = ConfigFileBaseName.ToString();
				const FString OverrideConfigPath = FPaths::Combine(FPaths::ProjectConfigDir(), "SteamDeck", "SteamDeck" + ConfigFileName + ".ini");
				FoundBranch->AddDynamicLayerToHierarchy(OverrideConfigPath);
			}
			else
			{
				UE_LOG(LogSteamDeckConfig, Warning, TEXT("Could not find config branch for %s"), *ConfigFileBaseName.ToString());
			}
		}
	}
}

void FSteamDeckConfigModule::ShutdownModule()
{

}

bool FSteamDeckConfigModule::IsRunningOnSteamDeck()
{
	if (!FSteamSharedModule::IsAvailable())
	{
		FSteamSharedModule::Get();
	}

	if (FSteamSharedModule::IsAvailable())
	{
		if (SteamUtils())
		{
			return SteamUtils()->IsSteamRunningOnSteamDeck();
		}
	}

	return IsRunningOnSteamDeck_EarlyInit();
}

bool FSteamDeckConfigModule::IsRunningOnSteamDeck_EarlyInit()
{
	return FPlatformMisc::GetEnvironmentVariable(TEXT("SteamDeck")).Equals(FString(TEXT("1")));
}

IMPLEMENT_MODULE(FSteamDeckConfigModule, SteamDeckConfig)
