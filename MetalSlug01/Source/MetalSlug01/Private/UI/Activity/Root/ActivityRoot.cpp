// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Activity/Root/ActivityRoot.h"
#include "UI/Activity/Controller/ActivityController.h"
#include "UI/Activity/Root/ActivityMenuItem.h"
#include "Components/VerticalBox.h"


void UActivityRoot::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	// 创建 Controller
	Controller = NewObject<UActivityController>(this);
	Controller->Init(ActivityConfigTable, RightContent);

	// 构建左侧菜单
	BuildLeftMenu();
}

void UActivityRoot::BuildLeftMenu()
{
	TArray<FActivityConfig*> Rows;
	ActivityConfigTable->GetAllRows(TEXT("ActivityRoot"), Rows);

	// 排序
	Rows.Sort([](const FActivityConfig& A, const FActivityConfig& B)
	{
		return A.SortOrder < B.SortOrder;
	});

	for (FActivityConfig* Row : Rows)
	{
		UActivityMenuItem* Item =
			CreateWidget<UActivityMenuItem>(
				GetWorld(),
				UActivityMenuItem::StaticClass()
			);

		Item->PageId = Row->PageId;

		// 绑定点击事件
		Item->OnClicked.AddDynamic(
			Controller,
			&UActivityController::OnMenuClicked
		);

		LeftMenuBox->AddChild(Item);
	}
}
