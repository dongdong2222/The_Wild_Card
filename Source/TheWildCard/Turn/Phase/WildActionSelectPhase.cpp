// Fill out your copyright notice in the Description page of Project Settings.


#include "WildActionSelectPhase.h"
#include "TheWildCard/GameState/WildGameState.h"
#include "TheWildCard/WildLogChannels.h"

void UWildActionSelectPhase::InitPhase(AWildGameState* P_GameState)
{
  GameState = P_GameState;
}

void UWildActionSelectPhase::StartPhase()
{
  //카드 사용 활성화
  //Force 최대치 증가
  //Force 회복
}

void UWildActionSelectPhase::EndPhase()
{
  UE_LOG(LogPhase, Warning, TEXT("TurnStartPhase End"));
  GameState->SetPhase(GameState->ActionSelectPhase);
}
