// Fill out your copyright notice in the Description page of Project Settings.


#include "Puzzle.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APuzzle::APuzzle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APuzzle::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> meshes;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), AQuantumMesh::StaticClass(), Tags[0], meshes);
	for (AActor *mesh : meshes)
	{
		int32 indx = Meshes.Add((AQuantumMesh*)mesh);
		Meshes[indx]->SetPuzzleParent(this);
	}

	TArray<AActor *> spots;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), ATeleportationSpot::StaticClass(), Tags[0], spots);
	for (AActor *spot : spots)
		TpSpots.Add((ATeleportationSpot*)spot);
}

// Called every frame
void APuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
