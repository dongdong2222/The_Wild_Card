// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WildUnitManager.generated.h"

class AWildUnitBase;
class AWildTileBase;


/**
 * 
 */
UCLASS()
class THEWILDCARD_API UWildUnitManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SpawnUnitToTile(TSubclassOf<AWildUnitBase> UnitClass, AWildTileBase* Tile);
	UFUNCTION(BlueprintCallable)
	void SpawnUnitByCord(TSubclassOf<AWildUnitBase> UnitClass, int x, int y);
public:
	TArray<AWildUnitBase*> PlayerUnits;
	TArray<AWildUnitBase*> EnemyUnits;
	
	UPROPERTY(BlueprintReadWrite)
	AWildUnitBase* SelectedUnit;
	
};
