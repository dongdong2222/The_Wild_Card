// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "WildUnitBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClickedUnitSignature, AWildUnitBase*, Unit);

class AWildTileBase;
/**
 * 
 */
UCLASS()
class THEWILDCARD_API AWildUnitBase : public APaperFlipbookActor
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
public:
	UPROPERTY(BlueprintReadOnly)
	AWildTileBase* CurrentTile;
	TPair<int, int> CurrentCord;
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnClickedUnitSignature OnClickedUnitDelegate;
public:
	UFUNCTION()
	void OnClickedUnit(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

	UFUNCTION(BlueprintCallable)
	void MoveToTile(AWildTileBase* Tile);
	UFUNCTION(BlueprintCallable)
	void AttackToTile(AWildTileBase* Tile);
};
