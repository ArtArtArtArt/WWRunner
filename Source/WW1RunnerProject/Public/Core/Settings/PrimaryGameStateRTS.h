// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Misc/DateTime.h"
#include "PrimaryGameStateRTS.generated.h"

/**
 * 
 */
UCLASS()
class WW1RUNNERPROJECT_API APrimaryGameStateRTS : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	APrimaryGameStateRTS();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float deltaTime) override;

protected:
	//TODO: add controller ref

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calendar");
	int Years = 2020;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calendar");
	int Months = 7;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calendar");
	int Days = 25;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calendar");
	int DayOfWeek = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calendar");
	int DayCounter = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clock");
	int Hours = 13;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clock");
	int Minutes = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clock");
	int Seconds = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speed Settings");
	float GameSpeed = 60;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speed Settings");
	float GameTime = Hours + (Minutes / float(60.0f)) + (Seconds / float(3600.0f));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speed Settings");
	FDateTime DateTimeStruct = {Years, Months, Days, Hours, Minutes, Seconds};

	UFUNCTION(BlueprintCallable, Category = "Game Time")
	virtual void CalculateTime(float deltaTime, float currentGameSpeed, float gameTimeIn, float& gameTimeOut, int& dayCountOut);

	UFUNCTION(BlueprintCallable, Category = "Game Time")
	virtual void SetClockCalendar();

	UFUNCTION(BlueprintCallable, Category = "Game Time")
	virtual void SetDateTime(UPARAM(ref) int &Year, UPARAM(ref) int& Month, UPARAM(ref) int& Day, UPARAM(ref) int& Hour, UPARAM(ref) int& Minute, UPARAM(ref) int& Second);

};
