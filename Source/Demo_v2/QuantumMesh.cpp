// Fill out your copyright notice in the Description page of Project Settings.

#include "QuantumMesh.h"
// Sets default values
AQuantumMesh::AQuantumMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AQuantumMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuantumMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UTeleporter *Teleporter = this->FindComponentByClass<UTeleporter>();
	
	Teleporter->Teleport(this);
}

float AQuantumMesh::GetTeleportationCooldown()
{
	return this->FindComponentByClass<UTeleporter>()->GetTeleportationCooldown();
}