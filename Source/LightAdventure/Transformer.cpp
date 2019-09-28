// Fill out your copyright notice in the Description page of Project Settings.


#include "Transformer.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UTransformer::UTransformer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTransformer::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetOwner()->GetActorLocation();
	StartRotation = GetOwner()->GetActorRotation();
}


// Called every frame
void UTransformer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	switch (state)
	{
	case UTransformer::Forward:
	{
		FVector newLoc = FMath::Lerp(StartLocation, StartLocation + LocationOffset, Alpha);
		GetOwner()->SetActorLocation(newLoc);

		FQuat newRot = FQuat::Slerp(StartRotation.Quaternion(), EndRotation.Quaternion(), Alpha);
		GetOwner()->SetActorRotation(newRot);

		Alpha += DeltaTime / StepDuration;

		if (Alpha >= 1.0f) {
			Alpha = 0;
			prevState = State::Forward;
			state = State::Paused;
		}
		break;
	}
	case UTransformer::Reverse:
	{
		FVector newLoc = FMath::Lerp(StartLocation + LocationOffset, StartLocation, Alpha);
		GetOwner()->SetActorLocation(newLoc);

		FQuat newRot = FQuat::Slerp(EndRotation.Quaternion(), StartRotation.Quaternion(), Alpha);
		GetOwner()->SetActorRotation(newRot);

		Alpha += DeltaTime / StepDuration;

		if (Alpha >= 1.0f) {
			Alpha = 0;
			prevState = State::Reverse;
			state = State::Paused;
		}
		break;
	}
	case UTransformer::Paused:
	{
		Alpha += DeltaTime / PauseDuration;
		if (Alpha > 1.0f) {
			Alpha = 0;
			state = prevState == State::Forward ? State::Reverse : State::Forward;
		}
		break;
	}
	default:
		break;
	}
}

