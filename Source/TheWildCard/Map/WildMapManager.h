// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WildMapManager.generated.h"

class AWildMapBase;
class AWildTileBase;
class AWildUnitBase;
/**
 * 
 */
UCLASS()
class THEWILDCARD_API UWildMapManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void GenerateMap(TSubclassOf<AWildMapBase> MapClass);
	TArray<AWildTileBase*> GetInjectTiles(AWildUnitBase* Unit);

	UFUNCTION(BlueprintCallable)
	void SetTileSpawnable();
	UFUNCTION(BlueprintCallable)
	void SetTileMoveable(AWildUnitBase* Unit);
	UFUNCTION(BlueprintCallable)
	void SetAllTileNone();


public:
	AWildMapBase* CurrentMap;
	TArray<AWildUnitBase*> Units;
	
};
