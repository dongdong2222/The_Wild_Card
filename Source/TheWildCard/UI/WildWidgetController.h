// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WildWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDrawDelegate, FName, CardName);


class UWildDeckManager;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class THEWILDCARD_API UWildWidgetController : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams();
	virtual void BroadcastInitialValues();
	virtual void BindCallbackToDependencies();

public:
	UPROPERTY(BlueprintAssignable, Category="WidgetController")
	FDrawDelegate DrawDelegate;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UWildDeckManager> DeckManager;

	//UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	//TObjectPtr<APlayerController> PlayerController;

	//UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	//TObjectPtr<APlayerState> PlayerState;

};
