// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilityFunctions.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_V2_API UUtilityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Utilities")
	static bool IsBoxOnScreen(UWorld *World, FVector Origin, FVector BoxExtent);
};
