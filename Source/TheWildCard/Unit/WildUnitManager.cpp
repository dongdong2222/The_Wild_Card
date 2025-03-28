// Fill out your copyright notice in the Description page of Project Settings.


#include "WildUnitManager.h"
#include "TheWildCard/Map/Tile/WildTileBase.h"
#include "TheWildCard/Unit/WildUnitBase.h"
#include "TheWildCard/Map/WildMapManager.h"

void UWildUnitManager::SpawnUnitToTile(TSubclassOf<AWildUnitBase> UnitClass, AWildTileBase* Tile)
{
	if (!IsValid(UnitClass) && !Tile) return;
	AWildUnitBase* Unit = GetWorld()->SpawnActor<AWildUnitBase>(
		UnitClass,
		Tile->GetActorLocation(),
		FRotator::ZeroRotator
	);
	Unit->AddActorLocalOffset(FVector(0.f, 50.f, 0.f));
	Unit->CurrentTile = Tile;
	Unit->CurrentCord = Tile->Cordinate;

	PlayerUnits.Add(Unit);
}

void UWildUnitManager::SpawnUnitByCord(TSubclassOf<AWildUnitBase> UnitClass, int x, int y)
{
	if (!IsValid(UnitClass)) return;
	AWildTileBase* Tile = GetWorld()->GetGameInstance()->GetSubsystem<UWildMapManager>()->GetTileWithCord(x, y);
	SpawnUnitToTile(UnitClass, Tile);
}
