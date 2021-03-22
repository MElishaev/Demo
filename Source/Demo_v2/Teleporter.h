// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Teleporter.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class DEMO_V2_API UTeleporter : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTeleporter();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bTeleported = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bSeenAlready = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float TeleportCooldown = 0.2f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void Teleport(AQuantumMesh *Owner);
};
