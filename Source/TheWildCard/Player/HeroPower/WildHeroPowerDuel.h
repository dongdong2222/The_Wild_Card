// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TheWildCard/Player/HeroPower/IHeroPower.h"
#include "WildHeroPowerDuel.generated.h"

/**
 * 
 */
UCLASS()
class THEWILDCARD_API UWildHeroPowerDuel : public UObject, public IHeroPower
{
	GENERATED_BODY()
public:
	//implement of IHeroPower
	virtual void Use() override;
	//End of IHeroPower



};
