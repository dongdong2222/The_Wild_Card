// Fill out your copyright notice in the Description page of Project Settings.


#include "WildGameState.h"
#include "TheWildCard/Turn/WildTurnState.h"
#include "TheWildCard/Turn/Phase/WildGameSetPhase.h"

void AWildGameState::BeginPlay()
{
  GameSetPhase = NewObject<UWildGameSetPhase>(this, GameSetPhaseClass);
  GameSetPhase->InitPhase(this);
  //TurnStartPhase;
  //ActionSelectPhase;
  //ActionPhase;
  //GameEndPhase;



  StartGame();
}

void AWildGameState::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
  //GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Blue, FString::Printf("CurrentState : %s", *CurrentPhase->_getUObject()->StaticConfigName));
}

void AWildGameState::StartGame()
{
  //�� �İ� ���ϱ�


  SetPhase(GameSetPhase);
}

void AWildGameState::SetPhase(IWildTurnState* NextPhase)
{
  if (!NextPhase) return;
  CurrentPhase = NextPhase;
  CurrentPhase->StartPhase();
}

void AWildGameState::EndPhase()
{
  CurrentPhase->EndPhase();
}

void AWildGameState::SetInterface(TScriptInterface<IWildTurnState> NewInterface)
{

}