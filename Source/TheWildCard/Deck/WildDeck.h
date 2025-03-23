// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TheWildCard/Card/CardDataRow.h"
#include "WildDeck.generated.h"

/**
 * 
 */
UCLASS()
class THEWILDCARD_API UWildDeck : public UObject
{
	GENERATED_BODY()
public:
	UWildDeck();

	//UFUNCTION()
	//void Init();
	//UFUNCTION()
	//FCardDataRow Draw();
	//UFUNCTION()
	//void Shuffle();
public:
	EClassType Class;

private:
	int MaxSize;
	TArray<FCardDataRow> Deck;
	TArray<int> Buffer;
};
