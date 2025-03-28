// Fill out your copyright notice in the Description page of Project Settings.


#include "WildUnitBase.h"
#include "Paper2D/Classes/PaperFlipbookComponent.h"
#include "TheWildCard/Map/Tile/WildTileBase.h"
#include "TheWildCard/Map/WildMapManager.h"

void AWildUnitBase::BeginPlay()
{
	Super::BeginPlay();
	GetRenderComponent()->OnClicked.AddDynamic(this, &ThisClass::OnClickedUnit);
}

void AWildUnitBase::OnClickedUnit(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	OnClickedUnitDelegate.Broadcast(this);
}

void AWildUnitBase::MoveToTile(AWildTileBase* Tile)
{
	CurrentTile->SpawnedUnit = nullptr;
	CurrentTile = Tile;
	CurrentCord = Tile->Cordinate;
	CurrentTile->SpawnedUnit = this;
	SetActorLocation(Tile->GetActorLocation());
	AddActorLocalOffset(FVector(0.f, 50.f, 0.f));

	GetGameInstance()->GetSubsystem<UWildMapManager>()->SetAllTileNone();
}

void AWildUnitBase::AttackToTile(AWildTileBase* Tile)
{

}
