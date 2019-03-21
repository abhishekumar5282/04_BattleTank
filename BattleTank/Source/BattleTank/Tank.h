// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent1;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable,Category= Setup)
	void Setbarrelreference(UTankBarrel* BarrelToSet);	

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretreference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
		void Fire();
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 4000;//Sensible starting value of 1000m/s

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	//Local Refernce for use in projectile instatntiation
	UTankBarrel * Barrel=nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float ReloadTimeinSeconds=3;

	double LastFireTime=0;


protected:
	UTankAimingComponent1* TankAimingComponent = nullptr;
};
