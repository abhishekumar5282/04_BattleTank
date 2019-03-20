// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankAimingComponent1.generated.h"

//Forward Declaration
class UTankBarrel;
class UTankTurret;

//Holds Barrel Properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent1 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent1();
	void AimAt(FVector HitLocation,float LaunchSpeed);

	void Setbarrelreference(UTankBarrel* BarrelToSet);
	void SetTurretreference(UTankTurret* TurretToSet);
private:
	void MoveBarrelTowards(FVector AimDirection);

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	
};
