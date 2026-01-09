// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Activity/Pages/ActivityPageBase.h"
#include "DailyTaskData.h"
#include "DailyTaskPage.generated.h"

class UListView;

/**
 * 每日任务页面
 * 负责数据和列表刷新
 */
UCLASS()
class METALSLUG01_API UDailyTaskPage : public UActivityPageBase
{
	GENERATED_BODY()

public:

	/** 页面显示时刷新数据 */
	virtual void OnPageShow_Implementation() override;

protected:

	/** 任务列表 */
	UPROPERTY(meta = (BindWidget))
	UListView* TaskListView;

private:

	/** 当前任务数据 */
	UPROPERTY()
	TArray<FDailyTaskData> TaskDataList;

	/** 构造假数据（Demo 用） */
	void BuildMockData();

	/** 刷新列表 */
	void RefreshList();
};
