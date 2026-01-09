// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Activity/Pages/DailyTask/DailyTaskPage.h"
#include "Components/ListView.h"
#include "UI/Activity/Pages/DailyTask/DailyTaskItemObject.h"

void UDailyTaskPage::OnPageShow_Implementation()
{
	Super::OnPageShow_Implementation();

	// 构造 Demo 数据
	BuildMockData();

	// 刷新列表
	RefreshList();
}

void UDailyTaskPage::BuildMockData()
{
	TaskDataList.Empty();

	// 任务 1
	FDailyTaskData Task1;
	Task1.TaskId = 1;
	Task1.Title = FText::FromString(TEXT("完成 1 次对局"));
	Task1.CurrentValue = 1;
	Task1.TargetValue = 1;
	Task1.bCompleted = true;
	Task1.bRewardClaimed = false;

	// 任务 2
	FDailyTaskData Task2;
	Task2.TaskId = 2;
	Task2.Title = FText::FromString(TEXT("累计在线 10 分钟"));
	Task2.CurrentValue = 3;
	Task2.TargetValue = 10;
	Task2.bCompleted = false;
	Task2.bRewardClaimed = false;

	TaskDataList.Add(Task1);
	TaskDataList.Add(Task2);
}

void UDailyTaskPage::RefreshList()
{
	if (!TaskListView)
	{
		return;
	}

	TaskListView->ClearListItems();

	for (const FDailyTaskData& Task : TaskDataList)
	{
		UDailyTaskItemObject* Item =
			NewObject<UDailyTaskItemObject>(this);

		Item->TaskData = Task;

		TaskListView->AddItem(Item);
	}
}
