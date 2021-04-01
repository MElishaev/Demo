// Fill out your copyright notice in the Description page of Project Settings.


#include "Puzzle.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "UtilityFunctions.h"

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

	// get the box extent of the meshes in the puzzle to adjust
	// the size of the teleportation spots.
	// NOTE: assuming we have only one type of mesh in each puzzle
	// or if more than one than they are of the same size
	FVector Origin;
	FVector BoxExtent;
	if(meshes.Num() > 0)
		meshes[0]->GetActorBounds(false, Origin, BoxExtent);


	TArray<AActor *> spots;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), ATeleportationSpot::StaticClass(), Tags[0], spots);
	for (AActor *spot : spots)
	{
		spot->SetActorScale3D(BoxExtent/50.f); // scale base to 1 meter and take half of that for each side (+x,-x)
		TpSpots.Add((ATeleportationSpot*)spot);
	}
}

// Called every frame
void APuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APuzzle::CaptureMeshSpot(ATeleportationSpot *Spot, AQuantumMesh* Mesh)
{
	if(!Spot->IsOccupied())
	{
		FreeMeshSpot(Mesh);
		Spot->SetOccupyingMesh(Mesh);
		Spot->SetOccupation(true);
		return true;
	}
	UE_LOG(LogTemp, Warning, TEXT("Spot %s is occupied."), *Spot->GetActorLocation().ToString());
	return false;
}

void APuzzle::FreeMeshSpot(AQuantumMesh* Mesh)
{
	for (ATeleportationSpot *s : TpSpots)
	{
		//UE_LOG(LogTemp, Warning, TEXT("%p =? %p"), s->GetOccupyingMesh(), Mesh);
		if(s->GetOccupyingMesh() == Mesh)
		{
			s->SetOccupyingMesh(NULL);
			s->SetOccupation(false);
			return;
		}
	}
}

ATeleportationSpot *APuzzle::FindEmptySpot(FVector &BoxExtent)
{
	TArray<int32> AvailableSpots;

	for (int32 i = 0; i < TpSpots.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("checking spot for availability %s"), *TpSpots[i]->GetActorLocation().ToString());
		if (!TpSpots[i]->IsOccupied() && !TpSpots[i]->WasRecentlyRendered(0.05))	
		{
			AvailableSpots.Add(i);
			UE_LOG(LogTemp, Warning, TEXT("Available"));
		}
	}
	if (AvailableSpots.Num() == 0)
		return NULL;
	int32 SpotIndex = FMath::RandRange(0, AvailableSpots.Num() - 1);
	UE_LOG(LogTemp, Warning, TEXT("Empty spot chosen at %s"), *TpSpots[AvailableSpots[SpotIndex]]->GetActorLocation().ToString());
	return TpSpots[AvailableSpots[SpotIndex]];
}