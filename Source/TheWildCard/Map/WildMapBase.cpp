// Fill out your copyright notice in the Description page of Project Settings.


#include "WildMapBase.h"
#include "TheWildCard/Map/Tile/WildTileBase.h"

// Sets default values
AWildMapBase::AWildMapBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AWildMapBase::InitMap()
{
	Tiles.Init(FGrid(MapSize), MapSize);
	//Tile Spawn
	double Dx = 200.f;
	double Dy = 150.f;
	for (int i = 0; i < MapSize; i++)
	{
		for (int j = 0; j < MapSize; j++) {
			AWildTileBase* Tile = GetWorld()->SpawnActor<AWildTileBase>(
				TileClass,
				FVector((double)(Dx * j), 0.f, (double)(Dy * i)),
				FRotator::ZeroRotator
			);
			Tile->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
			Tile->Cordinate = TPair<int, int>(i, j);
			Tiles[i].Col[j] = Tile;
		}
	}

}





