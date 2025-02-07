// Copyright Epic Games, Inc. All Rights Reserved.

#include "SteamDeckDeviceProfileSelectorModule.h"
#include "Modules/ModuleManager.h"
#include "Misc/ConfigCacheIni.h"

IMPLEMENT_MODULE(FSteamDeckDeviceProfileSelectorModule, SteamDeckDeviceProfileSelector);

void FSteamDeckDeviceProfileSelectorModule::StartupModule()
{

}

void FSteamDeckDeviceProfileSelectorModule::ShutdownModule()
{

}

const FString FSteamDeckDeviceProfileSelectorModule::GetRuntimeDeviceProfileName()
{
	return TEXT("SteamDeck");
}
