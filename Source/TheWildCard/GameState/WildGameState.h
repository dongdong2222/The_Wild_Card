// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "WildGameState.generated.h"

class IWildTurnState;
class UWildGameSetPhase;
class APlayerController;

/**
 * 
 */
UCLASS()
class THEWILDCARD_API AWildGameState : public AGameState
{
	GENERATED_BODY()
public:
	//implement of AGameState
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//End of AGameState

	void StartGame();
	void SetPhase(IWildTurnState* NextPhase);

	UFUNCTION(BlueprintCallable)
	void EndPhase();


public:
	UPROPERTY(EditAnywhere, Category="Phase")
	TSubclassOf<UWildGameSetPhase> GameSetPhaseClass;
	UPROPERTY(EditAnywhere, Category = "Phase")
	TSubclassOf<UWildGameSetPhase> TurnStartPhaseClass;
	UPROPERTY(EditAnywhere, Category = "Phase")
	TSubclassOf<UWildGameSetPhase> ActionSelectPhaseClass;
	UPROPERTY(EditAnywhere, Category = "Phase")
	TSubclassOf<UWildGameSetPhase> ActionPhaseClass;
	UPROPERTY(EditAnywhere, Category = "Phase")
	TSubclassOf<UWildGameSetPhase> GameEndPhaseClass;

	IWildTurnState* GameSetPhase;
	IWildTurnState* TurnStartPhase;
	IWildTurnState* ActionSelectPhase;
	IWildTurnState* ActionPhase;
	IWildTurnState* GameEndPhase;

	//Phases
	IWildTurnState* CurrentPhase;

	AController* FirstPlayer;
	AController* SecondPlayer;


	
};
