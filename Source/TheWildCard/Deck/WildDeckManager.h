// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WildDeckManager.generated.h"

struct FCardDataRow;
class UWildDeck;

UCLASS()
class THEWILDCARD_API UWildDeckManager : public UObject
{
	GENERATED_BODY()
public:
	static UWildDeckManager* GetInstance();

	TArray<UWildDeck*> Decks;




	\


private:
	static UWildDeckManager* Instance;

	//UDeck* CurrentDeck;

	
};
