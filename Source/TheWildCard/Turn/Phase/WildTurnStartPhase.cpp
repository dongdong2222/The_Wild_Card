// Fill out your copyright notice in the Description page of Project Settings.


#include "WildTurnStartPhase.h"
#include "TheWildCard/GameState/WildGameState.h"
#include "TheWildCard/Deck/WildDeckManager.h"
#include "TheWildCard/WildLogChannels.h"


void UWildTurnStartPhase::InitPhase(AWildGameState* P_GameState)
{
  GameState = P_GameState;
}

void UWildTurnStartPhase::StartPhase()
{
  //턴 시작시 효과 발동
  OnTurnStart.Broadcast();
  UWildDeckManager* DeckManager = GetWorld()->GetGameInstance()->GetSubsystem<UWildDeckManager>();
  DeckManager->DrawCard(1);
  //Draw() player1
  //Draw() player2
  EndPhase();
}

void UWildTurnStartPhase::EndPhase()
{
  UE_LOG(LogPhase, Warning, TEXT("TurnStartPhase End"));
  GameState->SetPhase(GameState->ActionSelectPhase);
}
