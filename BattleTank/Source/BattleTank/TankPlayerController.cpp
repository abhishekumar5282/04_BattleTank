// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankAimingComponent1.h"



void ATankPlayerController::BeginPlay()
{
Super::BeginPlay();
//	UE_LOG(LogTemp, Warning, TEXT("Playercontroller beginplay"));
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent1>();
	if (!AimingComponent) { return; }
	FoundAimingComponent(AimingComponent);
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("TICK TICK"));
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetPawn()) { return; }
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent1>();
	if (!AimingComponent) { return; }
	else
	{
		FVector HitLocation;
		if (GetSightRayHitLocation(HitLocation))
		{
			//UE_LOG(LogTemp, Warning, TEXT("HIt Location is %s"), *HitLocation.ToString());
			AimingComponent->AimAt(HitLocation);
		}
	}
}


bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//HitLocation = FVector(1.0);
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX* CrossHairXLocation, ViewPortSizeY *  CrossHairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("Screen Loaction is %s "), *ScreenLocation.ToString());
	//FVector Cameraworldlocation;
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		
		GetLookVectorHitLocation(LookDirection,HitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction is %s "), *HitLocation.ToString());
	}
	

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D &ScreenLocation, FVector &LookDirection) const
{
	FVector Cameraworldlocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y,Cameraworldlocation, LookDirection);
}

bool	ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	//if line trace succeeds then return true
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
	{
		HitLocation=HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);

	return false;
}
