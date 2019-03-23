// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent1.h"
#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/AIModule/Classes/AIController.h"

//Depends on path finding

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank= GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank= GetPawn();
	FVector HitLocation = PlayerTank->GetActorLocation();
	if (!PlayerTank || !ControlledTank) { return; }
	
		//Move towards the actor
		MoveToActor(PlayerTank,AcceptanceRadius);

		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent1>();
		AimingComponent->AimAt(HitLocation);
		//Fire
		AimingComponent->Fire();
	
}


