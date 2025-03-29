// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WildTileBase.generated.h"

class AWildUnitBase;

UENUM(BlueprintType)
enum class ETileState : uint8
{
	None,
	Spawnable,
	Moveable,
	Attackable
};

UCLASS()
class THEWILDCARD_API AWildTileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWildTileBase();
	
	//UFUNCTION(BlueprintCallable)
	//void SpawnToTile(TSubclassOf<AWildUnitBase> UnitClass);
	UFUNCTION(BlueprintCallable)
	void SetTileState(ETileState NextState);

	UFUNCTION(BlueprintImplementableEvent)
	void K2_SetNone();
	UFUNCTION(BlueprintImplementableEvent)
	void K2_SetMoveable();
	UFUNCTION(BlueprintImplementableEvent)
	void K2_SetSpawnable();
	UFUNCTION(BlueprintImplementableEvent)
	void K2_SetAttackable();
public:
	//TArray<AWildTileBase*> InjectTiles;
	//int8 MaxTileCount = 6;
	
	AWildUnitBase* SpawnedUnit;
	TPair<int, int> Cordinate;
	UPROPERTY(BlueprintReadOnly)
	ETileState CurrentState;


};
