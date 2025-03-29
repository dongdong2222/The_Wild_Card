// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WildMapBase.generated.h"

class AWildTileBase;

USTRUCT(BlueprintType, Blueprintable)
struct FGrid
{
	GENERATED_BODY()

public:
	FGrid() 
	{

	}
	FGrid(int32 ColSize)
	{
		Col.Init(nullptr, ColSize);
	}
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<AWildTileBase*> Col;
};


UCLASS()
class THEWILDCARD_API AWildMapBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWildMapBase();

	UFUNCTION()
	void InitMap();

public:
	UPROPERTY(EditAnywhere, Category="Map")
	TSubclassOf<AWildTileBase> TileClass;
	UPROPERTY(EditAnywhere, Category="Map")
	int32 MapSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Map")
	TArray<FGrid> Tiles;

};
