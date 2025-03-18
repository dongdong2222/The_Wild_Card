// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "CardDataRow.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ECardType : uint8
{
  Unit,
  Item,
  Spell,
  Tao,
  Nature
};

USTRUCT(BlueprintType)
struct FCardDataRow : public FTableRowBase
{
  GENERATED_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FName CardName;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FName Eng_CardName;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  ECardType CardType;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int32 Forse;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int32 Intelligence;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int32 Damage;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int32 Health;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FGameplayTagContainer CardTags;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FGameplayTagContainer AbilityTags;

  //for Widget
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  UTexture2D* Illust;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TSubclassOf<AActor> UnitClass;
};
