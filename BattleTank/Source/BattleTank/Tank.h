// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent1;
class UTankTurret;

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

//protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnyWhere, Category = Firing)
		float LaunchSpeed = 100000;//Sensible starting value of 1000m/s


protected:
	UTankAimingComponent1* TankAimingComponent = nullptr;
};
