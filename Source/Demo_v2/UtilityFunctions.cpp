// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityFunctions.h"
#include "Engine/World.h"

bool UUtilityFunctions::IsBoxOnScreen(UWorld* World, FVector Origin, FVector BoxExtent)
{
    // below method doesnt work well with 3rd person character occluding the quantum object
    // still will save it incase will move to 1st person
    APlayerController *PlayerController = World->GetFirstPlayerController();
    
    if(!PlayerController)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s :: Couldn't find player controller"), __FUNCTION__);
        return false;
    }

    for (int i = -1; i <= 1; i += 2)
        for (int j = -1; j <= 1; j += 2)
            for (int k = -1; k <= 1; k += 2)
            {
                FVector vertex = Origin + FVector(i * BoxExtent.X, j * BoxExtent.Y, k * BoxExtent.Z);

                FVector2D screenCoords;
                int32 viewportX;
                int32 viewportY;
                PlayerController->GetViewportSize(viewportX, viewportY);
                PlayerController->ProjectWorldLocationToScreen(vertex, screenCoords);

                if (screenCoords.X > 0 && screenCoords.Y > 0 &&
                	screenCoords.X < viewportX && screenCoords.Y < viewportY)
                {
                    return true;
                }
            }

    return false;
}