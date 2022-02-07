// Fill out your copyright notice in the Description page of Project Settings.


#include "WWRunnerFunctionLibrary.h"
#include "E:\UnrealEngine\UE_4.27\Engine\Source\Runtime\SlateCore\Public\Widgets\SWindow.h"

//TODO: clamp should be used here

float UWWRunnerFunctionLibrary::CalculateZoomInValue(float armLength, float zoomInSpeed, float minZoomLimit)
{
	return armLength - zoomInSpeed < minZoomLimit ? minZoomLimit : armLength - zoomInSpeed;
}

float UWWRunnerFunctionLibrary::CalculateZoomOutValue(float armLength, float zoomOutSpeed, float maxZoomLimit)
{
	return armLength + zoomOutSpeed > maxZoomLimit ? maxZoomLimit : armLength + zoomOutSpeed;
}

void UWWRunnerFunctionLibrary::Learning()
{
	FVector2D viewportSize;
	GEngine->GameViewport->GetViewportSize(viewportSize);
}
