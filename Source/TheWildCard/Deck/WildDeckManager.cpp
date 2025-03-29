// Fill out your copyright notice in the Description page of Project Settings.


#include "WildDeckManager.h"
#include "TheWildCard/Deck/WildDeck.h"
#include "TheWildCard/Card/CardDataRow.h"



UWildDeckManager::UWildDeckManager()
{
  TArray<FName> Cards;
  for (int i = 0; i < 10; i++)
  {
    Cards.Add("1c_sample");
  }
  MakeDeck(EClassType::Warrior, Cards);
  SelectDeck();
}

void UWildDeckManager::AddDeck(UWildDeck* NewDeck)
{
  if (!NewDeck) return;
  Decks.Add(NewDeck);
}

void UWildDeckManager::MakeDeck(EClassType Class, TArray<FName> CardList)
{
  UWildDeck* Deck = NewObject<UWildDeck>();
  Deck->Init(Class, CardList);
  AddDeck(Deck);
}

void UWildDeckManager::DrawCard(int Amount)
{
  if (!CurrentDeck) return;
  for (int i = 0; i < Amount; i++)
  {
    FName CardName = CurrentDeck->Draw();
    OnDraw.Broadcast(CardName);
    
  }
}

void UWildDeckManager::SelectDeck()
{
  CurrentDeck = Decks[0];
}
