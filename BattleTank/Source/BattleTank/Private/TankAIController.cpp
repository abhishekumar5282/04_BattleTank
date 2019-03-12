// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("AIcontroller beginplay"));
	auto playertank = GetPlayerTanK();
	if (!playertank)
	{
		UE_LOG(LogTemp, Warning, TEXT("NO AI tank found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI TANK Possessed Tank is %s"), *playertank->GetName());
	}

}

ATank * ATankAIController::GetPlayerTanK() const
{
	//APlayerController *playertank = nullptr;
	auto playerpawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!playerpawn)
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(playerpawn);
	}
	
}


ATank * ATankAIController::GetControlledTanK() const
{
	//return nullptr;


	return Cast<ATank>(GetPawn());
}