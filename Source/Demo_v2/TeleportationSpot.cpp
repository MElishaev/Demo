// Fill out your copyright notice in the Description page of Project Settings.


#include "TeleportationSpot.h"

// Sets default values
ATeleportationSpot::ATeleportationSpot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATeleportationSpot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeleportationSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
