// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);
	InputComponent->BindAction("ZoomIn", IE_Pressed, this, &AMyPlayerController::ZoomIn);
	InputComponent->BindAction("ZoomOut", IE_Pressed, this, &AMyPlayerController::ZoomOut);
	InputComponent->BindAxis("MouseX", this, &AMyPlayerController::MouseX);
	InputComponent->BindAxis("MouseY", this, &AMyPlayerController::MouseY);
}

void AMyPlayerController::BeginPlay()
{
	m_springArm = GetPawn()->FindComponentByClass<USpringArmComponent>();
	this->APlayerController::bShowMouseCursor = true;
}

void AMyPlayerController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}

FVector AMyPlayerController::GetMovementLocation(float deltaTime)
{ 
	const FVector oldLocation = GetPawn()->GetActorLocation();
	return oldLocation + (m_movementDirection * deltaTime * movementSpeed);
}

void AMyPlayerController::MoveForward(float axisValue)
{
	m_movementDirection.X = FMath::Clamp(axisValue, -1.0f, 1.0f);
}

void AMyPlayerController::MoveRight(float axisValue)
{
	m_movementDirection.Y = FMath::Clamp(axisValue, -1.0f, 1.0f);
}

void AMyPlayerController::ZoomIn()
{
	m_springArm->TargetArmLength = FMath::Clamp(m_springArm->TargetArmLength - zoomSpeed, minZoomLimit, maxZoomLimit);
}

void AMyPlayerController::ZoomOut()
{
	m_springArm->TargetArmLength = FMath::Clamp(m_springArm->TargetArmLength + zoomSpeed, minZoomLimit, maxZoomLimit);
}

void AMyPlayerController::MouseX(float xValue)
{
	UpdateEdgeScroll();
}

void AMyPlayerController::MouseY(float yValue)
{
	UpdateEdgeScroll();
}

void UpdateMovementDirectionComponentValue(float & outParam, float coef, float posRatio, float min, float max)
{
	if (posRatio > max) { outParam = coef; }
	else if (posRatio < min) { outParam = -coef; }
}

//TODO: if mouse is out of bounds - still remember the last position and use it to move the camera
void AMyPlayerController::UpdateEdgeScroll()
{
	float mx, my;
	if (GetMousePosition(mx, my))
	{
		int vpx, vpy;
		GetViewportSize(vpx, vpy);

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Mx : %f\t My : %f"), mx, my));
	
		UpdateMovementDirectionComponentValue(m_movementDirection.Y, 1.0f, mx / vpx, minXEdgeScroll, maxXEdgeScroll);
		UpdateMovementDirectionComponentValue(m_movementDirection.X, -1.0f, my / vpy, minYEdgeScroll, maxYEdgeScroll);
	}
}