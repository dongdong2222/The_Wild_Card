// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TheWildCard/Turn/WildTurnState.h"
#include "WildActionSelectPhase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class THEWILDCARD_API UWildActionSelectPhase : public UObject, public IWildTurnState
{
	GENERATED_BODY()
public:
	//implement of IWildTurnState
	virtual void InitPhase(AWildGameState* GameState) override;
	virtual void StartPhase() override;
	virtual void EndPhase() override;
	//End of IWildTurnState
public:

private:
	AWildGameState* GameState;
};
