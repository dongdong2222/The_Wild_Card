// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "WildTurnState.generated.h"

class AWildGameState;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWildTurnState : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class THEWILDCARD_API IWildTurnState
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void InitPhase(AWildGameState* GameState) = 0;
	virtual void StartPhase() = 0;
	virtual void EndPhase() = 0;
};
