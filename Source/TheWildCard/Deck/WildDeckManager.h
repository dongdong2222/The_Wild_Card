// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WildDeckManager.generated.h"

struct FCardDataRow;
//UCLASS()
//class UDeck : public UObject
//{
//	GENERATED_BODY()
//public:
//	//UDeck();
//
//	UFUNCTION()
//	void Init();
//	UFUNCTION()
//	FCardDataRow Draw();
//	UFUNCTION()
//	void Shuffle();
//
//private:
//	int maxSize;
//	TArray<FCardDataRow> Deck;
//	TArray<int> Buffer;
//};
/**
 * 
 */
UCLASS()
class THEWILDCARD_API UWildDeckManager : public UObject
{
	GENERATED_BODY()
public:
	static UWildDeckManager* GetInstance();

private:
	static UWildDeckManager* Instance;

	//UDeck* CurrentDeck;

	
};
