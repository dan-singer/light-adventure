// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LightAdventureGameModeBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEnteredLight);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FExitedLight);


/**
 * 
 */
UCLASS()
class LIGHTADVENTURE_API ALightAdventureGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	FEnteredLight EnteredLight;
	FExitedLight ExitedLight;
	
};
