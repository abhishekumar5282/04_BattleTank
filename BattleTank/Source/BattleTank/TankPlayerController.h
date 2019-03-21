// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
		ATank* GetControlledTanK() const;
	
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
private:
		//Start the tank aiming to hit the objects
		void AimTowardCrosshair();

		UPROPERTY(EditDefaultsOnly)
			float CrossHairXLocation = 0.5;

		UPROPERTY(EditDefaultsOnly)
			float CrossHairYLocation = 0.33333;

		UPROPERTY(EditDefaultsOnly)
			float  LineTraceRange = 1000000;//10km

		//FVector2D ScreenLocation=FVector2D(0,0);

	bool	GetLookVectorHitLocation(FVector Lookdirection,FVector& Hitlocation ) const;
	bool GetSightRayHitLocation(FVector&  HitLocation) const;
	bool GetLookDirection(FVector2D &ScreenLocation,  FVector &WorldDirection) const;
};
