// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessRunGameGameMode.h"
#include "EndlessRunGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEndlessRunGameGameMode::AEndlessRunGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
