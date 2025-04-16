// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "WildGameState.generated.h"

class IWildTurnState;
class UWildGameSetPhase;
class UWildTurnStartPhase;
class APlayerController;
class AWildMapBase;
class AWildUnitBase;
/**
 * 
 */
UCLASS()
class THEWILDCARD_API AWildGameState : public AGameState
{
	GENERATED_BODY()
public:
	AWildGameState();
	//implement of AGameState
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//End of AGameState

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void InitPlayers(APlayerController* p1, APlayerController* p2);
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void StartGame();
	void SetPhase(IWildTurnState* NextPhase);

	UFUNCTION(BlueprintCallable)
	void EndPhase();


public:
	UPROPERTY(EditAnywhere, Category="Phase")
	TSubclassOf<UWildGameSetPhase> GameSetPhaseClass;
	UPROPERTY(EditAnywhere, Category = "Phase")
	TSubclassOf<UWildTurnStartPhase> TurnStartPhaseClass;
	UPROPERTY(EditAnywhere, Category = "Phase")
	TSubclassOf<UWildGameSetPhase> ActionSelectPhaseClass;
	UPROPERTY(EditAnywhere, Category = "Phase")
	TSubclassOf<UWildGameSetPhase> ActionPhaseClass;
	UPROPERTY(EditAnywhere, Category = "Phase")
	TSubclassOf<UWildGameSetPhase> GameEndPhaseClass;
	UPROPERTY(EditAnywhere, Category = "Map")
	TSubclassOf<AWildMapBase> MapClass;
	UPROPERTY(EditAnywhere, Category = "Player")
	TSubclassOf<AWildUnitBase> PlayerUnitClass;

	IWildTurnState* GameSetPhase;
	IWildTurnState* TurnStartPhase;
	IWildTurnState* ActionSelectPhase;
	IWildTurnState* ActionPhase;
	IWildTurnState* GameEndPhase;

	//Phases
	IWildTurnState* CurrentPhase;
	
	UPROPERTY()
	APlayerController* Player1;
	APlayerController* Player2;
};
