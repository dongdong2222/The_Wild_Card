// Fill out your copyright notice in the Description page of Project Settings.


#include "WildWidgetController.h"
#include "TheWildCard/Deck/WildDeckManager.h"

void UWildWidgetController::SetWidgetControllerParams()
{
  DeckManager = GetWorld()->GetGameInstance()->GetSubsystem<UWildDeckManager>();
  BindCallbackToDependencies();
}

void UWildWidgetController::BroadcastInitialValues()
{
}

void UWildWidgetController::BindCallbackToDependencies()
{
  DeckManager.Get()->OnDraw.AddLambda([this](FName CardName) {
    DrawDelegate.Broadcast(CardName);
    });
}
