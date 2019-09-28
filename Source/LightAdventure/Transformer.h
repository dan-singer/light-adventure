// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Transformer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIGHTADVENTURE_API UTransformer : public UActorComponent
{
	GENERATED_BODY()

	enum State {
		Forward,
		Reverse,
		Paused
	};

public:	
	// Sets default values for this component's properties
	UTransformer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FVector StartLocation;
	FRotator StartRotation;

	UPROPERTY(EditAnywhere)
	FVector LocationOffset;

	UPROPERTY(EditAnywhere)
	FRotator EndRotation;

	UPROPERTY(EditAnywhere)
	float StepDuration = 1.0f;

	UPROPERTY(EditAnywhere)
	float PauseDuration = 1.0f;

	float Alpha = 0.0f;
	State state = State::Forward;
	State prevState = State::Forward;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
