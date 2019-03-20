// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is max downwards and +1 is max upwards
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnyWhere, Category=Setup)
	float MaxDegreesPerSecond =5;

	UPROPERTY(EditAnyWhere, Category = Setup)
		float MaxElevationDegrees = 40;

	UPROPERTY(EditAnyWhere, Category = Setup)
		float MinElevationDegrees = 0;
	
};
