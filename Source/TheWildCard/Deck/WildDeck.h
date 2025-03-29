// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TheWildCard/Card/CardDataRow.h"
#include "WildDeck.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class THEWILDCARD_API UWildDeck : public UObject
{
	GENERATED_BODY()
public:
	UWildDeck();

	UFUNCTION()
	void Init(EClassType P_Class, TArray<FName> CardList);
	UFUNCTION()
	FName Draw();

	UFUNCTION()
	void Shuffle();
public:
	UPROPERTY(BlueprintReadOnly)
	EClassType Class;

private:
	int MaxSize;
	TArray<FName> Deck;
	TArray<int> Buffer;
};
