// Fill out your copyright notice in the Description page of Project Settings.


#include "WildTileBase.h"
#include "TheWildCard/Unit/WildUnitBase.h"

// Sets default values
AWildTileBase::AWildTileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentState = ETileState::None;
}

//void AWildTileBase::SpawnToTile(TSubclassOf<AWildUnitBase> UnitClass)
//{
//	//if (TileState != ETileState::Spawnable) return;
//	AWildUnitBase* Unit = GetWorld()->SpawnActor<AWildUnitBase>(
//		UnitClass,
//		GetActorLocation(),
//		FRotator::ZeroRotator
//	);
//	Unit->AddActorLocalOffset(FVector(0.f, 50.f, 0.f));
//	Unit->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
//	CurrentState = Unit;
//}

void AWildTileBase::SetTileState(ETileState NextState)
{
	switch (NextState)
	{
	case ETileState::None:
		K2_SetNone();
		break;
	case ETileState::Moveable:
		K2_SetMoveable();
		break;
	case ETileState::Spawnable:
		K2_SetSpawnable();
		break;
	}


	CurrentState = NextState;
}


