// Fill out your copyright notice in the Description page of Project Settings.


#include "WildDeck.h"

UWildDeck::UWildDeck()
  :MaxSize(25)
{
}

void UWildDeck::Shuffle()
{
  for (int i = 0; i < Buffer.Num(); i++)
  {
    int Rand = FMath::RandRange(i, Buffer.Num()-1);
    Buffer.Swap(i, Rand);
  }
}

void UWildDeck::Init(EClassType P_Class, TArray<FName> CardList)
{
  Class = P_Class;
  Deck.Empty();
  Deck.Append(CardList);
}

