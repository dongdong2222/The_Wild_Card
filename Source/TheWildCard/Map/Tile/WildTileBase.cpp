// Fill out your copyright notice in the Description page of Project Settings.


#include "WildTileBase.h"

// Sets default values
AWildTileBase::AWildTileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWildTileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWildTileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

