// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TheWildCard/Turn/WildTurnState.h"
#include "WildTurnStartPhase.generated.h"

/**
 * 
 */
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTurnStart, int32, i);


UCLASS()
class THEWILDCARD_API UWildTurnStartPhase : public UObject, public IWildTurnState
{
	GENERATED_BODY()
public:
	//implement of IWildTurnState
	virtual void InitPhase(AWildGameState* GameState) override;
	virtual void StartPhase() override;
	virtual void EndPhase() override;
	//End of IWildTurnState

private:
	AWildGameState* GameState;
	//FOnTurnStart OnTurnStart;

	
};
