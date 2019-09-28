// Fill out your copyright notice in the Description page of Project Settings.


#include "SpotLightDetector.h"
#include <Engine/World.h>
#include "LightAdventureGameModeBase.h"

USpotLightDetector::USpotLightDetector()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USpotLightDetector::BeginPlay()
{
	Player = Cast<ALightCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void USpotLightDetector::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if (Player) {
		ALightAdventureGameModeBase* GameMode = Cast<ALightAdventureGameModeBase>(GetWorld()->GetAuthGameMode());
		FVector forward = GetForwardVector();
		FVector toPlayer = Player->GetActorLocation() - GetComponentLocation();
		toPlayer.Normalize();
		float dot = FVector::DotProduct(forward, toPlayer);
		float angle = FMath::RadiansToDegrees(FMath::Acos(dot));
		if (angle <= OuterConeAngle && !bIsDetectingPlayer) {
			GameMode->EnteredLight.Broadcast();
			bIsDetectingPlayer = true;
		}
		else if (angle > OuterConeAngle && bIsDetectingPlayer) {
			GameMode->ExitedLight.Broadcast();
			bIsDetectingPlayer = false;
		}
	}
}

