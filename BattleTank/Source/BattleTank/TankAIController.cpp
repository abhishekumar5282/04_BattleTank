// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank= Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank= Cast<ATank>(GetPawn());
	FVector HitLocation = PlayerTank->GetActorLocation();
	if (PlayerTank)
	{
		ControlledTank->AimAt(HitLocation);
		//Fire
		ControlledTank->Fire();
	}
}


