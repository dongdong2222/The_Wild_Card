// Fill out your copyright notice in the Description page of Project Settings.


#include "WildMapManager.h"
#include "TheWildCard/Map/WildMapBase.h"
#include "TheWildCard/Unit/WildUnitBase.h"
#include "TheWildCard/Map/Tile/WildTileBase.h"

void UWildMapManager::GenerateMap(TSubclassOf<AWildMapBase> MapClass)
{
  CurrentMap = GetWorld()->SpawnActor<AWildMapBase>(
    MapClass,
    FVector::ZeroVector,
    FRotator::ZeroRotator
  );
  if (!CurrentMap) return;
  CurrentMap->InitMap();
}

TArray<AWildTileBase*> UWildMapManager::GetInjectTiles(AWildUnitBase* Unit)
{
  int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
  int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
  TArray<AWildTileBase*> InjectTiles;

  AWildTileBase* UnitTile = Unit->CurrentTile;
  for (int i = 0; i < 8; i++)
  {
    int nx = Unit->CurrentCord.Key + dx[i];
    int ny = Unit->CurrentCord.Value + dy[i];
    if (nx < 0 || nx >= CurrentMap->MapSize || ny < 0 || ny >= CurrentMap->MapSize) continue;
    InjectTiles.Add(CurrentMap->Tiles[nx].Col[ny]);
  }

  return InjectTiles;
}

void UWildMapManager::SetTileSpawnable()
{
  for (int i = 0; i < Units.Num(); i++)
  {
    TArray<AWildTileBase*> InjectTiles = GetInjectTiles(Units[i]);
    for (int j = 0; j < InjectTiles.Num(); j++)
    {
      InjectTiles[j]->SetTileState(ETileState::Spawnable);
    }
  }
}

//선택한 Unit의 주변만 Moveable로 바꿔줌
void UWildMapManager::SetTileMoveable(AWildUnitBase* Unit)
{
  TArray<AWildTileBase*> InjectTiles = GetInjectTiles(Unit);
  for (int i = 0; i < InjectTiles.Num(); i++)
  {
    InjectTiles[i]->SetTileState(ETileState::Moveable);
  }
}

void UWildMapManager::SetAllTileNone()
{
  for (int x = 0; x < CurrentMap->MapSize; x++)
  {
    for (int y = 0; y < CurrentMap->MapSize; y++)
    {
      CurrentMap->Tiles[x].Col[y]->SetTileState(ETileState::None);
    }
  }
}
