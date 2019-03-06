// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GroundsGameMode.h"
#include "GroundsHUD.h"
#include "GroundsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGroundsGameMode::AGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGroundsHUD::StaticClass();
}
