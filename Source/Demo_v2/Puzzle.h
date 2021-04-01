// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuantumMesh.h"
#include "TeleportationSpot.h"
#include "Puzzle.generated.h"

UCLASS()
class DEMO_V2_API APuzzle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<AQuantumMesh*> Meshes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<ATeleportationSpot*> TpSpots;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<AQuantumMesh *> GetMeshes() { return Meshes; }

	TArray<ATeleportationSpot *> GetTpSpots() { return TpSpots; }

	ATeleportationSpot *FindEmptySpot(FVector& BoxExtent);

	void FreeMeshSpot(AQuantumMesh*);

	bool CaptureMeshSpot(ATeleportationSpot *, AQuantumMesh *);
};
