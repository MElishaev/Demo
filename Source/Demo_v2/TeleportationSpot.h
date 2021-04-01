// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuantumMesh.h"
#include "TeleportationSpot.generated.h"

UCLASS()
class DEMO_V2_API ATeleportationSpot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleportationSpot();

	void SetOccupyingMesh(AQuantumMesh *Mesh) { Obj = Mesh; }
	AQuantumMesh *GetOccupyingMesh() { return Obj; }
	bool IsOccupied() { return bOccupied; }
	void SetOccupation(bool state) { bOccupied = state; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AQuantumMesh *Obj;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bOccupied = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
