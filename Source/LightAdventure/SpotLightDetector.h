// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SpotLightComponent.h"
#include "LightCharacter.h"
#include "SpotLightDetector.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LIGHTADVENTURE_API USpotLightDetector : public USpotLightComponent
{
	GENERATED_BODY()

private:
	ALightCharacter* Player = nullptr;
	bool bIsDetectingPlayer = false;

public:
	USpotLightDetector();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
