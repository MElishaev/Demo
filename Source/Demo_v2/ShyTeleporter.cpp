// Fill out your copyright notice in the Description page of Project Settings.


#include "ShyTeleporter.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Puzzle.h"
#include "UtilityFunctions.h"

void UShyTeleporter::Teleport(AQuantumMesh *Owner)
{
    APlayerController *PlayerController = GetWorld()->GetFirstPlayerController();

    FVector Origin;
    FVector BoxExtent;

    Owner->GetActorBounds(false, Origin, BoxExtent);
    if (Owner->WasRecentlyRendered(TeleportCooldown))
    {
        if(!bSeenAlready)
        {
            bSeenAlready = true;
            TimeSeen = GetWorld()->GetTimeSeconds();
            UE_LOG(LogTemp, Warning, TEXT("%s time seen at %f"), *Owner->GetName(), TimeSeen);
            return;
        }

        if(GetWorld()->GetTimeSeconds() - TimeSeen > TeleportAfter)
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
                    bSeenAlready = false;
                }
            }
            bTeleported = false;
        }
    } 
}