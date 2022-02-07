// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WWRunnerFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class WW1RUNNERPROJECT_API UWWRunnerFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="WWRCameraManipulations")
	static float CalculateZoomInValue(float armLength, float zoomInSpeed, float minZoomLimit);

	UFUNCTION(BlueprintCallable, Category = "WWRCameraManipulations")
	static float CalculateZoomOutValue(float armLength, float zoomOutSpeed, float maxZoomLimit);

	UFUNCTION(BlueprintCallable, Category = "WWRFunctionLearning")
	static void Learning();

};
