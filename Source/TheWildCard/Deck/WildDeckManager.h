// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TheWildCard/Card/CardDataRow.h"
#include "WildDeckManager.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnDraw, FName);

struct FCardDataRow;
class UWildDeck;

UCLASS()
class THEWILDCARD_API UWildDeckManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UWildDeckManager();

	UPROPERTY(BlueprintReadOnly, Category="Deck")
	TArray<UWildDeck*> Decks;

	UPROPERTY(BlueprintReadWrite, Category = "Deck")
	UWildDeck* CurrentDeck;

	FOnDraw OnDraw;

public:
	UFUNCTION(BlueprintCallable)
	void AddDeck(UWildDeck* NewDeck);

	UFUNCTION(BlueprintCallable)
	void MakeDeck(EClassType Class, TArray<FName> CardList);

	UFUNCTION(BlueprintCallable)
	void DrawCard(int Amount);

	UFUNCTION(BlueprintCallable)
	void SelectDeck();

private:
	

};
