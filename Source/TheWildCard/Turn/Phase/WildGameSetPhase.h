// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TheWildCard/Turn/WildTurnState.h"
#include "WildGameSetPhase.generated.h"


/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class THEWILDCARD_API UWildGameSetPhase : public UObject, public IWildTurnState
{
	GENERATED_BODY()
public:
	//implement of IWildTurnState
	virtual void InitPhase(AWildGameState* GameState) override;
	virtual void StartPhase() override;
	virtual void EndPhase() override;
	//End of IWildTurnState


	UFUNCTION(BlueprintImplementableEvent)
	void K2_StartPhase();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Widget")
	TSubclassOf<UUserWidget> GameSetWidgetClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widget")
	UUserWidget* GameSetWidget;

private:
	AWildGameState* GameState;


};
