// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WildTurnManager.generated.h"


UENUM(BlueprintType)
enum class EPhase : uint8
{
	GameSet,
	TurnStart,
	ActionSelect,
	Action
};

UCLASS()
class THEWILDCARD_API UWildTurnManager : public UObject
{
	GENERATED_BODY()
public:
	static UWildTurnManager* GetInstance();
private:
	static UWildTurnManager* Instance;

	UPROPERTY()
	int Turn; // 1 : player1 2: player2

	

	


};
