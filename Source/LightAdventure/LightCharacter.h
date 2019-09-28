// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LightCharacter.generated.h"

UCLASS()
class LIGHTADVENTURE_API ALightCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALightCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	float LookSensitivityX = 100.0f;

	UPROPERTY(EditDefaultsOnly)
	float LookSensitivityY = 100.0f;

	UFUNCTION(BlueprintCallable)
	void LookHorizontal(float amt);

	UFUNCTION(BlueprintCallable)
	void LookVertical(float amt);

	UFUNCTION(BlueprintCallable)
	void MoveForward(float amt);

	UFUNCTION(BlueprintCallable)
	void MoveRight(float amt);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
