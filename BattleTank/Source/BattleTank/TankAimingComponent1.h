// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankAimingComponent1.generated.h"

//Enum for Aiming State
UENUM()
enum class EFiringState :uint8 {
	Reloading,
	Aiming,
	Locked
};



//Forward Declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

//Holds Barrel Properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent1 : public UActorComponent
{
	GENERATED_BODY()

public:	

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankTurret * TurretToSet, UTankBarrel * BarrelToSet);


	UFUNCTION(BlueprintCallable, Category="Firing")
		void Fire();

private:
	// Sets default values for this component's properties
	UTankAimingComponent1();
	void MoveBarrelTowards(FVector AimDirection);
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	bool IsBarrelMoving();
	FVector AimDirection;
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Reloading;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000;//Sensible starting value of 1000m/s
private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float ReloadTimeinSeconds = 3;

	double LastFireTime = 0;
};
