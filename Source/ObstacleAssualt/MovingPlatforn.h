// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatforn.generated.h"

UCLASS()
class OBSTACLEASSUALT_API AMovingPlatforn : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatforn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// UPROPERTY(EditAnywehre)
	// int32 MyInt = 0;

	// UPROPERTY(EditAnywhere)
	// FVector MyVector = FVector(0, 0, 0);

private:
	UPROPERTY(EditAnywhere, Category = "Moving PlatForm")
	FVector PlatFormVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category = "Moving PlatForm")
	float MovedDistance = 100;

	UPROPERTY(EditAnywhere, Category = "Rotating PlatForm")
	// UE_LOG(LogTemp, Display, TEXT("%s rota"), *GetName());
	FRotator PlatFormRotation;

	FVector StartLocation;

	void MovePlateForm(float DeltaTime);

	void RotatePlateForm(float DeltaTime);

	bool ShouldMoveReverse() const;

	float GetDistanceCovered() const;
};
