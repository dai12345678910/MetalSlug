// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Activity/Root/ActivityMenuItem.h"
#include "Components/Button.h"

void UActivityMenuItem::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ClickButton)
	{
		ClickButton->OnClicked.AddDynamic(
			this,
			&UActivityMenuItem::HandleClicked
		);
	}
}

void UActivityMenuItem::HandleClicked()
{
	// 只负责广播，不知道 Controller
	OnClicked.Broadcast(PageId);
}
