// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "WildUnitBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClickedUnit, AWildUnitBase*, Unit);

class AWildTileBase;
/**
 * 
 */
UCLASS()
class THEWILDCARD_API AWildUnitBase : public APaperFlipbookActor
{
	GENERATED_BODY()
public:
	AWildTileBase* CurrentTile;
	TPair<int, int> CurrentCord;
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnClickedUnit OnClickedUnit;
};
