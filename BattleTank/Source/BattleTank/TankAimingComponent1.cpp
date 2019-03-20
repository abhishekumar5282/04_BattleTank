// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent1.h"
#include "BattleTank.h"
#include "TankBarrel.h"


// Sets default values for this component's properties
UTankAimingComponent1::UTankAimingComponent1()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



void UTankAimingComponent1::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	//Calclulate The OutLaunch velocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace

	);
		
	if(bHaveAimSolution)
	{
		//Get The Unit Vector
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s is Aiming at  %s"),*TankName ,*AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim Solution Found"), Time);
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No Solution Found"),Time);
	}
}

void UTankAimingComponent1::Setbarrelreference(UTankBarrel * BarrelToSet)
{
	if (!BarrelToSet) { return; }
	this->Barrel = BarrelToSet;
}
void UTankAimingComponent1::SetTurretreference(UTankTurret * TurretToSet)
{
	if (!TurretToSet) { return; }
	this->Turret = TurretToSet;
}
void UTankAimingComponent1::MoveBarrelTowards(FVector AimDirection)

{
	//Work out differnce between Current Barrel Rotation and AimRotation
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
}

