// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WildMapBase.generated.h"

class AWildTileBase;

UCLASS()
class THEWILDCARD_API AWildMapBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWildMapBase();
	TArray<TArray<AWildTileBase>> Tiles;
public:
	UPROPERTY(EditAnywhere, Category="Map")
	TSubclassOf<AWildTileBase> TileClass;
	UPROPERTY(EditAnywhere, Category="Map")
	int32 MapSize;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	


};
