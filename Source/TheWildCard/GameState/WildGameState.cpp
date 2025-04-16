// Fill out your copyright notice in the Description page of Project Settings.


#include "WildGameState.h"
#include "TheWildCard/Turn/WildTurnState.h"
#include "TheWildCard/Turn/Phase/WildGameSetPhase.h"
#include "TheWildCard/Turn/Phase/WildTurnStartPhase.h"
#include "TheWildCard/Map/WildMapManager.h"
#include "TheWildCard/Unit/WildUnitManager.h"

AWildGameState::AWildGameState()
{
  PrimaryActorTick.bCanEverTick = true;
  bReplicates = false;
}

void AWildGameState::BeginPlay()
{
  GameSetPhase = NewObject<UWildGameSetPhase>(this, GameSetPhaseClass);
  GameSetPhase->InitPhase(this);
  TurnStartPhase = NewObject<UWildTurnStartPhase>(this, TurnStartPhaseClass);
  TurnStartPhase->InitPhase(this);
  //TurnStartPhase;
  //ActionSelectPhase;
  //ActionPhase;
  //GameEndPhase

  //StartGame();
}

void AWildGameState::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
  if (!CurrentPhase) return;
  if (!IsValid(GEngine)) return;
  UE_LOG(LogTemp, Warning, TEXT("Warning"));
  //GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Blue, TEXT("Test"));
  //GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Blue, *Cast<UObject>(CurrentPhase)->GetClass()->GetName());
}

void AWildGameState::InitPlayers_Implementation(APlayerController* p1, APlayerController* p2)
{
	Player1 = p1;
	Player2 = p2;
}



void AWildGameState::StartGame_Implementation()
{
  //선 후공 정하기
	if (HasAuthority())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("StartGame in GameState"));
	}
  //Map 생성
  GetGameInstance()->GetSubsystem<UWildMapManager>()->GenerateMap(MapClass);
  //플레이어 생성
  GetGameInstance()->GetSubsystem<UWildUnitManager>()->SpawnUnitByCord(PlayerUnitClass, 1, 8);

  //GameSetPhase 시작
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
