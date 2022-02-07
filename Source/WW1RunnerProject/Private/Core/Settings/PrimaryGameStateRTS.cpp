// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Settings/PrimaryGameStateRTS.h"

APrimaryGameStateRTS::APrimaryGameStateRTS()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void APrimaryGameStateRTS::BeginPlay()
{
	Super::BeginPlay();
}

void APrimaryGameStateRTS::Tick(float deltaTime)
{
	if (GameSpeed != 0)
	{
		CalculateTime(deltaTime, GameSpeed, GameTime, GameTime, DayCounter);
		SetClockCalendar();
	}
	Super::Tick(deltaTime);
}

void APrimaryGameStateRTS::CalculateTime(float deltaTime, float currentGameSpeed, float gameTimeIn, float& gameTimeOut, int& dayCounterOut)
{
	GameTime = fmod(((deltaTime / currentGameSpeed) + gameTimeIn), 24.0);
	DayCounter = ((deltaTime / currentGameSpeed) + gameTimeIn), 24.0;
	gameTimeOut = GameTime; // FOR BP USE ONLY
	dayCounterOut = DayCounter; // FOR BP USE ONLY
}

void APrimaryGameStateRTS::SetClockCalendar()
{
	float InitialConversion = GameTime * 3600.0f;
	Seconds = floor(fmod(InitialConversion, 60));
	Minutes = floor(fmod(int(InitialConversion / 60), 60.0));
	Hours = floor(fmod((int(InitialConversion / 60) / 60), 24.0));

	DayOfWeek += DayCounter;
	if (DayOfWeek > 7)
	{
		DayOfWeek = 1;
	}

	Days += DayCounter;
	if (Days > FDateTime::DaysInMonth(Years, Months))
	{
		Days = 1;
		Months++;
	}

	if (Months > 12)
	{
		Months = 1;
		Years++;
	}
	SetDateTime(Years, Months, Days, Hours, Minutes, Seconds);
}

void APrimaryGameStateRTS::SetDateTime(UPARAM(ref) int& Year, UPARAM(ref) int& Month, UPARAM(ref) int& Day, UPARAM(ref) int& Hour, UPARAM(ref) int& Minute, UPARAM(ref) int& Second)
{
	DateTimeStruct = { Year, Month, Day, Hour, Minute, Second };
}
