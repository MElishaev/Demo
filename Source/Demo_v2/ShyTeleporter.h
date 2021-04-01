// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Teleporter.h"
#include "ShyTeleporter.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_V2_API UShyTeleporter : public UTeleporter
{
	GENERATED_BODY()

private:
	float TimeSeen;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TeleportAfter = 1.0f;

public:
	virtual void Teleport(AQuantumMesh *Owner);
};
