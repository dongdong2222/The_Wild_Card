// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WildDeckManager.generated.h"

struct FCardDataRow;
class UWildDeck;

UCLASS()
class THEWILDCARD_API UWildDeckManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	TArray<UWildDeck*> Decks;

public:
	UFUNCTION(BlueprintCallable)
	void AddDeck(UWildDeck* NewDeck);

private:

	//UDeck* CurrentDeck;

	
};
