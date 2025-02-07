// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IDeviceProfileSelectorModule.h"

class FSteamDeckDeviceProfileSelectorModule: public IDeviceProfileSelectorModule
{
public:

	// IDeviceProfileSelectorModule implementation
	virtual const FString GetRuntimeDeviceProfileName() override;

	// IModuleInterface implementation
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual ~FSteamDeckDeviceProfileSelectorModule()
	{

	}
};
