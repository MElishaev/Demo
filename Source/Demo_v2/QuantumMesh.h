// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teleporter.h"
#include "QuantumMesh.generated.h"

UCLASS()
class DEMO_V2_API AQuantumMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuantumMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	APuzzle* PuzzleParent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	APuzzle *GetPuzzleParent() { return PuzzleParent; }

	float GetTeleportationCooldown();

	// TODO: maybe can delete, the BP API create their setters and getters
	UFUNCTION(BlueprintCallable) void SetPuzzleParent(APuzzle *Parent)
	{
		PuzzleParent = Parent;
	}
};
