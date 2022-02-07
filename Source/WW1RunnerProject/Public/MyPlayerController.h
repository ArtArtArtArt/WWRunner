// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"

#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class WW1RUNNERPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "WWRCameraManipulations")
	FVector GetMovementLocation(float deltaTime);

protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;

private:
	FVector m_movementDirection = {};

	UPROPERTY(EditAnywhere, Category = "EdgeScroll")
	float minXEdgeScroll = 0.05f;

	UPROPERTY(EditAnywhere, Category = "EdgeScroll")
	float maxXEdgeScroll = 0.95f;

	UPROPERTY(EditAnywhere, Category = "EdgeScroll")
	float minYEdgeScroll = 0.05f;

	UPROPERTY(EditAnywhere, Category = "EdgeScroll")
	float maxYEdgeScroll = 0.95f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float movementSpeed = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Zoom")
	float zoomSpeed = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Zoom")
	float minZoomLimit = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Zoom")
	float maxZoomLimit = 1000.0f;

	USpringArmComponent* m_springArm;

	void MoveForward(float axisValue);
	void MoveRight(float axisValue);
	void ZoomIn();
	void ZoomOut();
	void MouseX(float xValue);
	void MouseY(float yValue);
	void UpdateEdgeScroll();
};
