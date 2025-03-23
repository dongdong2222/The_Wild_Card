// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "WildPlayerState.generated.h"

class WildDeck;
/**
 * 
 */
UCLASS()
class THEWILDCARD_API AWildPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	WildDeck* CurrentDeck;
	
};
