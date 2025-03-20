// Fill out your copyright notice in the Description page of Project Settings.


#include "WildTurnManager.h"

UWildTurnManager* UWildTurnManager::Instance = nullptr;

UWildTurnManager* UWildTurnManager::GetInstance()
{
  if (!Instance)
  {
    Instance = NewObject<UWildTurnManager>();
  }
  return Instance;
}
