// Fill out your copyright notice in the Description page of Project Settings.
#include "TankBarrel.h"
#include "BattleTank.h"
#include "Runtime/Engine/Classes/Engine/World.h"
void UTankBarrel::Elevate(float RelativeSpeed)
{
	
	
	//Move the barrel in the righht amount this frame
	//Given a max elevation speed and frame rate

//clamp relative speed
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
SetRelativeRotation(FRotator(Elevation, 0, 0));

}


