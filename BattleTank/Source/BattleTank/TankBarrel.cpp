// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//Move the barrel in the righht amount this frame
	//Given a max elevation speed and frame rate
	UE_LOG(LogTemp, Warning, TEXT("Barrel elevated by %f"), DegreesPerSecond);
}


