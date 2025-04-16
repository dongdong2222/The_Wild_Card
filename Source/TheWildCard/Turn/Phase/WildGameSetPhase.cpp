// Fill out your copyright notice in the Description page of Project Settings.


#include "WildGameSetPhase.h"
#include "TheWildCard/WildLogChannels.h"
#include "TheWildCard/GameState/WildGameState.h"
#include "TheWildCard/Deck/WildDeckManager.h"
#include "TheWildCard/Deck/WildDeck.h"
#include "Blueprint/UserWidget.h"



void UWildGameSetPhase::InitPhase(AWildGameState* P_GameState)
{
  GameState = P_GameState;
}



void UWildGameSetPhase::StartPhase()
{
  if (!GameState) return;
  UE_LOG(LogPhase, Warning, TEXT("GamesetPhase Start"));
  UWildDeckManager* DeckManager = GetWorld()->GetGameInstance()->GetSubsystem<UWildDeckManager>();
  DeckManager->CurrentDeck->Shuffle();
  DeckManager->DrawCard(4);

  if (!IsValid(GameSetWidgetClass)) return;
  GameSetWidget = CreateWidget<UUserWidget>(GetWorld(), GameSetWidgetClass);

  if (GameSetWidget)
  {
    GameSetWidget->AddToViewport();
    // TODO : PlayerController�� �Է��� UI����
    
  }


}

void UWildGameSetPhase::EndPhase()
{
  UE_LOG(LogPhase, Warning, TEXT("GamesetPhase End"));
  //�ָ��� �̱�
  GameState->SetPhase(GameState->TurnStartPhase);

}
