// Fill out your copyright notice in the Description page of Project Settings.


#include "WildDeckManager.h"
#include "TheWildCard/Card/CardDataRow.h"


//UDeck::UDeck()
//  :maxSize(25)
//{
//}
//void UDeck::Init()
//{
//  Buffer.Empty();
//  for (int i = 0; i < maxSize; i++)
//  {
//    Buffer.Add(i);
//  }
//  Shuffle();
//}
//FCardDataRow UDeck::Draw()
//{
//  int idx =  Buffer.Last();
//  Buffer.Pop();
//  return Deck[idx];
//}
//void UDeck::Shuffle()
//{
//  for (int i = 0; i < Buffer.Num(); i++)
//  {
//    int Rand = FMath::RandRange(i, Buffer.Num()-1);
//    Buffer.Swap(i, Rand);
//  }
//}

void UWildDeckManager::AddDeck(UWildDeck* NewDeck)
{
  if (!NewDeck) return;
  Decks.Add(NewDeck);
}
