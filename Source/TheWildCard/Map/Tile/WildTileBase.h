// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WildTileBase.generated.h"

class AWildUnitBase;

UENUM()
enum class ETileState
{
	None,
	Spawnable,
	Moveable,
};

UCLASS()
class THEWILDCARD_API AWildTileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWildTileBase();
	
	UFUNCTION(BlueprintCallable)
	void SpawnToTile(TSubclassOf<AWildUnitBase> UnitClass);
	UFUNCTION(BlueprintCallable)
	void SetTileState(ETileState NextState);

	UFUNCTION(BlueprintImplementableEvent)
	void K2_SetNone();
	UFUNCTION(BlueprintImplementableEvent)
	void K2_SetMoveable();
	UFUNCTION(BlueprintImplementableEvent)
	void K2_SetSpawnable();
public:
	TArray<AWildTileBase*> InjectTiles;
	int8 MaxTileCount = 6;
	
	AWildUnitBase* PlacedUnit;
	ETileState TileState;
public:
	//UPROPERTY(EditAnywhere)
	//UMaterial* NoneMaterial;
	//UPROPERTY(EditAnywhere)
	//UMaterial* SpawnableMaterial;
	//UPROPERTY(EditAnywhere)
	//UMaterial* MoveableMaterial;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
