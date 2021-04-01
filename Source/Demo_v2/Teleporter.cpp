// Fill out your copyright notice in the Description page of Project Settings.


#include "Teleporter.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Puzzle.h"
#include "UtilityFunctions.h"

// Sets default values for this component's properties
UTeleporter::UTeleporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTeleporter::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTeleporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UTeleporter::Teleport(AQuantumMesh *Owner)
{
	APlayerController *PlayerController = GetWorld()->GetFirstPlayerController();

	FVector Origin;
	FVector BoxExtent;

	Owner->GetActorBounds(false, Origin, BoxExtent);

	if (Owner->WasRecentlyRendered(TeleportCooldown))
	{
		UE_LOG(LogTemp, Warning, TEXT("Was recently rendered"));
		bSeenAlready = true;
		bTeleported = false;
		return;
	}

	// for(int i=-1; i <= 1; i+=2)
	// 	for(int j=-1; j <= 1; j+=2)
	// 		for(int k=-1; k <= 1; k+=2)
	// 		{
	// 			FVector vertex = Origin + FVector(i*BoxExtent.X, j*BoxExtent.Y, k*BoxExtent.Z);
	// 			FVector CameraLocation = PlayerController->PlayerCameraManager->GetCameraLocation();
	// 			FVector CameraForwardVector = PlayerController->PlayerCameraManager->GetCameraRotation().Vector();
	// 		}

	// choose the destination of teleportation
	if (bSeenAlready && !bTeleported)
	{
		APuzzle *Puzzle = Owner->GetPuzzleParent();
		if (IsValid(Puzzle))
		{
			ATeleportationSpot *Spot = Puzzle->FindEmptySpot(BoxExtent);

			if (Spot != NULL && Puzzle->CaptureMeshSpot(Spot, Owner))
			{
				UE_LOG(LogTemp, Warning, TEXT("Teleported %s to %s"), *Owner->GetName(), *Spot->GetActorLocation().ToString());
				Owner->SetActorLocation(Spot->GetActorLocation());
				bTeleported = true;
			}
		}
	}
}
