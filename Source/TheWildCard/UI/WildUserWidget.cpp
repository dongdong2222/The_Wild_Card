// Fill out your copyright notice in the Description page of Project Settings.


#include "WildUserWidget.h"

void UWildUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}