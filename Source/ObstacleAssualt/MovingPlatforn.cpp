// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatforn.h"

// Sets default values
AMovingPlatforn::AMovingPlatforn()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatforn::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	// SetActorLocation(MyVector);

	FString MyString = "Hello World";
	FString MyActorName = GetName();
	UE_LOG(LogTemp, Display, TEXT("The Welcome String Is: %s"), *MyString);
	UE_LOG(LogTemp, Display, TEXT("The %s is Actor Presented"), *MyActorName);
	UE_LOG(LogTemp, Display, TEXT("Your message"));
	UE_LOG(LogTemp, Display, TEXT("MovedDistance: %f"), MovedDistance);
}

// Called every frame
void AMovingPlatforn::Tick(float DeltaTime)
{
	// Above (::) or Scope Resolution Oprerator tells us that we are using the Tick function from the Super Class below or the tick function used by the AMovingPlatform Class.
	Super::Tick(DeltaTime);

	// FVector LoactVector = MyVector;
	// LoactVector.Z = LoactVector.Z + 100;
	// MyVector.Y = MyVector.Y + 1;
	// SetActorLocation(MyVector);
	// SetActorLocation(LoactVector);

	MovePlateForm(DeltaTime);
	RotatePlateForm(DeltaTime);

	// FVector CurrentLocation = GetActorLocation();
	// CurrentLocation += PlatFormVelocity * DeltaTime;
	// SetActorLocation(CurrentLocation);
	// float DistanceCovered = FVector::Dist(StartLocation, CurrentLocation);
	// // Here we are extracting Dist Or Distance from the FVector Class
	// if (DistanceCovered > MovedDistance)
	// {
	// 	float OverShoot = DistanceCovered - MovedDistance;
	// 	FString Name = GetName();
	// 	UE_LOG(LogTemp, Display, TEXT("%s overshooted"), *Name);
	// 	UE_LOG(LogTemp, Display, TEXT("Overshoot: %f"), OverShoot);
	// 	// GetSafeNormal() is a function that returns a normalized version of the vector, safely handles zero vectors.
	// 	FVector MovedDirection = PlatFormVelocity.GetSafeNormal();
	// 	StartLocation = StartLocation + MovedDirection * MovedDistance;
	// 	SetActorLocation(StartLocation);
	// 	PlatFormVelocity = PlatFormVelocity * -1;
	// }
}

void AMovingPlatforn::MovePlateForm(float DeltaTime)
{

	// Here we are extracting Dist Or Distance from the FVector Class
	// float DistanceCovered = FVector::Dist(StartLocation, CurrentLocation);
	// OR
	GetDistanceCovered();

	if (ShouldMoveReverse())
	{
		float OverShoot = GetDistanceCovered() - MovedDistance;
		FString Name = GetName();
		UE_LOG(LogTemp, Display, TEXT("%s overshooted"), *Name);
		UE_LOG(LogTemp, Display, TEXT("Overshoot: %f"), OverShoot);
		// GetSafeNormal() is a function that returns a normalized version of the vector, safely handles zero vectors.
		FVector MovedDirection = PlatFormVelocity.GetSafeNormal();
		StartLocation = StartLocation + MovedDirection * MovedDistance;
		SetActorLocation(StartLocation);
		PlatFormVelocity = PlatFormVelocity * -1;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += PlatFormVelocity * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatforn::RotatePlateForm(float DeltaTime)
{
	// FRotator CurrentRotation = GetActorRotation();
	// CurrentRotation = CurrentRotation + PlatFormRotation * DeltaTime;
	// SetActorRotation(CurrentRotation);
	// OR
	AddActorLocalRotation(PlatFormRotation * DeltaTime);
}

bool AMovingPlatforn::ShouldMoveReverse() const
{
	return GetDistanceCovered() > MovedDistance;
}

float AMovingPlatforn::GetDistanceCovered() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}