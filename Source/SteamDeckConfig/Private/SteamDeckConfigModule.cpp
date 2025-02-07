// Copyright Feral Cat Den, LLC. All Rights Reserved.

#include "SteamDeckConfigModule.h"
#include "SteamSharedModule.h"
#include <steam/isteamutils.h>

DEFINE_LOG_CATEGORY(LogSteamDeckConfig);

void FSteamDeckConfigModule::StartupModule()
{
	if (IsRunningOnSteamDeck_EarlyInit())
	{
		UE_LOG(LogSteamDeckConfig, Log, TEXT("Applying SteamDeck configs"));

		TArray<FString> ConfigFiles = { TEXT("Engine"), TEXT("Game"), TEXT("Input"), TEXT("DeviceProfiles") };
		for (const FString& ConfigFile : ConfigFiles)
		{
			FConfigFile* FoundConfig = GConfig->FindConfigFile(ConfigFile);
			if (FoundConfig)
			{
				const FString OverrideConfigPath = FPaths::Combine(FPaths::ProjectConfigDir(), "SteamDeck", "SteamDeck" + ConfigFile + ".ini");
				FoundConfig->AddDynamicLayerToHierarchy(OverrideConfigPath);
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
