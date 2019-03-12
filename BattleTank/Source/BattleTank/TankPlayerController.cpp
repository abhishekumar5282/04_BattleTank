// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Playercontroller beginplay"));
	auto possessed = GetControlledTanK();
	if (!possessed)
	{
		UE_LOG(LogTemp, Warning, TEXT("NO tank found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessed Tank is %s"),*possessed->GetName());
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("TICK TICK"));
}

ATank * ATankPlayerController::GetControlledTanK() const
{
	//return nullptr;
	
	
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair()
{
	FVector hitlocation;
	if (!GetControlledTanK())
	{
		return;
	}
	else
	{
		
		if (GetSightRayHitLocation(hitlocation))
		{
			UE_LOG(LogTemp, Warning, TEXT("Location is %s"), *hitlocation.ToString());
		}
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}
