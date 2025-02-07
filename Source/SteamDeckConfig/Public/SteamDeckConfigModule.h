// Copyright Feral Cat Den, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FSteamDeckConfigModule : public IModuleInterface
{
public:

	// IModuleInterface implementation
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	STEAMDECKCONFIG_API static bool IsRunningOnSteamDeck();
	STEAMDECKCONFIG_API static bool IsRunningOnSteamDeck_EarlyInit();
};

DECLARE_LOG_CATEGORY_EXTERN(LogSteamDeckConfig, Log, All);
