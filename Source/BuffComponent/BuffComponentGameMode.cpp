// Copyright Epic Games, Inc. All Rights Reserved.

#include "BuffComponentGameMode.h"
#include "BuffComponentCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABuffComponentGameMode::ABuffComponentGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
