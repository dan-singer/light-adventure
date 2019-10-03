// Fill out your copyright notice in the Description page of Project Settings.


#include "LightCharacter.h"
#include "Engine/World.h"
#include "LightAdventureGameModeBase.h"
#include <Engine/Engine.h>
#include <GameFramework/CharacterMovementComponent.h>
// Sets default values
ALightCharacter::ALightCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALightCharacter::BeginPlay()
{
	Super::BeginPlay();
	ALightAdventureGameModeBase* GameMode = Cast<ALightAdventureGameModeBase>(GetWorld()->GetAuthGameMode());
	GameMode->EnteredLight.AddDynamic(this, &ALightCharacter::OnLightEnter);
	GameMode->ExitedLight.AddDynamic(this, &ALightCharacter::OnLightExit);
	InitialWalkSpeed = Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed;
}

void ALightCharacter::LookHorizontal(float amt)
{
	AddControllerYawInput(amt * GetWorld()->DeltaTimeSeconds * LookSensitivityX);
}

void ALightCharacter::LookVertical(float amt)
{
	AddControllerPitchInput(-amt * GetWorld()->DeltaTimeSeconds * LookSensitivityY);
}

void ALightCharacter::MoveForward(float amt)
{
	AddMovementInput(GetActorForwardVector(), amt);
}

void ALightCharacter::MoveRight(float amt)
{
	AddMovementInput(GetActorRightVector(), amt);
}

void ALightCharacter::SprintStart()
{
	Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = SprintSpeed;

}

void ALightCharacter::SprintEnd()
{
	Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = InitialWalkSpeed;
}

void ALightCharacter::OnLightEnter()
{
	++LightsUnder;
}

void ALightCharacter::OnLightExit()
{
	--LightsUnder;
}

// Called every frame
void ALightCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (LightsUnder > 0 && Strength < 1 && !IsDead) {
		Strength += DeltaTime * RecoverRate;
	}
	else if (LightsUnder == 0 && Strength > 0) {
		Strength -= DeltaTime * DamageRate;
		if (Strength <= 0) {
			Died.Broadcast();
			IsDead = true;
		}
	}
}

// Called to bind functionality to input
void ALightCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

