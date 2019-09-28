// Fill out your copyright notice in the Description page of Project Settings.


#include "LightCharacter.h"
#include "Engine/World.h"
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

// Called every frame
void ALightCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALightCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

