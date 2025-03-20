// Fill out your copyright notice in the Description page of Project Settings.


#include "WildTurnStartPhase.h"
#include "TheWildCard/GameState/WildGameState.h"
#include "TheWildCard/WildLogChannels.h"


void UWildTurnStartPhase::InitPhase(AWildGameState* P_GameState)
{
  GameState = P_GameState;
}

void UWildTurnStartPhase::StartPhase()
{

}

void UWildTurnStartPhase::EndPhase()
{
  UE_LOG(LogPhase, Warning, TEXT("TurnStartPhase End"));
  GameState->SetPhase(GameState->TurnStartPhase);
}
