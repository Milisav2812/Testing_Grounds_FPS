// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Testing_Grounds_FPSGameMode.h"
#include "Testing_Grounds_FPSHUD.h"
#include "Testing_Grounds_FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATesting_Grounds_FPSGameMode::ATesting_Grounds_FPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATesting_Grounds_FPSHUD::StaticClass();
}
